/**
 * @file
 * @defgroup Matrix_Motion_Estimation
 * @brief Matrix Motion Estimation
 * @ingroup VBXware 
 */
/**@{*/
//VBXCOPYRIGHTTAG

#ifndef __VBX_MTX_MOTEST_H
#define __VBX_MTX_MOTEST_H

//
// Motion Estimation
// Scalar NIOS version and vbx VECTOR version
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "vbx.h"

#if 1 // BENCHMARK SETTINGS

#define BLOCK_HEIGHT  16
#define BLOCK_WIDTH   16
#define IMAGE_WIDTH   96
#define IMAGE_HEIGHT  96
#define SEARCH_WIDTH  16
#define SEARCH_HEIGHT 16

#else // TESTING SETTINGS

#define BLOCK_HEIGHT  16
#define BLOCK_WIDTH   16
#define IMAGE_WIDTH   256
#define IMAGE_HEIGHT  256
#define SEARCH_WIDTH  64
#define SEARCH_HEIGHT 64

#endif


#define BLOCK_SIZE    (BLOCK_WIDTH*BLOCK_HEIGHT)
#define IMAGE_SIZE    (IMAGE_WIDTH*IMAGE_HEIGHT)



typedef unsigned char  input_type;
typedef unsigned short intermediate_type;
typedef unsigned int   output_type;

//Don't need to pad up the dma length any more
//#define RESULT_SIZE (VBX_PAD_UP(SEARCH_WIDTH*SEARCH_HEIGHT*sizeof(output_type),this_mxp->dma_alignment_bytes))
#define RESULT_SIZE (SEARCH_WIDTH*SEARCH_HEIGHT*sizeof(output_type))

void vbw_mtx_motest_scalar_byte  (output_type *result, input_type *x, input_type *y);

int  vbw_mtx_motest_byte         (output_type *result, input_type *x, input_type *y);

int  vbw_mtx_motest_3d_byte      (output_type *result, input_type *x, input_type *y);

int  vbw_mtx_motest_byte_setup   ();

int  vbw_mtx_motest_3d_byte_setup();

#endif // __VBX_MTX_MOTEST_H
/**@}*/
