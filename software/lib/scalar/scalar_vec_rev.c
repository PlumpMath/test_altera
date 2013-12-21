#include "scalar_vec_rev.h"

// Scalar reverse byte
void scalar_vec_rev_byte(uint8_t *output, uint8_t *input, const int32_t N)
{
	int32_t i;
    uint8_t tmp;
    for (i = 0; i < N/2; i++) {
        tmp = input[i];
        input[i]=input[N-1-i];
        input[N-1-i]=tmp;
	}
}

// Scalar reverse half
void scalar_vec_rev_half(uint16_t *output, uint16_t *input, const int32_t N)
{
	int32_t i;
    uint8_t tmp;
    for (i = 0; i < N/2; i++) {
        tmp = input[i];
        input[i]=input[N-1-i];
        input[N-1-i]=tmp;
	}
}

// Scalar reverse word
void scalar_vec_rev_word(uint32_t *output, uint32_t *input, const int32_t N)
{
	int32_t i;
    uint32_t tmp;
    for (i = 0; i < N/2; i++) {
        tmp = input[i];
        input[i]=input[N-1-i];
        input[N-1-i]=tmp;
	}
}
