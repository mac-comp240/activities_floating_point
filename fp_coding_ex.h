/*
 *  This is an example for bit-level encoding of floats
 */

/* use typedef so that an unsigned value becomes the bits for a
  hypothetical floting point representation
 */
typedef unsigned float_bits;

typedef unsigned char *byte_pointer;  //from original show_bytes activity

float_bits float_denorn_zero(float_bits f);
float_bits float_negate(float_bits f);
void show_bytes(byte_pointer start, int len);
void show_float(float x);
void binary(unsigned int input, char* result);
