/**@file*/
//VBXCOPYRIGHTTAG

// DO NOT ADD #ifdef WRAPPER TO THIS HEADER FILE
// This file should NOT be protected from multiple #includes.

#include "vbw_template_t.h"

void VBX_T(vbw_vec_fir_1d)(vbx_mm_t *output, vbx_mm_t *input, vbx_mm_t *coeffs, const int sample_size, const int num_taps);

void VBX_T(vbw_vec_fir_2d)(vbx_mm_t *output, vbx_mm_t *input, vbx_mm_t *coeffs, const int sample_size, const int num_taps);

void VBX_T(vbw_vec_fir_transpose)(vbx_mm_t *output, vbx_mm_t *input, vbx_mm_t *coeffs, const int sample_size, const int num_taps);

