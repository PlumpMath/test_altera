/* VECTORBLOX MXP SOFTWARE DEVELOPMENT KIT
 * 
 * Copyright (C) 2012-2013 VectorBlox Computing Inc., Vancouver, British Columbia, Canada.
 * All rights reserved.
 * 
 * THIS BETA VERSION SOFTWARE IS PROVIDED ONLY TO PARTIES BOUND UNDER A SIGNED
 * NON-DISCLOSURE AGREEMENT. THIS SOFTWARE IS FOR THE PURPOSES OF EVALUATION ONLY.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, OF THIS BETA VERSION SOFTWARE IS STRICTLY PROHIBITED.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL VECTORBLOX COMPUTING INC. BE LIABLE FOR ANY
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
VBXCOPYRIGHT( scalar_ball_detect )

#include "demo.h"
#include "ball_detect.h"

void scalar_yuv_fast( pixel *in, pixel *out, uint8_t* py ,uint8_t* pu, uint8_t* pv, int height, int width, feat_kalman *kal0, feat_kalman *kal1)
{
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

	int y,x,r,g,b,u,v;
	unsigned int num = 0; 
	unsigned int total = 0;
	unsigned int rtotal = 0;

#if TRACK_TWO
	unsigned int num2 = 0; 
	unsigned int total2 = 0;
	unsigned int rtotal2 = 0;

#endif
	for(y=0; y<height; y++){
		for(x=0; x<width; x++){
			r = in[y*width+x].r;
			g = in[y*width+x].g;
			b = in[y*width+x].b;
			u = (((-38*r -74*g +112*b) + 127) >> 8) + 128;
			v = (((112*r -94*g  -18*b) + 127) >> 8) + 128;

			if( (u > (u0-thresh)) && (u < (u0+thresh)) && (v > (v0-thresh)) && (v < (v0+thresh)) ){
				num++;
				rtotal +=y;
				total +=x;
			} 
#if TRACK_TWO
			if( (u > (u1-thresh)) && (u < (u1+thresh)) && (v > (v1-thresh)) && (v < (v1+thresh)) ){
				num2++;
				rtotal2 +=y;
				total2 +=x;
			} 
#endif
		}
	}

	int my_x, my_y, rad;
	pixel a;
	if( num > MIN_PIXELS ){
		kal0->active = 1;
		a.r = 0;
		a.g = 255;
		a.b = 0;
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
		a.r = 0;
		a.g = 0;
		a.b = 255;
		a.a = 0;

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
}

void draw_outline(pixel* buffer, feat_kalman *k, pixel* col)
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

		draw_square( my_x-rad,   my_y-rad ,   2*rad, 2*rad, &a, buffer);
		draw_square( my_x-rad+1, my_y-rad+1 , 2*rad, 2*rad, &a, buffer);
		draw_square( my_x-rad-1, my_y-rad-1 , 2*rad, 2*rad, &a, buffer);

	}
}

int scalar_ball_detect(pixel *input, pixel *output, feat_kalman *kal0, feat_kalman *kal1, pixel *color0, pixel* color1, int draw_ball)
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

	uint8_t *py = (uint8_t *)malloc( height*width * sizeof(uint8_t));
	uint8_t *pu = (uint8_t *)malloc( height*width * sizeof(uint8_t));
	uint8_t *pv = (uint8_t *)malloc( height*width * sizeof(uint8_t));

	scalar_yuv_fast( input, output, py, pu, pv, height, width, kal0, kal1);

	if(draw_ball){
		draw_outline(input, kal0, &_color0);
		draw_outline(input, kal1, &_color1);
	}

	free(py);
	free(pu);
	free(pv);

	return 0;
}

int ball_calibrate(pixel *input, pixel *output, int player, pixel *color)
{
	int i,j;
	int width = IMAGE_WIDTH;
	int offset_y = IMAGE_HEIGHT/2 -20/2;
	int offset_x = IMAGE_WIDTH/2 -20/2;
	int my_r = 0; 
	int my_b = 0;
	int my_g = 0;

	for(j=0;j<20;j++){
		for(i=0;i<20;i++){
			my_r += input[ (j+offset_y)*width + (i+offset_x)].r;
			my_g += input[ (j+offset_y)*width + (i+offset_x)].g;
			my_b += input[ (j+offset_y)*width + (i+offset_x)].b;
		}
	}
	my_r = my_r / 20 / 20;
	my_g = my_g / 20 / 20;
	my_b = my_b / 20 / 20;

	if(player){
		printf("set 1 to r,g,b %d,%d,%d\n", my_r, my_g, my_b);
		_color1.r = my_r;
		_color1.g = my_g;
		_color1.b = my_b;
	}else{
		printf("set 0 to r,g,b %d,%d,%d\n", my_r, my_g, my_b);
		_color0.r = my_r;
		_color0.g = my_g;
		_color0.b = my_b;
	}

	color->r = my_r;
	color->g = my_g;
	color->b = my_b;

	offset_y = IMAGE_HEIGHT/2 -40/2;
	offset_x = IMAGE_WIDTH/2 -40/2;
	pixel a;

	a.r = 255-color->r;
	a.g = 255-color->g;
	a.b = 255-color->b;
	a.a = 0;
	draw_square( offset_x, offset_y , 40, 40, &a, input);
	draw_square( offset_x-1, offset_y-1 , 40, 40, &a, input);
	draw_square( offset_x+1, offset_y+1 , 40, 40, &a, input);

	offset_x = IMAGE_WIDTH-1-80;

	return 0;
}

