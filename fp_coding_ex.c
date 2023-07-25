#include <stdio.h>
#include <string.h>

/* use typedef so that an unsigned value becomes the bits for a
  hypothetical floting point representation
 */
typedef unsigned float_bits;

typedef unsigned char *byte_pointer;  //from original show_bytes activity


/*
 * This fnction takes an unsigned value and checks to see if its
 * binary form represents a normalized or denormalized floating
 * point number.
 * paramter: f   is a 32-bit representation of some IEEE single precision number
 *
 * returns: an unsigned value that is  +/-0  if f is a denormalized number
 *          OR returns f itself if it is a normalized number
 */
float_bits float_denorn_zero(float_bits f) {
  /* Decompose bit representation into parts */
  unsigned sign = f>>31;
  unsigned exp =  f>>23 & 0xFF;
  unsigned frac = f     & 0x7FFFFF;

  if (exp == 0) {  // denormalized
    frac = 0;
  }

  return (sign << 31) | (exp << 23) | frac ;
}

// TODO: Write a function similar to float_denorn_zero
// to check if a number is infinity or NaN


/* Compute -f. If f is NaN, then return f. */
float_bits float_negate(float_bits f) {

  // TODO: complete this by replacing the code below with code that negates f

  unsigned neg = f; //replace this line

  return neg;
}
