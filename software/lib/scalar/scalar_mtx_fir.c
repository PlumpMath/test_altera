/**@file*/
#include "scalar_mtx_fir.h"

/** 2D FIR filter scalar byte.
 *	Scan through the input multiplying
 * 	and accumulating with the filter
 *
 * @param[in] input.
 * @param[out] output.
 * @param[in] coeffs.
 * @param[in] num_row.
 * @param[in] num_column.
 * @param[in] ntaps_row.
 * @param[in] ntaps_column.
 *
 */
void scalar_mtx_2Dfir_byte(
		int8_t *output, int8_t *input, const int32_t *coeffs,
		const int num_row, const int num_column, const int ntaps_row, const int ntaps_column )
{
	int l,k,j,i;
	int32_t temp1, temp2;
	for( l = 0 ; l < num_row-ntaps_row; l++) {
		for( k = 0; k < num_column-ntaps_column; k++) {
			temp1 = 0;
			for( j = 0; j < ntaps_row; j++) {
				temp2 = 0;
				for( i = 0; i < ntaps_column; i++) {
					temp2 += input[(l+j)*num_column+(k+i)] * coeffs[j*ntaps_column+i];
				}
				temp1 += temp2;
			}
			output[l*num_column+k] = temp1 >> 8;
		}
	}
}

/** 2D FIR filter scalar half.
 *	Scan through the input multiplying
 * 	and accumulating with the filter
 *
 * @param[in] input.
 * @param[out] output.
 * @param[in] coeffs.
 * @param[in] num_row.
 * @param[in] num_column.
 * @param[in] ntaps_row.
 * @param[in] ntaps_column.
 *
 */
void scalar_mtx_2Dfir_half(
		int16_t *output, int16_t *input, const int32_t *coeffs,
		const int num_row, const int num_column, const int ntaps_row, const int ntaps_column )
{
	int l,k,j,i;
	int32_t temp1, temp2;
	for( l = 0 ; l < num_row-ntaps_row; l++) {
		for( k = 0; k < num_column-ntaps_column; k++) {
			temp1 = 0;
			for( j = 0; j < ntaps_row; j++) {
				temp2 = 0;
				for( i = 0; i < ntaps_column; i++) {
					temp2 += input[(l+j)*num_column+(k+i)] * coeffs[j*ntaps_column+i];
				}
				temp1 += temp2;
			}
			output[l*num_column+k] = temp1 >> 8;
		}
	}
}

/** 2D FIR filter scalar word.
 *	Scan through the input multiplying
 * 	and accumulating with the filter
 *
 * @param[in] input.
 * @param[out] output.
 * @param[in] coeffs.
 * @param[in] num_row.
 * @param[in] num_column.
 * @param[in] ntaps_row.
 * @param[in] ntaps_column.
 *
 */
void scalar_mtx_2Dfir_word(
		int32_t *output, int32_t *input, const int32_t *coeffs,
		const int num_row, const int num_column, const int ntaps_row, const int ntaps_column )
{
	int l,k,j,i;
	int32_t temp1, temp2;
	for( l = 0 ; l < num_row-ntaps_row; l++) {
		for( k = 0; k < num_column-ntaps_column; k++) {
			temp1 = 0;
			for( j = 0; j < ntaps_row; j++) {
				temp2 = 0;
				for( i = 0; i < ntaps_column; i++) {
					temp2 += input[(l+j)*num_column+(k+i)] * coeffs[j*ntaps_column+i];
				}
				temp1 += temp2;
			}
			output[l*num_column+k] = temp1 >> 8;
		}
	}
}

/** 2D FIR filter scalar byte.
 *	Scan through the input multiplying
 * 	and accumulating with the filter
 *
 * @param[in] input.
 * @param[out] output.
 * @param[in] coeffs.
 * @param[in] num_row.
 * @param[in] num_column.
 * @param[in] ntaps_row.
 * @param[in] ntaps_column.
 *
 */
void scalar_mtx_2Dfir_ubyte(
		uint8_t *output, uint8_t *input, const uint32_t *coeffs,
		const int num_row, const int num_column, const int ntaps_row, const int ntaps_column )
{
	int l,k,j,i;
	uint32_t temp1, temp2;
	for( l = 0 ; l < num_row-ntaps_row; l++) {
		for( k = 0; k < num_column-ntaps_column; k++) {
			temp1 = 0;
			for( j = 0; j < ntaps_row; j++) {
				temp2 = 0;
				for( i = 0; i < ntaps_column; i++) {
					temp2 += input[(l+j)*num_column+(k+i)] * coeffs[j*ntaps_column+i];
				}
				temp1 += temp2;
			}
			output[l*num_column+k] = temp1 >> 8;
		}
	}
}

/** 2D FIR filter scalar half.
 *	Scan through the input multiplying
 * 	and accumulating with the filter
 *
 * @param[in] input.
 * @param[out] output.
 * @param[in] coeffs.
 * @param[in] num_row.
 * @param[in] num_column.
 * @param[in] ntaps_row.
 * @param[in] ntaps_column.
 *
 */
void scalar_mtx_2Dfir_uhalf(
		uint16_t *output, uint16_t *input, const uint32_t *coeffs,
		const int num_row, const int num_column, const int ntaps_row, const int ntaps_column )
{
	int l,k,j,i;
	uint32_t temp1, temp2;
	for( l = 0 ; l < num_row-ntaps_row; l++) {
		for( k = 0; k < num_column-ntaps_column; k++) {
			temp1 = 0;
			for( j = 0; j < ntaps_row; j++) {
				temp2 = 0;
				for( i = 0; i < ntaps_column; i++) {
					temp2 += input[(l+j)*num_column+(k+i)] * coeffs[j*ntaps_column+i];
				}
				temp1 += temp2;
			}
			output[l*num_column+k] = temp1 >> 8;
		}
	}
}

/** 2D FIR filter scalar word.
 *	Scan through the input multiplying
 * 	and accumulating with the filter
 *
 * @param[in] input.
 * @param[out] output.
 * @param[in] coeffs.
 * @param[in] num_row.
 * @param[in] num_column.
 * @param[in] ntaps_row.
 * @param[in] ntaps_column.
 *
 */
void scalar_mtx_2Dfir_uword(
		uint32_t *output, uint32_t *input, const uint32_t *coeffs,
		const int num_row, const int num_column, const int ntaps_row, const int ntaps_column )
{
	int l,k,j,i;
	uint32_t temp1, temp2;
	for( l = 0 ; l < num_row-ntaps_row; l++) {
		for( k = 0; k < num_column-ntaps_column; k++) {
			temp1 = 0;
			for( j = 0; j < ntaps_row; j++) {
				temp2 = 0;
				for( i = 0; i < ntaps_column; i++) {
					temp2 += input[(l+j)*num_column+(k+i)] * coeffs[j*ntaps_column+i];
				}
				temp1 += temp2;
			}
			output[l*num_column+k] = temp1 >> 8;
		}
	}
}

/**@}*/
