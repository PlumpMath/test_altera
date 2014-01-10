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


#ifndef __BALL_DETECT_H
#define __BALL_DETECT_H

#include "demo.h"
#include <math.h>
//#include "adventure2.h"

typedef vbx_uhalf_t* vptr_uhalf;
typedef vbx_uword_t* vptr_uword;
typedef vbx_ubyte_t* vptr_ubyte;
typedef vbx_half_t* vptr_half;

extern pixel _color0;
extern pixel _color1;

#define THRESHOLD 8
#define MIN_PIXELS 500
#define USE_HALF 0
#define TRACK_TWO 1

void scalar_yuv_fast( pixel *in, pixel *out, uint8_t* py ,uint8_t* pu, uint8_t* pv, int height, int width, feat_kalman *kal0, feat_kalman *kal1);
void draw_outline(pixel* buffer, feat_kalman *k, pixel* col);
int scalar_ball_detect(pixel *input, pixel *output, feat_kalman *kal0, feat_kalman *kal1, pixel *color0, pixel* color1, int draw_ball);
int ball_calibrate(pixel *input, pixel *output, int player, pixel *color);

void vector_uv_row(vptr_uword v_pixel, vptr_uhalf v_temp0, vptr_half v_temp1, vbx_byte_t *v_u, vbx_byte_t *v_v, int width);
void vector_thresh_row(vbx_byte_t *v_bin, vbx_byte_t *v_u, vbx_byte_t *v_v, vbx_byte_t *v_high, vbx_byte_t *v_low, vbx_byte_t *v_temp, int width, int u, int v, int thresh);
void vector_accum(vptr_uword v_acc, vptr_uword v_num, vptr_ubyte v_row, vptr_uword v_temp0, vptr_uword v_temp1, int width);
void vector_uv( pixel *in, pixel *out, int height, int width, feat_kalman *kal0, feat_kalman *kal1);
int vector_ball_detect(pixel *input, pixel *output, feat_kalman *kal0, feat_kalman *kal1, pixel *color0, pixel* color1, int draw_ball);

#endif // __BALL_DETECT_H
