/**
 * @file
 * @defgroup VBX_ASM_or_sim
 * @brief Included proper headers depending if running simulator or not
 *
 * @ingroup VBXapi
 */
/**@{*/
//VBXCOPYRIGHTTAG

#ifndef __VBX_ASM_OR_SIM_H
#define __VBX_ASM_OR_SIM_H

#ifdef __cplusplus
extern "C" {
#endif

// So you don't always have to define VBX_ASSEMBLER.
#ifdef VBX_ASSEMBLER
 /** VBX_ASSEMBLER is defined. it takes priority. */
 #undef  VBX_ASSEMBLER
 #define VBX_ASSEMBLER 1
 #define VBX_SIMULATOR 0
#else
 #ifdef VBX_SIMULATOR
  /** VBX_SIMULATOR is defined. */
  #undef  VBX_SIMULATOR
  #define VBX_ASSEMBLER 0
  #define VBX_SIMULATOR 1
 #else
  /** Neither VBX_ASSEMBLER or VBX_SIMULATOR are defined. Defaults to assembler. */
  #define VBX_ASSEMBLER 1
  #define VBX_SIMULATOR 0
 #endif
#endif

// NB: the assembler and the simulator are mutually exclusive
#if (VBX_ASSEMBLER && VBX_SIMULATOR)
#error "Configuration error. Cannot use both assembler and simulator at the same time."
#endif

// Include the assembler
#if VBX_ASSEMBLER
#if __NIOS2__
#include "vbx_asm_nios.h"
#elif __MICROBLAZE__
#include "vbx_asm_mb.h"
#elif __ARM_ARCH_7A__
#include "vbx_asm_arm.h"
#endif
#endif

// Include the simulator
#if VBX_SIMULATOR
#include "vbx_sim.h"
#endif

#ifdef __cplusplus
}
#endif

#endif //__VBX_ASM_OR_SIM_H
/**@}*/
