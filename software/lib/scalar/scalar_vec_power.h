#ifndef __SCALAR_VEC_POWER_H
#define __SCALAR_VEC_POWER_H

#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void scalar_vec_power_byte(int8_t *output, int8_t *input1, int8_t *input2, const int N);
void scalar_vec_power_half(int16_t *output, int16_t *input1, int16_t *input2, const int N);
void scalar_vec_power_word(int32_t *output, int32_t *input1, int32_t *input2, const int N);
void scalar_vec_power_ubyte(uint8_t *output, uint8_t *input1, uint8_t *input2, const int N);
void scalar_vec_power_uhalf(uint16_t *output, uint16_t *input1, uint16_t *input2, const int N);
void scalar_vec_power_uword(uint32_t *output, uint32_t *input1, uint32_t *input2, const int N);

#endif //__SCALAR_VEC_POWER_H
