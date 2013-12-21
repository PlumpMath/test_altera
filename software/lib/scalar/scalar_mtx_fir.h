/**@file*/
/**@{*/

#ifndef __SCALAR_MTX_FIR_H
#define __SCALAR_MTX_FIR_H
#include <stdint.h>

void scalar_mtx_2Dfir_byte( int8_t *output, int8_t *input, const int32_t *coeffs, const int num_row, const int num_column, const int ntaps_row, const int ntaps_column );

void scalar_mtx_2Dfir_half( int16_t *output, int16_t *input, const int32_t *coeffs, const int num_row, const int num_column, const int ntaps_row, const int ntaps_column );

void scalar_mtx_2Dfir_word( int32_t *output, int32_t *input, const int32_t *coeffs, const int num_row, const int num_column, const int ntaps_row, const int ntaps_column );

void scalar_mtx_2Dfir_ubyte( uint8_t *output, uint8_t *input, const uint32_t *coeffs, const int num_row, const int num_column, const int ntaps_row, const int ntaps_column );

void scalar_mtx_2Dfir_uhalf( uint16_t *output, uint16_t *input, const uint32_t *coeffs, const int num_row, const int num_column, const int ntaps_row, const int ntaps_column );

void scalar_mtx_2Dfir_uword( uint32_t *output, uint32_t *input, const uint32_t *coeffs, const int num_row, const int num_column, const int ntaps_row, const int ntaps_column );

#endif // __SCALAR_MTX_FIR_H
/**@}*/
