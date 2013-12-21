#include "scalar_vec_add.h"

// Scalar add byte
void scalar_vec_add_byte(int8_t *output, int8_t *input1, int8_t *input2, const int32_t N){
    int32_t i;
    for(i=0; i<N; i++){
        output[i] = input1[i] + input2[i];
    }
}

// Scalar add half
void scalar_vec_add_half(int16_t *output, int16_t *input1, int16_t *input2, const int32_t N){
    int32_t i;
    for(i=0; i<N; i++){
        output[i] = input1[i] + input2[i];
    }
}

// Scalar add word
void scalar_vec_add_word(int32_t *output, int32_t *input1, int32_t *input2, const int32_t N){
    int32_t i;
    for(i=0; i<N; i++){
        output[i] = input1[i] + input2[i];
    }
}

// Scalar add unsigned byte
void scalar_vec_add_ubyte(uint8_t *output, uint8_t *input1, uint8_t *input2, const int32_t N){
    int32_t i;
    for(i=0; i<N; i++){
        output[i] = input1[i] + input2[i];
    }
}

// Scalar add unsigned half
void scalar_vec_add_uhalf(uint16_t *output, uint16_t *input1, uint16_t *input2, const int32_t N){
    int32_t i;
    for(i=0; i<N; i++){
        output[i] = input1[i] + input2[i];
    }
}

// Scalar add unsigned word
void scalar_vec_add_uword(uint32_t *output, uint32_t *input1, uint32_t *input2, const int32_t N){
    int32_t i;
    for(i=0; i<N; i++){
        output[i] = input1[i] + input2[i];
    }
}
