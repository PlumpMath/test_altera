#ifndef __SCALAR_VEC_REV_H
#define __SCALAR_VEC_REV_H
#include <stdint.h>

void scalar_vec_rev_byte(uint8_t *output, uint8_t *input, const int32_t N);

void scalar_vec_rev_half(uint16_t *output, uint16_t *input, const int32_t N);

void scalar_vec_rev_word(uint32_t *output, uint32_t *input, const int32_t N);

#endif //__SCALAR_VEC_REV_H
