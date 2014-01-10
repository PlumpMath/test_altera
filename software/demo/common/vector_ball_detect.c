/* VECTORBLOX MXP SOFTWARE DEVELOPMENT KIT
 *
 * Copyright (C) 2012-2014 VectorBlox Computing Inc., Vancouver, British Columbia, Canada.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 *     * Neither the name of VectorBlox Computing Inc. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * This agreement shall be governed in all respects by the laws of the Province
 * of British Columbia and by the laws of Canada.
 *
 * This file is part of the VectorBlox MXP Software Development Kit.
 *
 */


#include "vbx_copyright.h"
VBXCOPYRIGHT( vector_ball_detect )

#include "demo.h"
#include "ball_detect.h"

	pixel _color0;
	pixel _color1;

void vector_uv_row(vptr_uword v_pixel, vptr_uhalf v_temp0, vptr_half v_temp1, vbx_byte_t* v_u, vbx_byte_t* v_v, int width)
{
	vbx_set_vl(width);

#if 0
	//Move the b component into v_y
	vbx(SVWHU, VAND, v_temp0, 0xFF,   v_pixel);
	vbx(SVHU,  VMUL, v_temp1, 25,     v_temp0);

	//Move g into v_temp and add it to v_y
	vbx(SVWHU, VAND, v_temp0, 0xFF,   ((vptr_ubyte)v_pixel)+1);
	vbx(SVHU,  VMUL, v_temp0, 129,    v_temp0);
	vbx(VVHU,  VADD, v_temp1, v_temp1, v_temp0);

	//Move r into v_temp0 and add it to v_y
	vbx(SVWHU, VAND, v_temp0, 0xFF,   ((vptr_ubyte)v_pixel)+2);
	vbx(SVHU,  VMUL, v_temp0, 66,     v_temp0);
	vbx(VVHU,  VADD, v_temp1, v_temp1, v_temp0);

	vbx(SVHU,  VADD, v_temp1, 127,    v_temp1); // for rounding
	vbx(SVHU,  VSHR, v_temp1, 8,      v_temp1);
	vbx(VVHBU,  VMOV, v_y, v_temp1,      0);
	vbx(SVB,  VADD, v_y, 16,  v_y);
#endif

	//Move the b component into v_u
	vbx(SVWHU, VAND, v_temp0, 0xFF,   v_pixel);
	vbx(SVH,  VMUL, v_temp1, 112, (vbx_half_t *)v_temp0);

	//Move g into v_temp and add it to v_u
	vbx(SVWHU, VAND, v_temp0, 0xFF,   (vbx_uword_t *)(((vptr_ubyte)v_pixel)+1));
	vbx(SVH,  VMUL, (vbx_half_t *)v_temp0, -74, (vbx_half_t *)v_temp0);
	vbx(VVH,  VADD, v_temp1, v_temp1, (vbx_half_t *)v_temp0);

	//Move r into v_temp0 and add it to v_u
	vbx(SVWHU, VAND, v_temp0, 0xFF,   (vbx_uword_t *)(((vptr_ubyte)v_pixel)+2));
	vbx(SVH,  VMUL, (vbx_half_t *)v_temp0, -38, (vbx_half_t *)v_temp0);
	vbx(VVH,  VADD, v_temp1, v_temp1, (vbx_half_t *)v_temp0);

	vbx(SVH,  VADD, v_temp1, 127,    v_temp1); // for rounding
	vbx(SVH,  VSHR, v_temp1, 8,      v_temp1);
	vbx(VVHB,  VMOV, v_u, v_temp1,      0);
	vbx(SVBU,  VADD, (vbx_ubyte_t*)v_u, 128,  (vbx_ubyte_t*)v_u);

	//Move the b component into v_v
	vbx(SVWHU, VAND, v_temp0, 0xFF,   v_pixel);
	vbx(SVH,  VMUL, v_temp1, -18,     (vbx_half_t *)v_temp0);

	//Move g into v_temp and add it to v_v
	vbx(SVWHU, VAND, v_temp0, 0xFF,  (vbx_uword_t *)(((vptr_ubyte)v_pixel)+1));
	vbx(SVH,  VMUL, (vbx_half_t *)v_temp0, -94,    (vbx_half_t *)v_temp0);
	vbx(VVH,  VADD, v_temp1, v_temp1, (vbx_half_t *)v_temp0);

	//Move r into v_temp0 and add it to v_v
	vbx(SVWHU, VAND, v_temp0, 0xFF,   (vbx_uword_t *)(((vptr_ubyte)v_pixel)+2));
	vbx(SVH,  VMUL, (vbx_half_t *)v_temp0, 112,     (vbx_half_t *)v_temp0);
	vbx(VVH,  VADD, v_temp1, v_temp1, (vbx_half_t *)v_temp0);

	vbx(SVH,  VADD, v_temp1, 127,    v_temp1); // for rounding
	vbx(SVH,  VSHR, v_temp1, 8,      v_temp1);
	vbx(VVHB,  VMOV, v_v, v_temp1,      0);
	vbx(SVBU,  VADD, (vbx_ubyte_t*)v_v, 128,  (vbx_ubyte_t*)v_v);

}

void vector_thresh_row(vbx_byte_t *v_bin, vbx_byte_t *v_u, vbx_byte_t *v_v, vbx_byte_t *v_high, vbx_byte_t *v_low, vbx_byte_t *v_temp, int width, int u, int v, int thresh)
{
	vbx_set_vl(width);
	vbx(SVB, VMOV, v_bin,  255,    0); //all are 'on'

	vbx(SVB, VMOV, v_temp, 255,    0); //all are 'on'
	vbx(SVB, VSUB, v_high, u+thresh,  v_u); //color+value = max - actual; if actual > max will be negative
	vbx(SVB, VCMV_LTZ, v_temp, 0,  v_high);
	vbx(SVB, VSUB, v_low, u-thresh,  v_u); //color-value = min - actual; if actual < min will be positive
	vbx(SVB, VCMV_GTZ, v_temp, 0,  v_low);

	vbx(VVB, VAND, v_bin, v_bin, v_temp);

	vbx(SVB, VMOV, v_temp, 255,    0);
	vbx(SVB, VSUB, v_high, v+thresh,  v_v);
	vbx(SVB, VCMV_LTZ, v_temp, 0,  v_high);
	vbx(SVB, VSUB, v_low, v-thresh,  v_v);
	vbx(SVB, VCMV_GTZ, v_temp, 0,  v_low);

	vbx(VVB, VAND, v_bin, v_bin, v_temp);
}

void vector_accum(vptr_uword v_acc, vptr_uword v_num, vptr_ubyte v_row, vptr_uword v_temp0, vptr_uword v_temp1, int width)
{
	vbx_set_vl(width-2);//for edges

	vbx(VVBW, VMOV, (vbx_word_t*)v_temp0, (vbx_byte_t*)v_row, 0);
	vbx(SVW, VSUB, (vbx_word_t*)v_temp1, 0, (vbx_word_t*)v_temp0);
	vbx(SVW, VCMV_LTZ, (vbx_word_t*)v_temp1, 1, (vbx_word_t*)v_temp1);
	vbx_acc(VVWU, VMOV, v_num, v_temp1, 0);
	vbx_acc(VEWU, VMUL, v_acc, v_temp1, 0);
}

void vector_uv( pixel *in, pixel *out, int height, int width, feat_kalman *kal0, feat_kalman *kal1)
{
	vbx_sp_push();
	vptr_uword v_pix0 = (vptr_uword)vbx_sp_malloc(width*sizeof(vbx_uword_t));
	vptr_uword v_pix1 = (vptr_uword)vbx_sp_malloc(width*sizeof(vbx_uword_t));

	vptr_uword v_tempi = (vptr_uword)vbx_sp_malloc(width*sizeof(vbx_uword_t));
	vptr_uword v_tempii = (vptr_uword)vbx_sp_malloc(width*sizeof(vbx_uword_t));

	vptr_uhalf v_temp0   = (vptr_uhalf)v_tempi;
	vptr_half v_temp1   = (vptr_half)v_temp0 + width;

	vbx_byte_t *v_u   = (vbx_byte_t *)vbx_sp_malloc(width*sizeof(vbx_byte_t));
	vbx_byte_t *v_v   = (vbx_byte_t *)vbx_sp_malloc(width*sizeof(vbx_byte_t));

	vptr_ubyte v_bin0 = (vptr_ubyte)vbx_sp_malloc(width*sizeof(vbx_ubyte_t));
	vptr_ubyte v_bin1 = (vptr_ubyte)vbx_sp_malloc(width*sizeof(vbx_ubyte_t));

	vptr_uword v_acc = (vptr_uword)vbx_sp_malloc((height-2)*sizeof(vbx_uword_t));
	vptr_uword v_num = (vptr_uword)vbx_sp_malloc((height-2)*sizeof(vbx_uword_t));

	vptr_uword v_total = (vptr_uword)vbx_sp_malloc(3*sizeof(vbx_uword_t));

	vbx_byte_t *v_tempA  = (vbx_byte_t *) v_temp0;
	vbx_byte_t *v_tempB = (vbx_byte_t *) v_temp1;
	vbx_byte_t *v_tempC = v_tempB + width;

	vptr_ubyte v_final = v_bin0;
#if TRACK_TWO
	vptr_ubyte v_2final = v_bin1;

	vptr_uword v_2acc = (vptr_uword)vbx_sp_malloc((height-2)*sizeof(vbx_uword_t));
	vptr_uword v_2num = (vptr_uword)vbx_sp_malloc((height-2)*sizeof(vbx_uword_t));
	vptr_uword v_2total = (vptr_uword)vbx_sp_malloc(3*sizeof(vbx_uword_t));
#endif

	vptr_uword v_pixel[2]; 
	v_pixel[0] = v_pix0;
	v_pixel[1] = v_pix1;

	vptr_ubyte v_bin[2]; 
	v_bin[0] = v_bin0;
	v_bin[1] = v_bin1;

	int buf=1;

	int r0 = _color0.r;
	int g0 = _color0.g;
	int b0 = _color0.b;

	int r1 = _color1.r;
	int g1 = _color1.g;
	int b1 = _color1.b;

	int u0 = (((-38*r0 -74*g0 +112*b0) + 127) >> 8) + 128;
	int v0 = (((112*r0 -94*g0  -18*b0) + 127) >> 8) + 128;

	int u1 = (((-38*r1 -74*g1 +112*b1) + 127) >> 8) + 128;
	int v1 = (((112*r1 -94*g1  -18*b1) + 127) >> 8) + 128;

	int thresh = THRESHOLD;

	//init
	vbx_set_vl(width);
	vbx( VVBU, VMOV, v_final, 0, 0 );
	vbx( VVWU, VMOV, v_acc, 0, 0 );
	vbx( VVWU, VMOV, v_num, 0, 0 );

#if TRACK_TWO
	vbx( VVBU, VMOV, v_2final, 0, 0 );
	vbx( VVWU, VMOV, v_2acc, 0, 0 );
	vbx( VVWU, VMOV, v_2num, 0, 0 );
#endif

	vbx_dma_to_vector(    v_pixel[!buf], in +0*width, width*sizeof(vbx_uword_t));
	buf=!buf;

	vbx_dma_to_vector(    v_pixel[!buf], in +1*width, width*sizeof(vbx_uword_t));
	vector_uv_row(       v_pixel[buf], v_temp0, v_temp1,  v_u, v_v, width);
	vector_thresh_row( (vbx_byte_t*)v_bin[0], v_u, v_v, v_tempA, v_tempB, v_tempC, width, u0, v0, thresh);
#if TRACK_TWO
	vector_thresh_row( (vbx_byte_t*)v_bin[1], v_u, v_v, v_tempA, v_tempB, v_tempC, width, u1, v1, thresh);
#endif
	buf=!buf;

	vbx_dma_to_vector(    v_pixel[!buf], in +2*width, width*sizeof(vbx_uword_t));
	vector_uv_row(       v_pixel[buf], v_temp0, v_temp1,  v_u, v_v, width);
	vector_thresh_row( (vbx_byte_t*)v_bin[0], v_u, v_v, v_tempA, v_tempB, v_tempC, width, u0, v0, thresh);
#if TRACK_TWO
	vector_thresh_row( (vbx_byte_t*)v_bin[1], v_u, v_v, v_tempA, v_tempB, v_tempC, width, u1, v1, thresh);
	buf=!buf;
#endif

	int y;
	for(y=3; y<height; y++){
		vbx_dma_to_vector(    v_pixel[!buf], in +y*width, width*sizeof(vbx_uword_t));
		vector_uv_row(       v_pixel[buf], v_temp0, v_temp1,  v_u, v_v, width);
		vector_thresh_row( (vbx_byte_t*)v_bin[0], v_u, v_v, v_tempA, v_tempB, v_tempC, width, u0, v0, thresh);
#if TRACK_TWO
		vector_thresh_row( (vbx_byte_t*)v_bin[1], v_u, v_v, v_tempA, v_tempB, v_tempC, width, u1, v1, thresh);
#endif
		vector_accum( v_acc +y-3, v_num +y-3, v_final+1, v_tempi, v_tempii, width);
#if TRACK_TWO
		vector_accum( v_2acc +y-3, v_2num +y-3, v_2final+1, v_tempi, v_tempii, width);
#endif

		buf=!buf;
	}

	//final
	vector_uv_row(       v_pixel[buf], v_temp0, v_temp1,  v_u, v_v, width);
	vector_thresh_row( (vbx_byte_t*)v_bin[0], v_u, v_v, v_tempA, v_tempB, v_tempC, width, u0, v0, thresh);
#if TRACK_TWO
	vector_thresh_row( (vbx_byte_t*)v_bin[1], v_u, v_v, v_tempA, v_tempB, v_tempC, width, u1, v1, thresh);
#endif
	vector_accum( v_acc +height-3, v_num +height-3, v_final+1, v_tempi, v_tempii, width);
#if TRACK_TWO
	vector_accum( v_2acc +height-3, v_2num +height-3, v_2final+1, v_tempi, v_tempii, width);
#endif


	vbx_sync();
	vbx_set_vl( height-2 );
	vbx_acc( VVWU, VMOV, v_total+0, v_num, 0);
	vbx_acc( VVWU, VMOV, v_total+1, v_acc, 0);
	vbx_acc( VEWU, VMUL, v_total+2, v_num, 0);

#if TRACK_TWO
	vbx_acc( VVWU, VMOV, v_2total+0, v_2num, 0);
	vbx_acc( VVWU, VMOV, v_2total+1, v_2acc, 0);
	vbx_acc( VEWU, VMUL, v_2total+2, v_2num, 0);
#endif
	vbx_sync();
	unsigned int num = v_total[0];
	unsigned int total = v_total[1];
	unsigned int rtotal = v_total[2];

#if TRACK_TWO
	unsigned int num2 = v_2total[0];
	unsigned int total2 = v_2total[1];
	unsigned int rtotal2 = v_2total[2];

#endif
	int my_x, my_y, rad;
	pixel a;
	if( num > MIN_PIXELS ){
		kal0->active = 1;
		//printf("num == %d\n", num);

		a.r = 255-_color0.r;
		a.g = 255-_color0.g;
		a.b = 255-_color0.b;
		a.a = 0;


		my_x = total/num +1;
		my_y = rtotal/num +1;
		rad = (int)(sqrt( (float)num ));

#if 1
		feat measured;
		//feat kal;
		measured.x = my_x;
		measured.y = my_y;
		measured.w = rad;
		kalman_filter(&measured, kal0, 0);
		my_x = kal0->x;
		my_y = kal0->y;
		rad =  kal0->z;
#endif
	}else{
		kal0->active = 0;
	}

#if TRACK_TWO
	if( num2 > MIN_PIXELS ){
		kal1->active = 1;
		a.r = 255-_color1.r;
		a.g = 255-_color1.g;
		a.b = 255-_color1.b;

		my_x = total2/num2 +1;
		my_y = rtotal2/num2 +1;
		rad = (int)(sqrt( (float)num2 ));

#if 1
		feat measured;
		//feat kal;
		measured.x = my_x;
		measured.y = my_y;
		measured.w = rad;
		kalman_filter(&measured, kal1, 1);
		my_x = kal1->x;
		my_y = kal1->y;
		rad =  kal1->z;
#endif

	}else{
		kal1->active = 0;
	}
#endif

	vbx_sp_pop();
}


void vector_draw_outline(pixel* buffer, feat_kalman *k, pixel* col)
{
	if(k->active){
		pixel a;
		a.r = 255 - col->r;
		a.b = 255 - col->b;
		a.g = 255 - col->g;
		a.a = 0;
		int rad = k->z;
		int my_x = k->x;
		int my_y = k->y;
		int color = *(int *)&a;

		vbx_set_vl(2*rad);
		vbx(SVW, VMOV, 0, color, 0);

		vbx_dma_to_host( buffer+my_x-rad+IMAGE_WIDTH*(my_y-rad+1), 0, 2*rad*sizeof(int));
		vbx_dma_to_host( buffer+my_x-rad+IMAGE_WIDTH*(my_y-rad),   0, 2*rad*sizeof(int));
		vbx_dma_to_host( buffer+my_x-rad+IMAGE_WIDTH*(my_y-rad-1), 0, 2*rad*sizeof(int));

		vbx_dma_to_host( buffer+my_x-rad+IMAGE_WIDTH*(my_y+rad+1), 0, 2*rad*sizeof(int));
		vbx_dma_to_host( buffer+my_x-rad+IMAGE_WIDTH*(my_y+rad),   0, 2*rad*sizeof(int));
		vbx_dma_to_host( buffer+my_x-rad+IMAGE_WIDTH*(my_y+rad-1), 0, 2*rad*sizeof(int));

	}
}


int vector_ball_detect(pixel *input, pixel *output, feat_kalman *kal0, feat_kalman *kal1, pixel *color0, pixel* color1, int draw_ball)
{
	static int initial = 0;
	if(!initial){
		_color0.r = 210;
		_color0.g = 75;
		_color0.b = 60;

		_color1.r = 85;
		_color1.g = 140;
		_color1.b = 60;

		initial = 1;
	}

	*(unsigned int*)color0 = *((unsigned int*)(&_color0));
	*(unsigned int*)color1 = *((unsigned int*)(&_color1));

	//load_img(input, IMAGE_WIDTH, IMAGE_HEIGHT );
	int height = IMAGE_HEIGHT;
	int width = IMAGE_WIDTH;

	vector_uv( input, output, height, width, kal0, kal1);

	if( draw_ball){
		vector_draw_outline(input, kal0, &_color0);
		vector_draw_outline(input, kal1, &_color1);
	}

	return 0;
}

