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

/**
 * @file
 * @defgroup VBX_ASM VBX Assembly Macros
 * @brief VBX ASM Macros
 *
 * @ingroup VBXapi
 */
/**@{*/

#ifndef __VBX_ASM_NIOS_H
#define __VBX_ASM_NIOS_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __VBX_ASM_OR_SIM_H
#error "This header file should not be included directly. Instead, include \"vbx_asm_or_sim.h\""
#else

#if VBX_ASSEMBLER

// be sure these were already included
#include "vbx_macros.h"

// -------------------------------------
// Vector API: Valid Operand Modes

#define VVBU_C  "c0"
#define VVBBU_C "c0"
#define VVBS_C  "c1"
#define VVBBS_C "c1"
#define VVB_C   "c1"
#define VVBB_C  "c1"
#define VVBHU_C "c2"
#define VVBHS_C "c3"
#define VVBH_C  "c3"
#define VVBWU_C "c4"
#define VVBWS_C "c5"
#define VVBW_C  "c5"
#define VVHBU_C "c8"
#define VVHBS_C "c9"
#define VVHB_C  "c9"
#define VVHU_C  "c10"
#define VVHHU_C "c10"
#define VVHS_C  "c11"
#define VVHHS_C "c11"
#define VVH_C   "c11"
#define VVHH_C  "c11"
#define VVHWU_C "c12"
#define VVHWS_C "c13"
#define VVHW_C  "c13"
#define VVWBU_C "c16"
#define VVWBS_C "c17"
#define VVWB_C  "c17"
#define VVWHU_C "c18"
#define VVWHS_C "c19"
#define VVWH_C  "c19"
#define VVWU_C  "c20"
#define VVWWU_C "c20"
#define VVWS_C  "c21"
#define VVWWS_C "c21"
#define VVW_C   "c21"
#define VVWW_C  "c21"

//SV calls
#define SVBU_C  VVBU_C
#define SVBBU_C VVBBU_C
#define SVBS_C  VVBS_C
#define SVBBS_C VVBBS_C
#define SVB_C   VVB_C
#define SVBB_C  VVBB_C
#define SVBHU_C VVBHU_C
#define SVBHS_C VVBHS_C
#define SVBH_C  VVBH_C
#define SVBWU_C VVBWU_C
#define SVBWS_C VVBWS_C
#define SVBW_C  VVBW_C
#define SVHBU_C VVHBU_C
#define SVHBS_C VVHBS_C
#define SVHB_C  VVHB_C
#define SVHU_C  VVHU_C
#define SVHHU_C VVHHU_C
#define SVHS_C  VVHS_C
#define SVHHS_C VVHHS_C
#define SVH_C   VVH_C
#define SVHH_C  VVHH_C
#define SVHWU_C VVHWU_C
#define SVHWS_C VVHWS_C
#define SVHW_C  VVHW_C
#define SVWBU_C VVWBU_C
#define SVWBS_C VVWBS_C
#define SVWB_C  VVWB_C
#define SVWHU_C VVWHU_C
#define SVWHS_C VVWHS_C
#define SVWH_C  VVWH_C
#define SVWU_C  VVWU_C
#define SVWWU_C VVWWU_C
#define SVWS_C  VVWS_C
#define SVWWS_C VVWWS_C
#define SVW_C   VVW_C
#define SVWW_C  VVWW_C

//VE calls
#define VEBU_C  VVBU_C
#define VEBBU_C VVBBU_C
#define VEBS_C  VVBS_C
#define VEBBS_C VVBBS_C
#define VEB_C   VVB_C
#define VEBB_C  VVBB_C
#define VEBHU_C VVBHU_C
#define VEBHS_C VVBHS_C
#define VEBH_C  VVBH_C
#define VEBWU_C VVBWU_C
#define VEBWS_C VVBWS_C
#define VEBW_C  VVBW_C
#define VEHBU_C VVHBU_C
#define VEHBS_C VVHBS_C
#define VEHB_C  VVHB_C
#define VEHU_C  VVHU_C
#define VEHHU_C VVHHU_C
#define VEHS_C  VVHS_C
#define VEHHS_C VVHHS_C
#define VEH_C   VVH_C
#define VEHH_C  VVHH_C
#define VEHWU_C VVHWU_C
#define VEHWS_C VVHWS_C
#define VEHW_C  VVHW_C
#define VEWBU_C VVWBU_C
#define VEWBS_C VVWBS_C
#define VEWB_C  VVWB_C
#define VEWHU_C VVWHU_C
#define VEWHS_C VVWHS_C
#define VEWH_C  VVWH_C
#define VEWU_C  VVWU_C
#define VEWWU_C VVWWU_C
#define VEWS_C  VVWS_C
#define VEWWS_C VVWWS_C
#define VEW_C   VVW_C
#define VEWW_C  VVWW_C

//SE calls
#define SEBU_C  VVBU_C
#define SEBBU_C VVBBU_C
#define SEBS_C  VVBS_C
#define SEBBS_C VVBBS_C
#define SEB_C   VVB_C
#define SEBB_C  VVBB_C
#define SEBHU_C VVBHU_C
#define SEBHS_C VVBHS_C
#define SEBH_C  VVBH_C
#define SEBWU_C VVBWU_C
#define SEBWS_C VVBWS_C
#define SEBW_C  VVBW_C
#define SEHBU_C VVHBU_C
#define SEHBS_C VVHBS_C
#define SEHB_C  VVHB_C
#define SEHU_C  VVHU_C
#define SEHHU_C VVHHU_C
#define SEHS_C  VVHS_C
#define SEHHS_C VVHHS_C
#define SEH_C   VVH_C
#define SEHH_C  VVHH_C
#define SEHWU_C VVHWU_C
#define SEHWS_C VVHWS_C
#define SEHW_C  VVHW_C
#define SEWBU_C VVWBU_C
#define SEWBS_C VVWBS_C
#define SEWB_C  VVWB_C
#define SEWHU_C VVWHU_C
#define SEWHS_C VVWHS_C
#define SEWH_C  VVWH_C
#define SEWU_C  VVWU_C
#define SEWWU_C VVWWU_C
#define SEWS_C  VVWS_C
#define SEWWS_C VVWWS_C
#define SEW_C   VVW_C
#define SEWW_C  VVWW_C

// -------------------------------------
// Modifiers

#define MOD_NONE       "c0"
#define MOD_ACC        "c2"
#define MOD_2D         "c4"
#define MOD_ACC_2D     "c6"

#define VVBU_MOD_NONE      "c0"
#define VVBBU_MOD_NONE     VVBU_MOD_NONE
#define VVBS_MOD_NONE      VVBU_MOD_NONE
#define VVBBS_MOD_NONE     VVBU_MOD_NONE
#define VVB_MOD_NONE       VVBU_MOD_NONE
#define VVBB_MOD_NONE      VVBU_MOD_NONE
#define VVBHU_MOD_NONE     VVBU_MOD_NONE
#define VVBHS_MOD_NONE     VVBU_MOD_NONE
#define VVBH_MOD_NONE      VVBU_MOD_NONE
#define VVBWU_MOD_NONE     VVBU_MOD_NONE
#define VVBWS_MOD_NONE     VVBU_MOD_NONE
#define VVBW_MOD_NONE      VVBU_MOD_NONE
#define VVHBU_MOD_NONE     VVBU_MOD_NONE
#define VVHBS_MOD_NONE     VVBU_MOD_NONE
#define VVHB_MOD_NONE      VVBU_MOD_NONE
#define VVHU_MOD_NONE      VVBU_MOD_NONE
#define VVHHU_MOD_NONE     VVBU_MOD_NONE
#define VVHS_MOD_NONE      VVBU_MOD_NONE
#define VVHHS_MOD_NONE     VVBU_MOD_NONE
#define VVH_MOD_NONE       VVBU_MOD_NONE
#define VVHH_MOD_NONE      VVBU_MOD_NONE
#define VVHWU_MOD_NONE     VVBU_MOD_NONE
#define VVHWS_MOD_NONE     VVBU_MOD_NONE
#define VVHW_MOD_NONE      VVBU_MOD_NONE
#define VVWBU_MOD_NONE     VVBU_MOD_NONE
#define VVWBS_MOD_NONE     VVBU_MOD_NONE
#define VVWB_MOD_NONE      VVBU_MOD_NONE
#define VVWHU_MOD_NONE     VVBU_MOD_NONE
#define VVWHS_MOD_NONE     VVBU_MOD_NONE
#define VVWH_MOD_NONE      VVBU_MOD_NONE
#define VVWU_MOD_NONE      VVBU_MOD_NONE
#define VVWWU_MOD_NONE     VVBU_MOD_NONE
#define VVWS_MOD_NONE      VVBU_MOD_NONE
#define VVWWS_MOD_NONE     VVBU_MOD_NONE
#define VVW_MOD_NONE       VVBU_MOD_NONE
#define VVWW_MOD_NONE      VVBU_MOD_NONE

#define SVBU_MOD_NONE      "c16"
#define SVBBU_MOD_NONE     SVBU_MOD_NONE
#define SVBS_MOD_NONE      SVBU_MOD_NONE
#define SVBBS_MOD_NONE     SVBU_MOD_NONE
#define SVB_MOD_NONE       SVBU_MOD_NONE
#define SVBB_MOD_NONE      SVBU_MOD_NONE
#define SVBHU_MOD_NONE     SVBU_MOD_NONE
#define SVBHS_MOD_NONE     SVBU_MOD_NONE
#define SVBH_MOD_NONE      SVBU_MOD_NONE
#define SVBWU_MOD_NONE     SVBU_MOD_NONE
#define SVBWS_MOD_NONE     SVBU_MOD_NONE
#define SVBW_MOD_NONE      SVBU_MOD_NONE
#define SVHBU_MOD_NONE     SVBU_MOD_NONE
#define SVHBS_MOD_NONE     SVBU_MOD_NONE
#define SVHB_MOD_NONE      SVBU_MOD_NONE
#define SVHU_MOD_NONE      SVBU_MOD_NONE
#define SVHHU_MOD_NONE     SVBU_MOD_NONE
#define SVHS_MOD_NONE      SVBU_MOD_NONE
#define SVHHS_MOD_NONE     SVBU_MOD_NONE
#define SVH_MOD_NONE       SVBU_MOD_NONE
#define SVHH_MOD_NONE      SVBU_MOD_NONE
#define SVHWU_MOD_NONE     SVBU_MOD_NONE
#define SVHWS_MOD_NONE     SVBU_MOD_NONE
#define SVHW_MOD_NONE      SVBU_MOD_NONE
#define SVWBU_MOD_NONE     SVBU_MOD_NONE
#define SVWBS_MOD_NONE     SVBU_MOD_NONE
#define SVWB_MOD_NONE      SVBU_MOD_NONE
#define SVWHU_MOD_NONE     SVBU_MOD_NONE
#define SVWHS_MOD_NONE     SVBU_MOD_NONE
#define SVWH_MOD_NONE      SVBU_MOD_NONE
#define SVWU_MOD_NONE      SVBU_MOD_NONE
#define SVWWU_MOD_NONE     SVBU_MOD_NONE
#define SVWS_MOD_NONE      SVBU_MOD_NONE
#define SVWWS_MOD_NONE     SVBU_MOD_NONE
#define SVW_MOD_NONE       SVBU_MOD_NONE
#define SVWW_MOD_NONE      SVBU_MOD_NONE

#define VEBU_MOD_NONE      "c8"
#define VEBBU_MOD_NONE     VEBU_MOD_NONE
#define VEBS_MOD_NONE      VEBU_MOD_NONE
#define VEBBS_MOD_NONE     VEBU_MOD_NONE
#define VEB_MOD_NONE       VEBU_MOD_NONE
#define VEBB_MOD_NONE      VEBU_MOD_NONE
#define VEBHU_MOD_NONE     VEBU_MOD_NONE
#define VEBHS_MOD_NONE     VEBU_MOD_NONE
#define VEBH_MOD_NONE      VEBU_MOD_NONE
#define VEBWU_MOD_NONE     VEBU_MOD_NONE
#define VEBWS_MOD_NONE     VEBU_MOD_NONE
#define VEBW_MOD_NONE      VEBU_MOD_NONE
#define VEHBU_MOD_NONE     VEBU_MOD_NONE
#define VEHBS_MOD_NONE     VEBU_MOD_NONE
#define VEHB_MOD_NONE      VEBU_MOD_NONE
#define VEHU_MOD_NONE      VEBU_MOD_NONE
#define VEHHU_MOD_NONE     VEBU_MOD_NONE
#define VEHS_MOD_NONE      VEBU_MOD_NONE
#define VEHHS_MOD_NONE     VEBU_MOD_NONE
#define VEH_MOD_NONE       VEBU_MOD_NONE
#define VEHH_MOD_NONE      VEBU_MOD_NONE
#define VEHWU_MOD_NONE     VEBU_MOD_NONE
#define VEHWS_MOD_NONE     VEBU_MOD_NONE
#define VEHW_MOD_NONE      VEBU_MOD_NONE
#define VEWBU_MOD_NONE     VEBU_MOD_NONE
#define VEWBS_MOD_NONE     VEBU_MOD_NONE
#define VEWB_MOD_NONE      VEBU_MOD_NONE
#define VEWHU_MOD_NONE     VEBU_MOD_NONE
#define VEWHS_MOD_NONE     VEBU_MOD_NONE
#define VEWH_MOD_NONE      VEBU_MOD_NONE
#define VEWU_MOD_NONE      VEBU_MOD_NONE
#define VEWWU_MOD_NONE     VEBU_MOD_NONE
#define VEWS_MOD_NONE      VEBU_MOD_NONE
#define VEWWS_MOD_NONE     VEBU_MOD_NONE
#define VEW_MOD_NONE       VEBU_MOD_NONE
#define VEWW_MOD_NONE      VEBU_MOD_NONE

#define SEBU_MOD_NONE      "c24"
#define SEBBU_MOD_NONE     SEBU_MOD_NONE
#define SEBS_MOD_NONE      SEBU_MOD_NONE
#define SEBBS_MOD_NONE     SEBU_MOD_NONE
#define SEB_MOD_NONE       SEBU_MOD_NONE
#define SEBB_MOD_NONE      SEBU_MOD_NONE
#define SEBHU_MOD_NONE     SEBU_MOD_NONE
#define SEBHS_MOD_NONE     SEBU_MOD_NONE
#define SEBH_MOD_NONE      SEBU_MOD_NONE
#define SEBWU_MOD_NONE     SEBU_MOD_NONE
#define SEBWS_MOD_NONE     SEBU_MOD_NONE
#define SEBW_MOD_NONE      SEBU_MOD_NONE
#define SEHBU_MOD_NONE     SEBU_MOD_NONE
#define SEHBS_MOD_NONE     SEBU_MOD_NONE
#define SEHB_MOD_NONE      SEBU_MOD_NONE
#define SEHU_MOD_NONE      SEBU_MOD_NONE
#define SEHHU_MOD_NONE     SEBU_MOD_NONE
#define SEHS_MOD_NONE      SEBU_MOD_NONE
#define SEHHS_MOD_NONE     SEBU_MOD_NONE
#define SEH_MOD_NONE       SEBU_MOD_NONE
#define SEHH_MOD_NONE      SEBU_MOD_NONE
#define SEHWU_MOD_NONE     SEBU_MOD_NONE
#define SEHWS_MOD_NONE     SEBU_MOD_NONE
#define SEHW_MOD_NONE      SEBU_MOD_NONE
#define SEWBU_MOD_NONE     SEBU_MOD_NONE
#define SEWBS_MOD_NONE     SEBU_MOD_NONE
#define SEWB_MOD_NONE      SEBU_MOD_NONE
#define SEWHU_MOD_NONE     SEBU_MOD_NONE
#define SEWHS_MOD_NONE     SEBU_MOD_NONE
#define SEWH_MOD_NONE      SEBU_MOD_NONE
#define SEWU_MOD_NONE      SEBU_MOD_NONE
#define SEWWU_MOD_NONE     SEBU_MOD_NONE
#define SEWS_MOD_NONE      SEBU_MOD_NONE
#define SEWWS_MOD_NONE     SEBU_MOD_NONE
#define SEW_MOD_NONE       SEBU_MOD_NONE
#define SEWW_MOD_NONE      SEBU_MOD_NONE

#define VVBU_MOD_ACC      "c2"
#define VVBBU_MOD_ACC     VVBU_MOD_ACC
#define VVBS_MOD_ACC      VVBU_MOD_ACC
#define VVBBS_MOD_ACC     VVBU_MOD_ACC
#define VVB_MOD_ACC       VVBU_MOD_ACC
#define VVBB_MOD_ACC      VVBU_MOD_ACC
#define VVBHU_MOD_ACC     VVBU_MOD_ACC
#define VVBHS_MOD_ACC     VVBU_MOD_ACC
#define VVBH_MOD_ACC      VVBU_MOD_ACC
#define VVBWU_MOD_ACC     VVBU_MOD_ACC
#define VVBWS_MOD_ACC     VVBU_MOD_ACC
#define VVBW_MOD_ACC      VVBU_MOD_ACC
#define VVHBU_MOD_ACC     VVBU_MOD_ACC
#define VVHBS_MOD_ACC     VVBU_MOD_ACC
#define VVHB_MOD_ACC      VVBU_MOD_ACC
#define VVHU_MOD_ACC      VVBU_MOD_ACC
#define VVHHU_MOD_ACC     VVBU_MOD_ACC
#define VVHS_MOD_ACC      VVBU_MOD_ACC
#define VVHHS_MOD_ACC     VVBU_MOD_ACC
#define VVH_MOD_ACC       VVBU_MOD_ACC
#define VVHH_MOD_ACC      VVBU_MOD_ACC
#define VVHWU_MOD_ACC     VVBU_MOD_ACC
#define VVHWS_MOD_ACC     VVBU_MOD_ACC
#define VVHW_MOD_ACC      VVBU_MOD_ACC
#define VVWBU_MOD_ACC     VVBU_MOD_ACC
#define VVWBS_MOD_ACC     VVBU_MOD_ACC
#define VVWB_MOD_ACC      VVBU_MOD_ACC
#define VVWHU_MOD_ACC     VVBU_MOD_ACC
#define VVWHS_MOD_ACC     VVBU_MOD_ACC
#define VVWH_MOD_ACC      VVBU_MOD_ACC
#define VVWU_MOD_ACC      VVBU_MOD_ACC
#define VVWWU_MOD_ACC     VVBU_MOD_ACC
#define VVWS_MOD_ACC      VVBU_MOD_ACC
#define VVWWS_MOD_ACC     VVBU_MOD_ACC
#define VVW_MOD_ACC       VVBU_MOD_ACC
#define VVWW_MOD_ACC      VVBU_MOD_ACC

#define SVBU_MOD_ACC      "c18"
#define SVBBU_MOD_ACC     SVBU_MOD_ACC
#define SVBS_MOD_ACC      SVBU_MOD_ACC
#define SVBBS_MOD_ACC     SVBU_MOD_ACC
#define SVB_MOD_ACC       SVBU_MOD_ACC
#define SVBB_MOD_ACC      SVBU_MOD_ACC
#define SVBHU_MOD_ACC     SVBU_MOD_ACC
#define SVBHS_MOD_ACC     SVBU_MOD_ACC
#define SVBH_MOD_ACC      SVBU_MOD_ACC
#define SVBWU_MOD_ACC     SVBU_MOD_ACC
#define SVBWS_MOD_ACC     SVBU_MOD_ACC
#define SVBW_MOD_ACC      SVBU_MOD_ACC
#define SVHBU_MOD_ACC     SVBU_MOD_ACC
#define SVHBS_MOD_ACC     SVBU_MOD_ACC
#define SVHB_MOD_ACC      SVBU_MOD_ACC
#define SVHU_MOD_ACC      SVBU_MOD_ACC
#define SVHHU_MOD_ACC     SVBU_MOD_ACC
#define SVHS_MOD_ACC      SVBU_MOD_ACC
#define SVHHS_MOD_ACC     SVBU_MOD_ACC
#define SVH_MOD_ACC       SVBU_MOD_ACC
#define SVHH_MOD_ACC      SVBU_MOD_ACC
#define SVHWU_MOD_ACC     SVBU_MOD_ACC
#define SVHWS_MOD_ACC     SVBU_MOD_ACC
#define SVHW_MOD_ACC      SVBU_MOD_ACC
#define SVWBU_MOD_ACC     SVBU_MOD_ACC
#define SVWBS_MOD_ACC     SVBU_MOD_ACC
#define SVWB_MOD_ACC      SVBU_MOD_ACC
#define SVWHU_MOD_ACC     SVBU_MOD_ACC
#define SVWHS_MOD_ACC     SVBU_MOD_ACC
#define SVWH_MOD_ACC      SVBU_MOD_ACC
#define SVWU_MOD_ACC      SVBU_MOD_ACC
#define SVWWU_MOD_ACC     SVBU_MOD_ACC
#define SVWS_MOD_ACC      SVBU_MOD_ACC
#define SVWWS_MOD_ACC     SVBU_MOD_ACC
#define SVW_MOD_ACC       SVBU_MOD_ACC
#define SVWW_MOD_ACC      SVBU_MOD_ACC

#define VEBU_MOD_ACC      "c10"
#define VEBBU_MOD_ACC     VEBU_MOD_ACC
#define VEBS_MOD_ACC      VEBU_MOD_ACC
#define VEBBS_MOD_ACC     VEBU_MOD_ACC
#define VEB_MOD_ACC       VEBU_MOD_ACC
#define VEBB_MOD_ACC      VEBU_MOD_ACC
#define VEBHU_MOD_ACC     VEBU_MOD_ACC
#define VEBHS_MOD_ACC     VEBU_MOD_ACC
#define VEBH_MOD_ACC      VEBU_MOD_ACC
#define VEBWU_MOD_ACC     VEBU_MOD_ACC
#define VEBWS_MOD_ACC     VEBU_MOD_ACC
#define VEBW_MOD_ACC      VEBU_MOD_ACC
#define VEHBU_MOD_ACC     VEBU_MOD_ACC
#define VEHBS_MOD_ACC     VEBU_MOD_ACC
#define VEHB_MOD_ACC      VEBU_MOD_ACC
#define VEHU_MOD_ACC      VEBU_MOD_ACC
#define VEHHU_MOD_ACC     VEBU_MOD_ACC
#define VEHS_MOD_ACC      VEBU_MOD_ACC
#define VEHHS_MOD_ACC     VEBU_MOD_ACC
#define VEH_MOD_ACC       VEBU_MOD_ACC
#define VEHH_MOD_ACC      VEBU_MOD_ACC
#define VEHWU_MOD_ACC     VEBU_MOD_ACC
#define VEHWS_MOD_ACC     VEBU_MOD_ACC
#define VEHW_MOD_ACC      VEBU_MOD_ACC
#define VEWBU_MOD_ACC     VEBU_MOD_ACC
#define VEWBS_MOD_ACC     VEBU_MOD_ACC
#define VEWB_MOD_ACC      VEBU_MOD_ACC
#define VEWHU_MOD_ACC     VEBU_MOD_ACC
#define VEWHS_MOD_ACC     VEBU_MOD_ACC
#define VEWH_MOD_ACC      VEBU_MOD_ACC
#define VEWU_MOD_ACC      VEBU_MOD_ACC
#define VEWWU_MOD_ACC     VEBU_MOD_ACC
#define VEWS_MOD_ACC      VEBU_MOD_ACC
#define VEWWS_MOD_ACC     VEBU_MOD_ACC
#define VEW_MOD_ACC       VEBU_MOD_ACC
#define VEWW_MOD_ACC      VEBU_MOD_ACC

#define SEBU_MOD_ACC      "c26"
#define SEBBU_MOD_ACC     SEBU_MOD_ACC
#define SEBS_MOD_ACC      SEBU_MOD_ACC
#define SEBBS_MOD_ACC     SEBU_MOD_ACC
#define SEB_MOD_ACC       SEBU_MOD_ACC
#define SEBB_MOD_ACC      SEBU_MOD_ACC
#define SEBHU_MOD_ACC     SEBU_MOD_ACC
#define SEBHS_MOD_ACC     SEBU_MOD_ACC
#define SEBH_MOD_ACC      SEBU_MOD_ACC
#define SEBWU_MOD_ACC     SEBU_MOD_ACC
#define SEBWS_MOD_ACC     SEBU_MOD_ACC
#define SEBW_MOD_ACC      SEBU_MOD_ACC
#define SEHBU_MOD_ACC     SEBU_MOD_ACC
#define SEHBS_MOD_ACC     SEBU_MOD_ACC
#define SEHB_MOD_ACC      SEBU_MOD_ACC
#define SEHU_MOD_ACC      SEBU_MOD_ACC
#define SEHHU_MOD_ACC     SEBU_MOD_ACC
#define SEHS_MOD_ACC      SEBU_MOD_ACC
#define SEHHS_MOD_ACC     SEBU_MOD_ACC
#define SEH_MOD_ACC       SEBU_MOD_ACC
#define SEHH_MOD_ACC      SEBU_MOD_ACC
#define SEHWU_MOD_ACC     SEBU_MOD_ACC
#define SEHWS_MOD_ACC     SEBU_MOD_ACC
#define SEHW_MOD_ACC      SEBU_MOD_ACC
#define SEWBU_MOD_ACC     SEBU_MOD_ACC
#define SEWBS_MOD_ACC     SEBU_MOD_ACC
#define SEWB_MOD_ACC      SEBU_MOD_ACC
#define SEWHU_MOD_ACC     SEBU_MOD_ACC
#define SEWHS_MOD_ACC     SEBU_MOD_ACC
#define SEWH_MOD_ACC      SEBU_MOD_ACC
#define SEWU_MOD_ACC      SEBU_MOD_ACC
#define SEWWU_MOD_ACC     SEBU_MOD_ACC
#define SEWS_MOD_ACC      SEBU_MOD_ACC
#define SEWWS_MOD_ACC     SEBU_MOD_ACC
#define SEW_MOD_ACC       SEBU_MOD_ACC
#define SEWW_MOD_ACC      SEBU_MOD_ACC

#define VVBU_MOD_2D      "c4"
#define VVBBU_MOD_2D     VVBU_MOD_2D
#define VVBS_MOD_2D      VVBU_MOD_2D
#define VVBBS_MOD_2D     VVBU_MOD_2D
#define VVB_MOD_2D       VVBU_MOD_2D
#define VVBB_MOD_2D      VVBU_MOD_2D
#define VVBHU_MOD_2D     VVBU_MOD_2D
#define VVBHS_MOD_2D     VVBU_MOD_2D
#define VVBH_MOD_2D      VVBU_MOD_2D
#define VVBWU_MOD_2D     VVBU_MOD_2D
#define VVBWS_MOD_2D     VVBU_MOD_2D
#define VVBW_MOD_2D      VVBU_MOD_2D
#define VVHBU_MOD_2D     VVBU_MOD_2D
#define VVHBS_MOD_2D     VVBU_MOD_2D
#define VVHB_MOD_2D      VVBU_MOD_2D
#define VVHU_MOD_2D      VVBU_MOD_2D
#define VVHHU_MOD_2D     VVBU_MOD_2D
#define VVHS_MOD_2D      VVBU_MOD_2D
#define VVHHS_MOD_2D     VVBU_MOD_2D
#define VVH_MOD_2D       VVBU_MOD_2D
#define VVHH_MOD_2D      VVBU_MOD_2D
#define VVHWU_MOD_2D     VVBU_MOD_2D
#define VVHWS_MOD_2D     VVBU_MOD_2D
#define VVHW_MOD_2D      VVBU_MOD_2D
#define VVWBU_MOD_2D     VVBU_MOD_2D
#define VVWBS_MOD_2D     VVBU_MOD_2D
#define VVWB_MOD_2D      VVBU_MOD_2D
#define VVWHU_MOD_2D     VVBU_MOD_2D
#define VVWHS_MOD_2D     VVBU_MOD_2D
#define VVWH_MOD_2D      VVBU_MOD_2D
#define VVWU_MOD_2D      VVBU_MOD_2D
#define VVWWU_MOD_2D     VVBU_MOD_2D
#define VVWS_MOD_2D      VVBU_MOD_2D
#define VVWWS_MOD_2D     VVBU_MOD_2D
#define VVW_MOD_2D       VVBU_MOD_2D
#define VVWW_MOD_2D      VVBU_MOD_2D

#define SVBU_MOD_2D      "c20"
#define SVBBU_MOD_2D     SVBU_MOD_2D
#define SVBS_MOD_2D      SVBU_MOD_2D
#define SVBBS_MOD_2D     SVBU_MOD_2D
#define SVB_MOD_2D       SVBU_MOD_2D
#define SVBB_MOD_2D      SVBU_MOD_2D
#define SVBHU_MOD_2D     SVBU_MOD_2D
#define SVBHS_MOD_2D     SVBU_MOD_2D
#define SVBH_MOD_2D      SVBU_MOD_2D
#define SVBWU_MOD_2D     SVBU_MOD_2D
#define SVBWS_MOD_2D     SVBU_MOD_2D
#define SVBW_MOD_2D      SVBU_MOD_2D
#define SVHBU_MOD_2D     SVBU_MOD_2D
#define SVHBS_MOD_2D     SVBU_MOD_2D
#define SVHB_MOD_2D      SVBU_MOD_2D
#define SVHU_MOD_2D      SVBU_MOD_2D
#define SVHHU_MOD_2D     SVBU_MOD_2D
#define SVHS_MOD_2D      SVBU_MOD_2D
#define SVHHS_MOD_2D     SVBU_MOD_2D
#define SVH_MOD_2D       SVBU_MOD_2D
#define SVHH_MOD_2D      SVBU_MOD_2D
#define SVHWU_MOD_2D     SVBU_MOD_2D
#define SVHWS_MOD_2D     SVBU_MOD_2D
#define SVHW_MOD_2D      SVBU_MOD_2D
#define SVWBU_MOD_2D     SVBU_MOD_2D
#define SVWBS_MOD_2D     SVBU_MOD_2D
#define SVWB_MOD_2D      SVBU_MOD_2D
#define SVWHU_MOD_2D     SVBU_MOD_2D
#define SVWHS_MOD_2D     SVBU_MOD_2D
#define SVWH_MOD_2D      SVBU_MOD_2D
#define SVWU_MOD_2D      SVBU_MOD_2D
#define SVWWU_MOD_2D     SVBU_MOD_2D
#define SVWS_MOD_2D      SVBU_MOD_2D
#define SVWWS_MOD_2D     SVBU_MOD_2D
#define SVW_MOD_2D       SVBU_MOD_2D
#define SVWW_MOD_2D      SVBU_MOD_2D

#define VEBU_MOD_2D      "c12"
#define VEBBU_MOD_2D     VEBU_MOD_2D
#define VEBS_MOD_2D      VEBU_MOD_2D
#define VEBBS_MOD_2D     VEBU_MOD_2D
#define VEB_MOD_2D       VEBU_MOD_2D
#define VEBB_MOD_2D      VEBU_MOD_2D
#define VEBHU_MOD_2D     VEBU_MOD_2D
#define VEBHS_MOD_2D     VEBU_MOD_2D
#define VEBH_MOD_2D      VEBU_MOD_2D
#define VEBWU_MOD_2D     VEBU_MOD_2D
#define VEBWS_MOD_2D     VEBU_MOD_2D
#define VEBW_MOD_2D      VEBU_MOD_2D
#define VEHBU_MOD_2D     VEBU_MOD_2D
#define VEHBS_MOD_2D     VEBU_MOD_2D
#define VEHB_MOD_2D      VEBU_MOD_2D
#define VEHU_MOD_2D      VEBU_MOD_2D
#define VEHHU_MOD_2D     VEBU_MOD_2D
#define VEHS_MOD_2D      VEBU_MOD_2D
#define VEHHS_MOD_2D     VEBU_MOD_2D
#define VEH_MOD_2D       VEBU_MOD_2D
#define VEHH_MOD_2D      VEBU_MOD_2D
#define VEHWU_MOD_2D     VEBU_MOD_2D
#define VEHWS_MOD_2D     VEBU_MOD_2D
#define VEHW_MOD_2D      VEBU_MOD_2D
#define VEWBU_MOD_2D     VEBU_MOD_2D
#define VEWBS_MOD_2D     VEBU_MOD_2D
#define VEWB_MOD_2D      VEBU_MOD_2D
#define VEWHU_MOD_2D     VEBU_MOD_2D
#define VEWHS_MOD_2D     VEBU_MOD_2D
#define VEWH_MOD_2D      VEBU_MOD_2D
#define VEWU_MOD_2D      VEBU_MOD_2D
#define VEWWU_MOD_2D     VEBU_MOD_2D
#define VEWS_MOD_2D      VEBU_MOD_2D
#define VEWWS_MOD_2D     VEBU_MOD_2D
#define VEW_MOD_2D       VEBU_MOD_2D
#define VEWW_MOD_2D      VEBU_MOD_2D

#define SEBU_MOD_2D      "c28"
#define SEBBU_MOD_2D     SEBU_MOD_2D
#define SEBS_MOD_2D      SEBU_MOD_2D
#define SEBBS_MOD_2D     SEBU_MOD_2D
#define SEB_MOD_2D       SEBU_MOD_2D
#define SEBB_MOD_2D      SEBU_MOD_2D
#define SEBHU_MOD_2D     SEBU_MOD_2D
#define SEBHS_MOD_2D     SEBU_MOD_2D
#define SEBH_MOD_2D      SEBU_MOD_2D
#define SEBWU_MOD_2D     SEBU_MOD_2D
#define SEBWS_MOD_2D     SEBU_MOD_2D
#define SEBW_MOD_2D      SEBU_MOD_2D
#define SEHBU_MOD_2D     SEBU_MOD_2D
#define SEHBS_MOD_2D     SEBU_MOD_2D
#define SEHB_MOD_2D      SEBU_MOD_2D
#define SEHU_MOD_2D      SEBU_MOD_2D
#define SEHHU_MOD_2D     SEBU_MOD_2D
#define SEHS_MOD_2D      SEBU_MOD_2D
#define SEHHS_MOD_2D     SEBU_MOD_2D
#define SEH_MOD_2D       SEBU_MOD_2D
#define SEHH_MOD_2D      SEBU_MOD_2D
#define SEHWU_MOD_2D     SEBU_MOD_2D
#define SEHWS_MOD_2D     SEBU_MOD_2D
#define SEHW_MOD_2D      SEBU_MOD_2D
#define SEWBU_MOD_2D     SEBU_MOD_2D
#define SEWBS_MOD_2D     SEBU_MOD_2D
#define SEWB_MOD_2D      SEBU_MOD_2D
#define SEWHU_MOD_2D     SEBU_MOD_2D
#define SEWHS_MOD_2D     SEBU_MOD_2D
#define SEWH_MOD_2D      SEBU_MOD_2D
#define SEWU_MOD_2D      SEBU_MOD_2D
#define SEWWU_MOD_2D     SEBU_MOD_2D
#define SEWS_MOD_2D      SEBU_MOD_2D
#define SEWWS_MOD_2D     SEBU_MOD_2D
#define SEW_MOD_2D       SEBU_MOD_2D
#define SEWW_MOD_2D      SEBU_MOD_2D

#define VVBU_MOD_ACC_2D      "c6"
#define VVBBU_MOD_ACC_2D     VVBU_MOD_ACC_2D
#define VVBS_MOD_ACC_2D      VVBU_MOD_ACC_2D
#define VVBBS_MOD_ACC_2D     VVBU_MOD_ACC_2D
#define VVB_MOD_ACC_2D       VVBU_MOD_ACC_2D
#define VVBB_MOD_ACC_2D      VVBU_MOD_ACC_2D
#define VVBHU_MOD_ACC_2D     VVBU_MOD_ACC_2D
#define VVBHS_MOD_ACC_2D     VVBU_MOD_ACC_2D
#define VVBH_MOD_ACC_2D      VVBU_MOD_ACC_2D
#define VVBWU_MOD_ACC_2D     VVBU_MOD_ACC_2D
#define VVBWS_MOD_ACC_2D     VVBU_MOD_ACC_2D
#define VVBW_MOD_ACC_2D      VVBU_MOD_ACC_2D
#define VVHBU_MOD_ACC_2D     VVBU_MOD_ACC_2D
#define VVHBS_MOD_ACC_2D     VVBU_MOD_ACC_2D
#define VVHB_MOD_ACC_2D      VVBU_MOD_ACC_2D
#define VVHU_MOD_ACC_2D      VVBU_MOD_ACC_2D
#define VVHHU_MOD_ACC_2D     VVBU_MOD_ACC_2D
#define VVHS_MOD_ACC_2D      VVBU_MOD_ACC_2D
#define VVHHS_MOD_ACC_2D     VVBU_MOD_ACC_2D
#define VVH_MOD_ACC_2D       VVBU_MOD_ACC_2D
#define VVHH_MOD_ACC_2D      VVBU_MOD_ACC_2D
#define VVHWU_MOD_ACC_2D     VVBU_MOD_ACC_2D
#define VVHWS_MOD_ACC_2D     VVBU_MOD_ACC_2D
#define VVHW_MOD_ACC_2D      VVBU_MOD_ACC_2D
#define VVWBU_MOD_ACC_2D     VVBU_MOD_ACC_2D
#define VVWBS_MOD_ACC_2D     VVBU_MOD_ACC_2D
#define VVWB_MOD_ACC_2D      VVBU_MOD_ACC_2D
#define VVWHU_MOD_ACC_2D     VVBU_MOD_ACC_2D
#define VVWHS_MOD_ACC_2D     VVBU_MOD_ACC_2D
#define VVWH_MOD_ACC_2D      VVBU_MOD_ACC_2D
#define VVWU_MOD_ACC_2D      VVBU_MOD_ACC_2D
#define VVWWU_MOD_ACC_2D     VVBU_MOD_ACC_2D
#define VVWS_MOD_ACC_2D      VVBU_MOD_ACC_2D
#define VVWWS_MOD_ACC_2D     VVBU_MOD_ACC_2D
#define VVW_MOD_ACC_2D       VVBU_MOD_ACC_2D
#define VVWW_MOD_ACC_2D      VVBU_MOD_ACC_2D

#define SVBU_MOD_ACC_2D      "c22"
#define SVBBU_MOD_ACC_2D     SVBU_MOD_ACC_2D
#define SVBS_MOD_ACC_2D      SVBU_MOD_ACC_2D
#define SVBBS_MOD_ACC_2D     SVBU_MOD_ACC_2D
#define SVB_MOD_ACC_2D       SVBU_MOD_ACC_2D
#define SVBB_MOD_ACC_2D      SVBU_MOD_ACC_2D
#define SVBHU_MOD_ACC_2D     SVBU_MOD_ACC_2D
#define SVBHS_MOD_ACC_2D     SVBU_MOD_ACC_2D
#define SVBH_MOD_ACC_2D      SVBU_MOD_ACC_2D
#define SVBWU_MOD_ACC_2D     SVBU_MOD_ACC_2D
#define SVBWS_MOD_ACC_2D     SVBU_MOD_ACC_2D
#define SVBW_MOD_ACC_2D      SVBU_MOD_ACC_2D
#define SVHBU_MOD_ACC_2D     SVBU_MOD_ACC_2D
#define SVHBS_MOD_ACC_2D     SVBU_MOD_ACC_2D
#define SVHB_MOD_ACC_2D      SVBU_MOD_ACC_2D
#define SVHU_MOD_ACC_2D      SVBU_MOD_ACC_2D
#define SVHHU_MOD_ACC_2D     SVBU_MOD_ACC_2D
#define SVHS_MOD_ACC_2D      SVBU_MOD_ACC_2D
#define SVHHS_MOD_ACC_2D     SVBU_MOD_ACC_2D
#define SVH_MOD_ACC_2D       SVBU_MOD_ACC_2D
#define SVHH_MOD_ACC_2D      SVBU_MOD_ACC_2D
#define SVHWU_MOD_ACC_2D     SVBU_MOD_ACC_2D
#define SVHWS_MOD_ACC_2D     SVBU_MOD_ACC_2D
#define SVHW_MOD_ACC_2D      SVBU_MOD_ACC_2D
#define SVWBU_MOD_ACC_2D     SVBU_MOD_ACC_2D
#define SVWBS_MOD_ACC_2D     SVBU_MOD_ACC_2D
#define SVWB_MOD_ACC_2D      SVBU_MOD_ACC_2D
#define SVWHU_MOD_ACC_2D     SVBU_MOD_ACC_2D
#define SVWHS_MOD_ACC_2D     SVBU_MOD_ACC_2D
#define SVWH_MOD_ACC_2D      SVBU_MOD_ACC_2D
#define SVWU_MOD_ACC_2D      SVBU_MOD_ACC_2D
#define SVWWU_MOD_ACC_2D     SVBU_MOD_ACC_2D
#define SVWS_MOD_ACC_2D      SVBU_MOD_ACC_2D
#define SVWWS_MOD_ACC_2D     SVBU_MOD_ACC_2D
#define SVW_MOD_ACC_2D       SVBU_MOD_ACC_2D
#define SVWW_MOD_ACC_2D      SVBU_MOD_ACC_2D

#define VEBU_MOD_ACC_2D      "c14"
#define VEBBU_MOD_ACC_2D     VEBU_MOD_ACC_2D
#define VEBS_MOD_ACC_2D      VEBU_MOD_ACC_2D
#define VEBBS_MOD_ACC_2D     VEBU_MOD_ACC_2D
#define VEB_MOD_ACC_2D       VEBU_MOD_ACC_2D
#define VEBB_MOD_ACC_2D      VEBU_MOD_ACC_2D
#define VEBHU_MOD_ACC_2D     VEBU_MOD_ACC_2D
#define VEBHS_MOD_ACC_2D     VEBU_MOD_ACC_2D
#define VEBH_MOD_ACC_2D      VEBU_MOD_ACC_2D
#define VEBWU_MOD_ACC_2D     VEBU_MOD_ACC_2D
#define VEBWS_MOD_ACC_2D     VEBU_MOD_ACC_2D
#define VEBW_MOD_ACC_2D      VEBU_MOD_ACC_2D
#define VEHBU_MOD_ACC_2D     VEBU_MOD_ACC_2D
#define VEHBS_MOD_ACC_2D     VEBU_MOD_ACC_2D
#define VEHB_MOD_ACC_2D      VEBU_MOD_ACC_2D
#define VEHU_MOD_ACC_2D      VEBU_MOD_ACC_2D
#define VEHHU_MOD_ACC_2D     VEBU_MOD_ACC_2D
#define VEHS_MOD_ACC_2D      VEBU_MOD_ACC_2D
#define VEHHS_MOD_ACC_2D     VEBU_MOD_ACC_2D
#define VEH_MOD_ACC_2D       VEBU_MOD_ACC_2D
#define VEHH_MOD_ACC_2D      VEBU_MOD_ACC_2D
#define VEHWU_MOD_ACC_2D     VEBU_MOD_ACC_2D
#define VEHWS_MOD_ACC_2D     VEBU_MOD_ACC_2D
#define VEHW_MOD_ACC_2D      VEBU_MOD_ACC_2D
#define VEWBU_MOD_ACC_2D     VEBU_MOD_ACC_2D
#define VEWBS_MOD_ACC_2D     VEBU_MOD_ACC_2D
#define VEWB_MOD_ACC_2D      VEBU_MOD_ACC_2D
#define VEWHU_MOD_ACC_2D     VEBU_MOD_ACC_2D
#define VEWHS_MOD_ACC_2D     VEBU_MOD_ACC_2D
#define VEWH_MOD_ACC_2D      VEBU_MOD_ACC_2D
#define VEWU_MOD_ACC_2D      VEBU_MOD_ACC_2D
#define VEWWU_MOD_ACC_2D     VEBU_MOD_ACC_2D
#define VEWS_MOD_ACC_2D      VEBU_MOD_ACC_2D
#define VEWWS_MOD_ACC_2D     VEBU_MOD_ACC_2D
#define VEW_MOD_ACC_2D       VEBU_MOD_ACC_2D
#define VEWW_MOD_ACC_2D      VEBU_MOD_ACC_2D

#define SEBU_MOD_ACC_2D      "c30"
#define SEBBU_MOD_ACC_2D     SEBU_MOD_ACC_2D
#define SEBS_MOD_ACC_2D      SEBU_MOD_ACC_2D
#define SEBBS_MOD_ACC_2D     SEBU_MOD_ACC_2D
#define SEB_MOD_ACC_2D       SEBU_MOD_ACC_2D
#define SEBB_MOD_ACC_2D      SEBU_MOD_ACC_2D
#define SEBHU_MOD_ACC_2D     SEBU_MOD_ACC_2D
#define SEBHS_MOD_ACC_2D     SEBU_MOD_ACC_2D
#define SEBH_MOD_ACC_2D      SEBU_MOD_ACC_2D
#define SEBWU_MOD_ACC_2D     SEBU_MOD_ACC_2D
#define SEBWS_MOD_ACC_2D     SEBU_MOD_ACC_2D
#define SEBW_MOD_ACC_2D      SEBU_MOD_ACC_2D
#define SEHBU_MOD_ACC_2D     SEBU_MOD_ACC_2D
#define SEHBS_MOD_ACC_2D     SEBU_MOD_ACC_2D
#define SEHB_MOD_ACC_2D      SEBU_MOD_ACC_2D
#define SEHU_MOD_ACC_2D      SEBU_MOD_ACC_2D
#define SEHHU_MOD_ACC_2D     SEBU_MOD_ACC_2D
#define SEHS_MOD_ACC_2D      SEBU_MOD_ACC_2D
#define SEHHS_MOD_ACC_2D     SEBU_MOD_ACC_2D
#define SEH_MOD_ACC_2D       SEBU_MOD_ACC_2D
#define SEHH_MOD_ACC_2D      SEBU_MOD_ACC_2D
#define SEHWU_MOD_ACC_2D     SEBU_MOD_ACC_2D
#define SEHWS_MOD_ACC_2D     SEBU_MOD_ACC_2D
#define SEHW_MOD_ACC_2D      SEBU_MOD_ACC_2D
#define SEWBU_MOD_ACC_2D     SEBU_MOD_ACC_2D
#define SEWBS_MOD_ACC_2D     SEBU_MOD_ACC_2D
#define SEWB_MOD_ACC_2D      SEBU_MOD_ACC_2D
#define SEWHU_MOD_ACC_2D     SEBU_MOD_ACC_2D
#define SEWHS_MOD_ACC_2D     SEBU_MOD_ACC_2D
#define SEWH_MOD_ACC_2D      SEBU_MOD_ACC_2D
#define SEWU_MOD_ACC_2D      SEBU_MOD_ACC_2D
#define SEWWU_MOD_ACC_2D     SEBU_MOD_ACC_2D
#define SEWS_MOD_ACC_2D      SEBU_MOD_ACC_2D
#define SEWWS_MOD_ACC_2D     SEBU_MOD_ACC_2D
#define SEW_MOD_ACC_2D       SEBU_MOD_ACC_2D
#define SEWW_MOD_ACC_2D      SEBU_MOD_ACC_2D

// -------------------------------------
// Vector API: Valid Instructions

#define VMOV_I "c4"
#define VAND_I "c5"
#define VOR_I  "c6"
#define VXOR_I "c7"

#define VADD_I  "c8"
#define VSUB_I  "c9"
#define VADDC_I "c10"
#define VSUBB_I "c11"

#define VMUL_I    "c12"
#define VMULLO_I  "c12"
#define VMULHI_I  "c13"
#define VMULFXP_I "c14"

#define VSHL_I  "c16"
#define VSHR_I  "c17"
#define VROTL_I "c18"
#define VROTR_I "c19"

#define VCUSTOM_I   "c20"
#define VCUSTOM0_I  "c20"
#define VCUSTOM1_I  "c21"
#define VCUSTOM2_I  "c22"
#define VCUSTOM3_I  "c23"

#define VCMV_LEZ_I  "c24" // N | Z
#define VCMV_GTZ_I  "c25" // ~N & ~Z
#define VCMV_LTZ_I  "c26" // N
#define VCMV_FS_I   "c26" // N
#define VCMV_GEZ_I  "c27" // ~N
#define VCMV_FC_I   "c27" // ~N
#define VCMV_Z_I    "c28" // Z
#define VCMV_NZ_I   "c29" // ~Z

#define VABSDIFF_I  "c31"

#define VMOV_3D "r4"
#define VAND_3D "r5"
#define VOR_3D  "r6"
#define VXOR_3D "r7"

#define VADD_3D  "r8"
#define VSUB_3D  "r9"
#define VADDC_3D "r10"
#define VSUBB_3D "r11"

#define VMUL_3D    "r12"
#define VMULLO_3D  "r12"
#define VMULHI_3D  "r13"
#define VMULFXP_3D "r14"

#define VSHL_3D  "r16"
#define VSHR_3D  "r17"
#define VROTL_3D "r18"
#define VROTR_3D "r19"

#define VCUSTOM_3D   "r20"
#define VCUSTOM0_3D  "r20"
#define VCUSTOM1_3D  "r21"
#define VCUSTOM2_3D  "r22"
#define VCUSTOM3_3D  "r23"

#define VCMV_LEZ_3D  "r24" // N | Z
#define VCMV_GTZ_3D  "r25" // ~N & ~Z
#define VCMV_LTZ_3D  "r26" // N
#define VCMV_FS_3D   "r26" // N
#define VCMV_GEZ_3D  "r27" // ~N
#define VCMV_FC_3D   "r27" // ~N
#define VCMV_Z_3D    "r28" // Z
#define VCMV_NZ_3D   "r29" // ~Z

#define VABSDIFF_3D  "r31"

// -------------------------------------

#define N_INSTR_A_B     "0"
#define N_INSTR_OP_DEST "1"

// -------------------------------------

#define _VBXASM __asm__ __volatile__

// VCMZ_GTZ_3D is encoded as r25 (aka bt) in custom instruction operand
// field. E.g.:
//   custom  0,c4,r7,r8
//   custom  1,c21,r6,bt
// r25/bt is meant to be "used exclusively by the JTAG debug module [..]
// as the breakpoint temporary" (Nios II Processor Reference Handbook), so
// get warnings like this:
//   {standard input}: Assembler messages:
//   {standard input}:4028: Warning: The debugger will corrupt bt (r25).
//   If you don't need to debug this code then use .set nobreak to turn off
//   this warning.
// These warnings can be safely ignored since bt is not actually used as a
// source or destination operand by the custom instruction. "set .nobreak"
// "allows assembly code to use ba and bt registers without warning."

#define VBX_ASM(MODIFIERS,VMODE,VINSTR,DEST,SRCA,SRCB) \
	VBX_S{ \
		_VBXASM ( ".set nobreak"); \
		_VBXASM ( "custom " N_INSTR_A_B     ", " MODIFIERS ", %0, %1"      : : "r" (SRCA), "r" (SRCB) ); \
		_VBXASM ( "custom " N_INSTR_OP_DEST ", " VMODE     ", %0, " VINSTR : : "r" (DEST) );	    \
		_VBXASM ( ".set break"); \
	}VBX_E

// -------------------------------------
// Vector API: Prototypes

#define _vbxasm(VMODE,VINSTR,DEST,SRCA,SRCB)            VBX_ASM(VMODE##_MOD_NONE,VMODE##_C,VINSTR##_I,DEST,SRCA,SRCB)
#define _vbxasm_acc(VMODE,VINSTR,DEST,SRCA,SRCB)        VBX_ASM(VMODE##_MOD_ACC,VMODE##_C,VINSTR##_I,DEST,SRCA,SRCB)
#define _vbxasm_2D(VMODE,VINSTR,DEST,SRCA,SRCB)         VBX_ASM(VMODE##_MOD_2D,VMODE##_C,VINSTR##_I,DEST,SRCA,SRCB)
#define _vbxasm_acc_2D(VMODE,VINSTR,DEST,SRCA,SRCB)     VBX_ASM(VMODE##_MOD_ACC_2D,VMODE##_C,VINSTR##_I,DEST,SRCA,SRCB)
#define _vbxasm_3D(VMODE,VINSTR,DEST,SRCA,SRCB)         VBX_ASM(VMODE##_MOD_2D,VMODE##_C,VINSTR##_3D,DEST,SRCA,SRCB)
#define _vbxasm_acc_3D(VMODE,VINSTR,DEST,SRCA,SRCB)     VBX_ASM(VMODE##_MOD_ACC_2D,VMODE##_C,VINSTR##_3D,DEST,SRCA,SRCB)

// NOTE: the double-macro calling is required to ensure macro arguments are fully expanded.
#define vbxasm(VMODE,VINSTR,DEST,SRCA,SRCB)             _vbxasm(VMODE,VINSTR,DEST,SRCA,SRCB)
#define vbxasm_acc(VMODE,VINSTR,DEST,SRCA,SRCB)         _vbxasm_acc(VMODE,VINSTR,DEST,SRCA,SRCB)
#define vbxasm_2D(VMODE,VINSTR,DEST,SRCA,SRCB)          _vbxasm_2D(VMODE,VINSTR,DEST,SRCA,SRCB)
#define vbxasm_acc_2D(VMODE,VINSTR,DEST,SRCA,SRCB)      _vbxasm_acc_2D(VMODE,VINSTR,DEST,SRCA,SRCB)
#define vbxasm_3D(VMODE,VINSTR,DEST,SRCA,SRCB)          _vbxasm_3D(VMODE,VINSTR,DEST,SRCA,SRCB)
#define vbxasm_acc_3D(VMODE,VINSTR,DEST,SRCA,SRCB)      _vbxasm_acc_3D(VMODE,VINSTR,DEST,SRCA,SRCB)

#endif // VBX_ASSEMBLER
#endif // __VBX_ASM_OR_SIM_H

#ifdef __cplusplus
}
#endif

#endif // __VBX_ASM_NIOS_H
/**@}*/
