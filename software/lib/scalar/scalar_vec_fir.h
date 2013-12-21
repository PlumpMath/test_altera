#ifndef __SCALAR_VEC_FIR_H
#define __SCALAR_VEC_FIR_H
#include <stdint.h>

void scalar_vec_fir_byte(int8_t *output, int8_t *input, const int8_t *const coeffs, const int32_t sample_size, const int32_t num_taps);

void scalar_vec_fir_half(int16_t *output, int16_t *input, const int16_t *const coeffs, const int32_t sample_size, const int32_t num_taps);

void scalar_vec_fir_word(int32_t *output, int32_t *input, const int32_t *const coeffs, const int32_t sample_size, const int32_t num_taps);

void scalar_vec_fir_ubyte(uint8_t *output, uint8_t *input, const uint8_t *const coeffs, const int32_t sample_size, const int32_t num_taps);

void scalar_vec_fir_uhalf(uint16_t *output, uint16_t *input, const uint16_t *const coeffs, const int32_t sample_size, const int32_t num_taps);

void scalar_vec_fir_uword(uint32_t *output, uint32_t *input, const uint32_t *const coeffs, const int32_t sample_size, const int32_t num_taps);

#endif //__SCALAR_VEC_FIR_H
