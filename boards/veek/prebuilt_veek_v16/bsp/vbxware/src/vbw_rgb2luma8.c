/**@file*/
// VBXCOPYRIGHTTAG
#include "vbx_copyright.h"
VBXCOPYRIGHT(vbw_rgb2luma8)

#include "vbx.h"

/** Converts RGB frame to 8-bit luma.
 * @usage Convert RGB frame to 8-bit luma using Bt.601 coefficients.
 *
 * @param[in] rgb          32-bit aRGB pixel input
 * @param[out] luma         8-bit luma pixel output
 * @param[in] image_width  input/output image width
 * @param[in] image_height input/output image height
 * @param[in] image_pitch  input/output image pitch
 *
 * @retval 0 if successful; -1 if out of scratchpad memory
 */
int vbw_rgb2luma8(unsigned char *luma, unsigned *rgb, const short image_width, const short image_height, const short image_pitch)
{
	vbx_uword_t *v_row_in, *v_row_in_next, *tmp_ptr;
	vbx_ubyte_t *v_row_out;
	vbx_uhalf_t *v_luma, *v_temp;
	int          i;

	vbx_set_vl(image_width);

	// Allocate scratchpad memory for vectors
	if ((v_row_in      = (vbx_uword_t *)vbx_sp_malloc(image_width*sizeof(vbx_uword_t))) == NULL
			||  (v_row_in_next = (vbx_uword_t *)vbx_sp_malloc(image_width*sizeof(vbx_uword_t))) == NULL
			||  (v_luma        = (vbx_uhalf_t *)vbx_sp_malloc(image_width*sizeof(vbx_uhalf_t))) == NULL
			||  (v_temp        = (vbx_uhalf_t *)vbx_sp_malloc(image_width*sizeof(vbx_uhalf_t))) == NULL
			||  (v_row_out     = (vbx_ubyte_t *)vbx_sp_malloc(image_width*sizeof(vbx_ubyte_t))) == NULL) {
		printf("Out of scratchpad memory\n");
		return -1;
	}

	// Transfer the first input row to scratchpad
	vbx_dma_to_vector_aligned(v_row_in, rgb, image_width*sizeof(vbx_uword_t));

	// Convert rows of RGB to luma
	for (i = 0; i < image_height; i++) {
		// Transfer the next input row to scratchpad while processing
		if ((i+1) < image_height)
			vbx_dma_to_vector_aligned(v_row_in_next, rgb + (i+1)*image_pitch, image_width*sizeof(vbx_uword_t));

		// Move weighted B into v_luma
		vbx(SVWHU, VAND, v_temp,   0xFF, v_row_in);
		vbx(SVHU,  VMUL, v_luma,     25, v_temp);

		// Move weighted G into v_temp and add it to v_luma
        vbx(SVWHU, VAND, v_temp,   0xFF, (vbx_uword_t*)(((vbx_ubyte_t *)v_row_in)+1));
		vbx(SVHU,  VMUL, v_temp,    129, v_temp);
		vbx(VVHU,  VADD, v_luma, v_luma, v_temp);

		// Move weighted R into v_temp and add it to v_luma
        vbx(SVWHU, VAND, v_temp,   0xFF, (vbx_uword_t*)(((vbx_ubyte_t *)v_row_in)+2));
		vbx(SVHU,  VMUL, v_temp,     66, v_temp);
		vbx(VVHU,  VADD, v_luma, v_luma, v_temp);

		// Round and normalize
		vbx(SVHU,  VADD, v_luma,  128, v_luma);
		vbx(SVHBU, VSHR, v_row_out, 8, v_luma);

		// Transfer from scratchpad memory to output
		vbx_dma_to_host_aligned(luma + i*image_pitch, v_row_out, image_width*sizeof(vbx_ubyte_t));

		// Swap scratchpad input buffer pointers
		tmp_ptr       = v_row_in;
		v_row_in      = v_row_in_next;
		v_row_in_next = tmp_ptr;
	}

	vbx_sync();
	vbx_sp_free();
	return 0;
}
