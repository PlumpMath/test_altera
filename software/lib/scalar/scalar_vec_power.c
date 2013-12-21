#include "scalar_vec_power.h"

static inline uint32_t power_uword( uint32_t a, uint32_t b )
{
	//int32_t sgn = (b<0);
	int32_t result = 1;
	int32_t aa     = a;
	b   = abs(b);
	while( b ) {
		if( b&1 ) result *= aa;
		aa = aa * aa;
		b = b >> 1;
	}
	//if( sgn )
	//	result = 1./result;
	return result;
}

static inline uint16_t power_uhalf( uint16_t a, uint16_t b )
{
	//int16_t sgn = (b<0);
	int16_t result = 1;
	int16_t aa     = a;
	b   = abs(b);
	while( b ) {
		if( b&1 ) result *= aa;
		aa = aa * aa;
		b = b >> 1;
	}
	//if( sgn )
	//	result = 1./result;
	return result;
}

static inline uint8_t power_ubyte( uint8_t a, uint8_t b )
{
	//int8_t sgn = (b<0);
	int8_t result = 1;
	int8_t aa     = a;
	b   = abs(b);
	while( b ) {
		if( b&1 ) result *= aa;
		aa = aa * aa;
		b = b >> 1;
	}
	//if( sgn )
	//	result = 1./result;
	return result;
}

static inline int32_t power_word( int32_t a, int32_t b )
{
	//int32_t sgn = (b<0);
	int32_t result = 1;
	int32_t aa     = a;
	b   = abs(b);
	while( b ) {
		if( b&1 ) result *= aa;
		aa = aa * aa;
		b = b >> 1;
	}
	//if( sgn )
	//	result = 1./result;
	return result;
}

static inline int16_t power_half( int16_t a, int16_t b )
{
	//int16_t sgn = (b<0);
	int16_t result = 1;
	int16_t aa     = a;
	b   = abs(b);
	while( b ) {
		if( b&1 ) result *= aa;
		aa = aa * aa;
		b = b >> 1;
	}
	//if( sgn )
	//	result = 1./result;
	return result;
}

static inline int8_t power_byte( int8_t a, int8_t b )
{
	//int8_t sgn = (b<0);
	int8_t result = 1;
	int8_t aa     = a;
	b   = abs(b);
	while( b ) {
		if( b&1 ) result *= aa;
		aa = aa * aa;
		b = b >> 1;
	}
	//if( sgn )
	//	result = 1./result;
	return result;
}

void scalar_vec_power_byte(int8_t *output, int8_t *input1, int8_t *input2, const int N)
{
    int i;
    for(i=0; i<N; i++){
        output[i] = power_byte(input1[i],input2[i]);

    }
}

void scalar_vec_power_half(int16_t *output, int16_t *input1, int16_t *input2, const int N)
{
    int i;
    for(i=0; i<N; i++){
        output[i] = power_half(input1[i],input2[i]);

    }
}

void scalar_vec_power_word(int32_t *output, int32_t *input1, int32_t *input2, const int N)
{
    int i;
    for(i=0; i<N; i++){
        output[i] = power_word(input1[i],input2[i]);

    }
}

void scalar_vec_power_ubyte(uint8_t *output, uint8_t *input1, uint8_t *input2, const int N)
{
    int i;
    for(i=0; i<N; i++){
        output[i] = power_ubyte(input1[i],input2[i]);

    }
}

void scalar_vec_power_uhalf(uint16_t *output, uint16_t *input1, uint16_t *input2, const int N)
{
    int i;
    for(i=0; i<N; i++){
        output[i] = power_uhalf(input1[i],input2[i]);

    }
}

void scalar_vec_power_uword(uint32_t *output, uint32_t *input1, uint32_t *input2, const int N)
{
    int i;
    for(i=0; i<N; i++){
        output[i] = power_uword(input1[i],input2[i]);

    }
}
