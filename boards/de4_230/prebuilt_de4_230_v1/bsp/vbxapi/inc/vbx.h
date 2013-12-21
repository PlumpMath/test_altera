/**
 * @file
 * @defgroup VBX
 * @brief Main file to include in programs
 *
 * @ingroup VBXapi
 *
 * ####Includes
 * * @ref vbx_types.h
 * * @ref vbx_extern.h
 * * @ref vbx_macros.h
 * * @ref vbx_asm_or_sim.h
 * * @ref vbx_api.h
 * * @ref vbx_lib.h
 * * @ref vbx_cproto.h
 * * @ref vbxx.hpp
 *
 */
/**@{*/
//VBXCOPYRIGHTTAG

#ifndef __VBX_H
#define __VBX_H

#ifdef __cplusplus
extern "C" {
#endif

//#include <system.h>
#include <stddef.h>


// The order below must not be altered
#include "vbx_types.h"
#include "vbx_extern.h"
#include "vbx_macros.h"

#include "vbx_asm_or_sim.h"

#include "vbx_api.h"
#include "vbx_lib.h"

#include "vbx_cproto.h"

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include "vbxx.hpp"
#endif

#endif //__VBX_H
/**@}*/
