#include "scalar_vec_copy.h"

// Scalar reverse byte
void scalar_vec_copy_ubyte(uint8_t *output, uint8_t *input, const int N)
{
	int i;
    for (i = 0; i < N; i++) {
        output[i]=input[i];
	}
}

// Scalar reverse half
void scalar_vec_copy_uhalf(uint16_t *output, uint16_t *input, const int N)
{
	int i;
    for (i = 0; i < N; i++) {
        output[i]=input[i];
	}
}

// Scalar reverse word
void scalar_vec_copy_uword(uint32_t *output, uint32_t *input, const int N)
{
	int i;
    for (i = 0; i < N; i++) {
        output[i]=input[i];
	}
}

void scalar_vec_copy_byte(int8_t *output, int8_t *input, const int N)
{
    scalar_vec_copy_ubyte((uint8_t *)output, (uint8_t *)input, N);
}

void scalar_vec_copy_half(int16_t *output, int16_t *input, const int N)
{
    scalar_vec_copy_uhalf((uint16_t *)output, (uint16_t *)input, N);
}

void scalar_vec_copy_word(int32_t *output, int32_t *input, const int N)
{
    scalar_vec_copy_uword((uint32_t *)output, (uint32_t *)input, N);
}

