/**@file*/
#include "scalar_mtx_xp.h"

/** Scalar Matrix Transpose Byte
 * Assumes in != out
 *
 * @param[out] out.
 * @param[in] in.
 * @param[in] INROWS.
 * @param[in] INCOLS.
 */
void scalar_mtx_xp_MN_byte(int8_t *out, int8_t *in, const int32_t INROWS, const int32_t INCOLS)
{
	int32_t i,j;
	for(j = 0; j < INROWS; j++){
		//print32_tf( "\nj:%d\n", j ); fflush(stdout);
		for(i = 0; i < INCOLS; i++){
			//print32_tf( "i:%d ", i ); fflush(stdout);
			out[i*INROWS+j] = in[j*INCOLS+i];
		}
	}
}

/** Scalar Matrix Transpose Half
 * Assumes in != out
 *
 * @param[out] out.
 * @param[in] in.
 * @param[in] INROWS.
 * @param[in] INCOLS.
 */
void scalar_mtx_xp_MN_half(int16_t *out, int16_t *in, const int32_t INROWS, const int32_t INCOLS)
{
	int32_t i,j;
	for(j = 0; j < INROWS; j++){
		//print32_tf( "\nj:%d\n", j ); fflush(stdout);
		for(i = 0; i < INCOLS; i++){
			//print32_tf( "i:%d ", i ); fflush(stdout);
			out[i*INROWS+j] = in[j*INCOLS+i];
		}
	}
}

/** Scalar Matrix Transpose Word
 * Assumes in != out
 *
 * @param[out] out.
 * @param[in] in.
 * @param[in] INROWS.
 * @param[in] INCOLS.
 */
void scalar_mtx_xp_MN_word(int32_t *out, int32_t *in, const int32_t INROWS, const int32_t INCOLS)
{
	int32_t i,j;
	for(j = 0; j < INROWS; j++){
		//print32_tf( "\nj:%d\n", j ); fflush(stdout);
		for(i = 0; i < INCOLS; i++){
			//print32_tf( "i:%d ", i ); fflush(stdout);
			out[i*INROWS+j] = in[j*INCOLS+i];
		}
	}
}

/** Scalar Matrix Transpose Unsigned Byte
 * Assumes in != out
 *
 * @param[out] out.
 * @param[in] in.
 * @param[in] INROWS.
 * @param[in] INCOLS.
 */
void scalar_mtx_xp_MN_ubyte(uint8_t *out, uint8_t *in, const int32_t INROWS, const int32_t INCOLS)
{
	int32_t i,j;
	for(j = 0; j < INROWS; j++){
		//print32_tf( "\nj:%d\n", j ); fflush(stdout);
		for(i = 0; i < INCOLS; i++){
			//print32_tf( "i:%d ", i ); fflush(stdout);
			out[i*INROWS+j] = in[j*INCOLS+i];
		}
	}
}

/** Scalar Matrix Transpose Unsigned Half
 * Assumes in != out
 *
 * @param[out] out.
 * @param[in] in.
 * @param[in] INROWS.
 * @param[in] INCOLS.
 */
void scalar_mtx_xp_MN_uhalf(uint16_t *out, uint16_t *in, const int32_t INROWS, const int32_t INCOLS)
{
	int32_t i,j;
	for(j = 0; j < INROWS; j++){
		//print32_tf( "\nj:%d\n", j ); fflush(stdout);
		for(i = 0; i < INCOLS; i++){
			//print32_tf( "i:%d ", i ); fflush(stdout);
			out[i*INROWS+j] = in[j*INCOLS+i];
		}
	}
}

/** Scalar Matrix Transpose Unsigned Word
 * Assumes in != out
 *
 * @param[out] out.
 * @param[in] in.
 * @param[in] INROWS.
 * @param[in] INCOLS.
 */
void scalar_mtx_xp_MN_uword(uint32_t *out, uint32_t *in, const int32_t INROWS, const int32_t INCOLS)
{
	int32_t i,j;
	for(j = 0; j < INROWS; j++){
		//print32_tf( "\nj:%d\n", j ); fflush(stdout);
		for(i = 0; i < INCOLS; i++){
			//print32_tf( "i:%d ", i ); fflush(stdout);
			out[i*INROWS+j] = in[j*INCOLS+i];
		}
	}
}
