/**@file*/
/**@{*/

#ifndef __SCALAR_MTX_MEDIAN_H
#define __SCALAR_MTX_MEDIAN_H
#include <stdint.h>

int8_t scalar_bubble_byte(int8_t *array, const int32_t filter_size);
int16_t scalar_bubble_half(int16_t *array, const int32_t filter_size);
int32_t scalar_bubble_word(int32_t *array, const int32_t filter_size);
uint8_t scalar_bubble_ubyte(uint8_t *array, const int32_t filter_size);
uint16_t scalar_bubble_uhalf(uint16_t *array, const int32_t filter_size);
uint32_t scalar_bubble_uword(uint32_t *array, const int32_t filter_size);

void scalar_mtx_median_byte(int8_t *output, int8_t *input, const int32_t filter_size, const int32_t filter_height, const int32_t filter_width, const int32_t image_height, const int32_t image_width);

void scalar_mtx_median_half(int16_t *output, int16_t *input, const int32_t filter_size, const int32_t filter_height, const int32_t filter_width, const int32_t image_height, const int32_t image_width);

void scalar_mtx_median_word(int32_t *output, int32_t *input, const int32_t filter_size, const int32_t filter_height, const int32_t filter_width, const int32_t image_height, const int32_t image_width);

void scalar_mtx_median_ubyte(uint8_t *output, uint8_t *input, const int32_t filter_size, const int32_t filter_height, const int32_t filter_width, const int32_t image_height, const int32_t image_width);

void scalar_mtx_median_uhalf(uint16_t *output, uint16_t *input, const int32_t filter_size, const int32_t filter_height, const int32_t filter_width, const int32_t image_height, const int32_t image_width);

void scalar_mtx_median_uword(uint32_t *output, uint32_t *input, const int32_t filter_size, const int32_t filter_height, const int32_t filter_width, const int32_t image_height, const int32_t image_width);

#endif // __SCALAR_MTX_MEDIAN_H
/**@}*/
