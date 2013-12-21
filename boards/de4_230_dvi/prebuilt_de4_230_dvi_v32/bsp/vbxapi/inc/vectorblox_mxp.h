/**
 * @file
 * @defgroup VectorBlox_MXP
 * @brief Details the instance of our VectorBlox MXP processor
 *
 * @ingroup VBXapi 
 */
/**@{*/
//VBXCOPYRIGHTTAG

#ifndef __VECTORBLOX_MXP_H
#define __VECTORBLOX_MXP_H

#ifdef __cplusplus
extern "C" {
#endif

#if __NIOS2__
#include "vectorblox_mxp_nios.h"
#else
#include "vectorblox_mxp_xil.h"
#endif

#ifdef __cplusplus
}
#endif

#endif //__VECTORBLOX_MXP_H
/**@}*/
