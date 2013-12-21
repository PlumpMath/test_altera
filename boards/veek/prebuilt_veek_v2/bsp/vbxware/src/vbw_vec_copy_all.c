/**@file*/
//VBXCOPYRIGHTTAG

#include "vbx_copyright.h"
VBXCOPYRIGHT( vbw_vec_copy )

#include "vbx.h"

// Now, include the C file six times
// First three for byte, half, word
// Next three for ubyte, uhalf, uword

#ifdef VBX_TEMPLATE_T
#undef VBX_TEMPLATE_T
#endif

#define VBX_TEMPLATE_T VBX_BYTESIZE_DEF
#include "vbw_vec_copy_t.c"

#undef VBX_TEMPLATE_T
#define VBX_TEMPLATE_T VBX_HALFSIZE_DEF
#include "vbw_vec_copy_t.c"

#undef VBX_TEMPLATE_T
#define VBX_TEMPLATE_T VBX_WORDSIZE_DEF
#include "vbw_vec_copy_t.c"

#undef VBX_TEMPLATE_T
#define VBX_TEMPLATE_T VBX_UBYTESIZE_DEF
#include "vbw_vec_copy_t.c"

#undef VBX_TEMPLATE_T
#define VBX_TEMPLATE_T VBX_UHALFSIZE_DEF
#include "vbw_vec_copy_t.c"

#undef VBX_TEMPLATE_T
#define VBX_TEMPLATE_T VBX_UWORDSIZE_DEF
#include "vbw_vec_copy_t.c"

