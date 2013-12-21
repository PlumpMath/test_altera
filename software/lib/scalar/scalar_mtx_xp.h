/**@file*/
/**@{*/

#ifndef __SCALAR_MTX_XP_H
#define __SCALAR_MTX_XP_H

#include <stdio.h>
#include <stdint.h>

void scalar_mtx_xp_MN_byte(int8_t *out, int8_t *in, const int32_t INROWS, const int32_t INCOLS);

void scalar_mtx_xp_MN_half(int16_t *out, int16_t *in, const int32_t INROWS, const int32_t INCOLS);

void scalar_mtx_xp_MN_word(int32_t *out, int32_t *in, const int32_t INROWS, const int32_t INCOLS);

void scalar_mtx_xp_MN_ubyte(uint8_t *out, uint8_t *in, const int32_t INROWS, const int32_t INCOLS);

void scalar_mtx_xp_MN_uhalf(uint16_t *out, uint16_t *in, const int32_t INROWS, const int32_t INCOLS);

void scalar_mtx_xp_MN_uword(uint32_t *out, uint32_t *in, const int32_t INROWS, const int32_t INCOLS);

#endif // __SCALAR_MTX_XP_H
/**@}*/
