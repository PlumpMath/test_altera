#ifndef __SCALAR_VEC_COPY_H
#define __SCALAR_VEC_COPY_H
#include <stdint.h>

void scalar_vec_copy_ubyte(uint8_t *output, uint8_t *input, const int N);
void scalar_vec_copy_uhalf(uint16_t *output, uint16_t *input, const int N);
void scalar_vec_copy_uword(uint32_t *output, uint32_t *input, const int N);
void scalar_vec_copy_byte(int8_t *output, int8_t *input, const int N);
void scalar_vec_copy_half(int16_t *output, int16_t *input, const int N);
void scalar_vec_copy_word(int32_t *output, int32_t *input, const int N);

#endif //__SCALAR_VEC_COPY_H
