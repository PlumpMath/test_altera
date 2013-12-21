/**@file*/
//VBXCOPYRIGHTTAG

// DO NOT ADD #ifdef WRAPPER TO THIS HEADER FILE
// This file should NOT be protected from multiple #includes.

#include "vbw_template_t.h"

void VBX_T(vbw_mtx_xp_square)(vbx_sp_t *v_dst, vbx_sp_t *v_src, const int INSIZE);

void VBX_T(vbw_mtx_xp)(vbx_sp_t *v_dst, vbx_sp_t *v_src, const int INROWS, const int INCOLS );

void VBX_T(vbw_mtx_xp_MN_ext)(vbx_mm_t *out, vbx_mm_t *in, const int INROWS, const int INCOLS );

void VBX_T(vbw_mtx_xp_NN_ext)(vbx_mm_t *out, vbx_mm_t *in, const int INSIZE );

