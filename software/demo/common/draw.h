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


#ifndef __DRAW_H
#define __DRAW_H

#include <stdint.h>
#include "demo.h"
#include "repulse.h"

void vector_erase_screen(pixel *buffer, vbx_word_t *v_screen, const int image_width, const int image_height, const int image_pitch);

void vector_erase_screen_alpha(pixel *buffer, vbx_word_t *v_screen, const int image_width, const int image_height, const int image_pitch);

void vector_draw_point_diamond(pixel *buffer, vbx_word_t *v_screen, int x, int y, int size, const int image_pitch);

void vector_draw_point_alpha_diamond(pixel *buffer, vbx_word_t *v_screen, int x, int y, int size, const int image_pitch);

void vector_draw_point(pixel *buffer, vbx_word_t *v_screen, int x, int y, int size, const int image_pitch);

void vector_draw_point_alpha(pixel *buffer, vbx_word_t *v_screen, int x, int y, int size, const int image_pitch);

void vector_draw_screen(pixel *cbuffer, int num_particles, const int use_diamond, const int use_alpha, const int use_black, const int image_width, const int image_height, const int image_pitch);

//draw a rectangle of given size, in a given color, on the output image
void draw_rectangle(int startx, int starty, int width, int height, pixel* color, pixel *output_buffer, const int image_width, const int image_height, const int image_pitch);

//draw a given set of haar features as rectangles on the output image
void draw_features( feat* feature, pixel* color, pixel* output, const int image_width, const int image_height, const int image_pitch);

#endif //__DRAW_H
