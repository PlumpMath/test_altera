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


#ifndef __VBX_VEC_FIR_ALL_H
#define __VBX_VEC_FIR_ALL_H

#include "vbx.h"

// Now, include the H file six times
// First three for byte, half, word
// Next three for ubyte, uhalf, uword

#ifdef VBX_TEMPLATE_T
#error Do not define VBX_TEMPLATE_T before including this file.
#endif

#define VBX_TEMPLATE_T VBX_BYTESIZE_DEF
#include "vbw_vec_fir_t.h"

#undef VBX_TEMPLATE_T
#define VBX_TEMPLATE_T VBX_HALFSIZE_DEF
#include "vbw_vec_fir_t.h"

#undef VBX_TEMPLATE_T
#define VBX_TEMPLATE_T VBX_WORDSIZE_DEF
#include "vbw_vec_fir_t.h"

#undef VBX_TEMPLATE_T
#define VBX_TEMPLATE_T VBX_UBYTESIZE_DEF
#include "vbw_vec_fir_t.h"

#undef VBX_TEMPLATE_T
#define VBX_TEMPLATE_T VBX_UHALFSIZE_DEF
#include "vbw_vec_fir_t.h"

#undef VBX_TEMPLATE_T
#define VBX_TEMPLATE_T VBX_UWORDSIZE_DEF
#include "vbw_vec_fir_t.h"

#undef VBX_TEMPLATE_T

#endif // __VBX_VEC_FIR_ALL_H
