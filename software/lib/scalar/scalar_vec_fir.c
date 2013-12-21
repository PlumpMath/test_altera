#include "scalar_vec_fir.h"

// Scalar FIR filter byte
void scalar_vec_fir_byte(int8_t *output, int8_t *input, const int8_t *const coeffs, const int32_t sample_size, const int32_t num_taps)
{
	int32_t i, j;

	for (j = 0; j <= (sample_size - num_taps); j++) {
		*output = 0;
		for (i = 0; i < num_taps; i++) {
			*output += input[i] * coeffs[i];
		}
		output++;
		input++;
	}
}

// Scalar FIR filter half
void scalar_vec_fir_half(int16_t *output, int16_t *input, const int16_t *const coeffs, const int32_t sample_size, const int32_t num_taps)
{
	int32_t i, j;

	for (j = 0; j <= (sample_size - num_taps); j++) {
		*output = 0;
		for (i = 0; i < num_taps; i++) {
			*output += input[i] * coeffs[i];
		}
		output++;
		input++;
	}
}

// Scalar FIR filter word
void scalar_vec_fir_word(int32_t *output, int32_t *input, const int32_t *const coeffs, const int32_t sample_size, const int32_t num_taps)
{
	int32_t i, j;

	for (j = 0; j <= (sample_size - num_taps); j++) {
		*output = 0;
		for (i = 0; i < num_taps; i++) {
			*output += input[i] * coeffs[i];
		}
		output++;
		input++;
	}
}
// Scalar FIR filter unsigned byte
void scalar_vec_fir_ubyte(uint8_t *output, uint8_t *input, const uint8_t *const coeffs, const int32_t sample_size, const int32_t num_taps)
{
	int32_t i, j;

	for (j = 0; j <= (sample_size - num_taps); j++) {
		*output = 0;
		for (i = 0; i < num_taps; i++) {
			*output += input[i] * coeffs[i];
		}
		output++;
		input++;
	}
}

// Scalar FIR filter unsigned half
void scalar_vec_fir_uhalf(uint16_t *output, uint16_t *input, const uint16_t *const coeffs, const int32_t sample_size, const int32_t num_taps)
{
	int32_t i, j;

	for (j = 0; j <= (sample_size - num_taps); j++) {
		*output = 0;
		for (i = 0; i < num_taps; i++) {
			*output += input[i] * coeffs[i];
		}
		output++;
		input++;
	}
}

// Scalar FIR filter unsigned word
void scalar_vec_fir_uword(uint32_t *output, uint32_t *input, const uint32_t *const coeffs, const int32_t sample_size, const int32_t num_taps)
{
	int32_t i, j;

	for (j = 0; j <= (sample_size - num_taps); j++) {
		*output = 0;
		for (i = 0; i < num_taps; i++) {
			*output += input[i] * coeffs[i];
		}
		output++;
		input++;
	}
}
