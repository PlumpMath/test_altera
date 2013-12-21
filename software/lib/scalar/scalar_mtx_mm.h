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

#ifndef __SCALAR_MTX_MM_H
#define __SCALAR_MTX_MM_H
#include <stdint.h>

void scalar_mtx_mm_byte( int8_t *out, int8_t *in1, int8_t *in2, const int32_t N );

void scalar_mtx_mm_half( int16_t *out, int16_t *in1, int16_t *in2, const int32_t N );

void scalar_mtx_mm_word( int32_t *out, int32_t *in1, int32_t *in2, const int32_t N );

void scalar_mtx_mm_ubyte( uint8_t *out, uint8_t *in1, uint8_t *in2, const int32_t N );

void scalar_mtx_mm_uhalf( uint16_t *out, uint16_t *in1, uint16_t *in2, const int32_t N );

void scalar_mtx_mm_uword( uint32_t *out, uint32_t *in1, uint32_t *in2, const int32_t N );

/* 
 * experimental 
 */
void scalar_ijk_mm_word( int32_t *out, int32_t *in1, int32_t *in2, const int32_t N );

void scalar_kij_mm_word( int32_t *out, int32_t *in1, int32_t *in2, const int32_t N );

void scalar_block_ijk_mm_word( int32_t *out, int32_t *in1, int32_t *in2, const int32_t N, const int32_t BS );

void scalar_block_kij_mm_word( int32_t *out, int32_t *in1, int32_t *in2, const int32_t N, const int32_t BS );

void scalar_block_kijkij_mm_word( int32_t *out, int32_t *in1, int32_t *in2, const int32_t N, const int32_t BS );

void scalar_transpose_matrix_word( int32_t *out, int32_t *in, const int32_t N );

#endif // __SCALAR_MTX_MM_H
