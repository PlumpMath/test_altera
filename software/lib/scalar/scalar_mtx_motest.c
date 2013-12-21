/**@file*/

#include "scalar_mtx_motest.h"

/**Scalar Motion Estimation.
 * Motion estimation.  Scan the block to be estimated over the image,
 * at each location calculating the SAD of the block and the reference image
 *
 * @param[in] x.
 * @param[in] y.
 * @param[out] result.
 */
void scalar_mtx_motest_byte(uint32_t *result, uint8_t *x, uint8_t *y, const int32_t search_height, const int32_t search_width, const int32_t block_height, const int32_t block_width, const int32_t image_width)
{
	int32_t i, j, k, l;
	uint32_t answer;
	uint8_t *x_line;
	uint8_t *y_line;

	for( l=0; l<search_height; l++ ) {
		for( k=0; k<search_width; k++ ) {
			answer = 0;
			for( j=0; j<block_height; j++ ) {
				x_line = x + ( image_width*j );
				y_line = y + ( image_width*(l+j)+k );
				for( i=0; i<block_width; i++ ) {
					answer += abs( *(x_line++) - *(y_line++) );
				}
			}
			result[l*search_width+k] = answer;
		}
	}
}
