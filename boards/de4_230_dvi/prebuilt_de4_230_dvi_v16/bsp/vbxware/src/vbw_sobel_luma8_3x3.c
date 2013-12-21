/**@file*/
// VBXCOPYRIGHTTAG
#include "vbx_copyright.h"
VBXCOPYRIGHT(vbw_sobel_luma8_3x3)

#include "vbx.h"
#include "vbw_mtx_sobel.h"


/// Apply [1 2 1] low-pass filter to raw input row
/// NB: Last two output pixels are not meaningful
inline static void vbw_sobel_3x3_row(vbx_uhalf_t *lpf, vbx_ubyte_t *raw, const short image_width)
{
	vbx_set_vl(image_width-1);
	vbx(VVBHU, VADD, lpf, raw, raw+1);
	vbx_set_vl(image_width-2);
	vbx(VVHU, VADD, lpf, lpf, lpf+1);
}


/** Luma Edge Detection.
 *
 * @usage 3x3 Sobel edge detection with 8-bit luma image
 *
 * @param[in] input        8-bit luma input
 * @param[out] output      32-bit aRGB edge-intensity output
 * @param[in] image_width  input/output image width
 * @param[in] image_height input/output image height
 * @param[in] image_pitch  input/output image pitch
 *
 * @retval 0 if successful; -1 if out of scratchpad memory
 */
int vbw_sobel_luma8_3x3(unsigned *output, unsigned char *input, const short image_width, const short image_height, const short image_pitch, const short renorm)
{
	int y;

	vbx_ubyte_t *v_luma_top, *v_luma_mid, *v_luma_bot, *v_luma_nxt;
	vbx_uword_t *v_row_out;

	vbx_uhalf_t *v_sobel_row_top, *v_sobel_row_mid, *v_sobel_row_bot;
	vbx_uhalf_t *v_gradient_x, *v_gradient_y;
	vbx_uhalf_t *v_tmp;

	void *tmp_ptr;

	// Allocate space in scratchpad for vectors
	if ((v_luma_top      = (vbx_ubyte_t *)vbx_sp_malloc(image_width*sizeof(vbx_ubyte_t))) == NULL
			||  (v_luma_mid      = (vbx_ubyte_t *)vbx_sp_malloc(image_width*sizeof(vbx_ubyte_t))) == NULL
			||  (v_luma_bot      = (vbx_ubyte_t *)vbx_sp_malloc(image_width*sizeof(vbx_ubyte_t))) == NULL
			||  (v_luma_nxt      = (vbx_ubyte_t *)vbx_sp_malloc(image_width*sizeof(vbx_ubyte_t))) == NULL
			||  (v_sobel_row_top = (vbx_uhalf_t *)vbx_sp_malloc(image_width*sizeof(vbx_uhalf_t))) == NULL
			||  (v_sobel_row_mid = (vbx_uhalf_t *)vbx_sp_malloc(image_width*sizeof(vbx_uhalf_t))) == NULL
			||  (v_sobel_row_bot = (vbx_uhalf_t *)vbx_sp_malloc(image_width*sizeof(vbx_uhalf_t))) == NULL
			||  (v_gradient_x    = (vbx_uhalf_t *)vbx_sp_malloc(image_width*sizeof(vbx_uhalf_t))) == NULL
			||  (v_gradient_y    = (vbx_uhalf_t *)vbx_sp_malloc(image_width*sizeof(vbx_uhalf_t))) == NULL
			||  (v_row_out       = (vbx_uword_t *)vbx_sp_malloc(image_width*sizeof(vbx_uword_t))) == NULL) {
		printf("Out of scratchpad memory\n");
		return -1;
	}

	// Transfer the first 3 input rows and interleave first 2 sobel row calculations
	vbx_dma_to_vector_aligned(v_luma_top, input,                 image_width*sizeof(vbx_ubyte_t));
	vbx_dma_to_vector_aligned(v_luma_mid, input +   image_pitch, image_width*sizeof(vbx_ubyte_t));
	vbw_sobel_3x3_row(v_sobel_row_top, v_luma_top, image_width);
	vbx_dma_to_vector_aligned(v_luma_bot, input + 2*image_pitch, image_width*sizeof(vbx_ubyte_t));
	vbw_sobel_3x3_row(v_sobel_row_mid, v_luma_mid, image_width);

	// Set top output row to 0
	vbx_set_vl(image_width);
	vbx(SVWU, VMOV, v_row_out, 0, 0);
	vbx_dma_to_host_aligned(output, v_row_out, image_width*sizeof(vbx_uword_t));

	// Calculate edges
	for (y = 0; y < image_height-(FILTER_HEIGHT-1); y++) {
		// Transfer the next input row while processing
		vbx_dma_to_vector_aligned(v_luma_nxt, input + (y+FILTER_HEIGHT)*image_pitch, image_width*sizeof(vbx_ubyte_t));

		// Start calculating gradient_x
		vbx_set_vl(image_width);
		vbx(SVBHU, VSHL, v_gradient_x, 1, v_luma_mid); // multiply by 2

		// Calculate gradient_y
		// Apply [1 2 1] matrix to last row in window and calculate absolute difference with pre-computed first row
		vbw_sobel_3x3_row(v_sobel_row_bot, v_luma_bot, image_width);
		vbx(VVH, VABSDIFF, (vbx_half_t*)v_gradient_y, (vbx_half_t*)v_sobel_row_top, (vbx_half_t*)v_sobel_row_bot);

		// Re-use v_sobel_row_top
		v_tmp = v_sobel_row_top;

		// Finish calculating gradient_x
		// Apply [1 2 1]T matrix to all columns
		vbx_set_vl(image_width);
		vbx(VVBHU, VADD, v_tmp, v_luma_top, v_luma_bot);
		vbx(VVHU,  VADD, v_tmp, v_tmp,      v_gradient_x);
		// For each column, calculate absolute difference with 2nd column to the right
		vbx_set_vl(image_width-2);
		vbx(VVH, VABSDIFF, (vbx_half_t*)v_gradient_x, (vbx_half_t*)v_tmp, (vbx_half_t*)v_tmp+2);

		// sum of absoute gradients
		vbx_set_vl(image_width-2);
		vbx(VVHU, VADD, v_tmp, v_gradient_x,  v_gradient_y);
		vbx(SVHU, VSHR, v_tmp, renorm, v_tmp);

		// Threshold
		vbx(SVHU, VSUB,     v_gradient_y, 255, v_tmp);
		vbx(SVHU, VCMV_LTZ, v_tmp,        255, v_gradient_y);

		// Copy the result to the low byte of the output row
		// Trick to copy the low byte (b) to the middle two bytes as well
		// Note that first and last columns are 0
		vbx_set_vl(image_width-2);
		vbx(SVHWU, VMULLO, v_row_out+1, 0x00010101, v_tmp);

		// DMA the result to the output
		vbx_dma_to_host_aligned(output+(y+1)*image_pitch, v_row_out, image_width*sizeof(vbx_uword_t));

		// Rotate input row buffers
		tmp_ptr      = (void *)v_luma_top;
		v_luma_top   = v_luma_mid;
		v_luma_mid   = v_luma_bot;
		v_luma_bot   = v_luma_nxt;
		v_luma_nxt   = (vbx_ubyte_t *)tmp_ptr;

		// Rotate v_sobel_row buffers (for gradient_y)
		tmp_ptr         = (void *)v_sobel_row_top;
		v_sobel_row_top = v_sobel_row_mid;
		v_sobel_row_mid = v_sobel_row_bot;
		v_sobel_row_bot = (vbx_uhalf_t *)tmp_ptr;
	}

	// Set bottom row to 0
	vbx_set_vl(image_width);
	vbx(SVWU, VMOV, v_row_out, 0, 0);
	vbx_dma_to_host_aligned(output+(image_height-1)*image_pitch, v_row_out, image_width*sizeof(vbx_uword_t));

	vbx_sync();
	vbx_sp_free();

	return 0;
}