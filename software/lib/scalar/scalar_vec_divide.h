#ifndef __SCALAR_VEC_DIVIDE_H
#define __SCALAR_VEC_DIVIDE_H

#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define RANGE  UINT_MAX

void scalar_vec_divide_byte(int8_t *output, int8_t *remainder, int8_t *input1, int8_t *input2, const int N);
void scalar_vec_divide_half(int16_t *output, int16_t *remainder, int16_t *input1, int16_t *input2, const int N);
void scalar_vec_divide_word(int32_t *output, int32_t *remainder, int32_t *input1, int32_t *input2, const int N);
void scalar_vec_divide_ubyte(uint8_t *output, uint8_t *remainder, uint8_t *input1, uint8_t *input2, const int N);
void scalar_vec_divide_uhalf(uint16_t *output, uint16_t *remainder,  uint16_t *input1, uint16_t *input2, const int N);
void scalar_vec_divide_uword(uint32_t *output, uint32_t *remainder, uint32_t *input1, uint32_t *input2, const int N);

#endif //__SCALAR_VEC_DIVIDE_H
