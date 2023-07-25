#include <stdio.h>
#include "fp_coding_ex.h"


int main() {
  float_bits value = 0;  //change this for testing, try more values

  // This is the example from the slides from class
  // 15213 in base 10 is 11101101101101 in base 2
  // This is 1.1101101101101  X  2 to the power 13
  // Therefore frac is 11011011011010000000000
  //            exp is 10001100        (13+127 = 140)
  //
  // The IEEE representation is:
  //   0 10001100 11011011011010000000000
  //
  //Or: 0100 0110 0110 1101 1011 0100 0000 0000
  //
  // Convert this to hex and we get:
  //     4    6     6   d     b    4   0     0


 // 15213.0 is:
  // s  exp         frac
  // 0 10001100  11011011011010000000000
  // 0100 0110  0110  1101  1011  0100  0000 0000
  //  4    6      6    d      b     4     0    0
  //
  // For a *NEGATIVE* value: -15213 is 0xC66DB400
  show_float(15213.0);    //remember that this prints bytes in the opposite direction
  value = 0x466db400;
  float_bits result = float_denorn_zero(value);
  printf("Checking the bit pattern %x results in %x\n", value, result);

  result = float_negate(value);
  printf("%x in float bit notation when negated is: %x\n", value, result);


  // determine four small values that should be denormalized (positive and negative) and
  // another that should not. (see description in data activity README)
  // execute the float_denorn_zero function on each and print result

  value = 0x12345678;
  result = float_denorn_zero(value);
  printf("Checking the bit pattern %x results in %x\n", value, result);

  // TODO: complete float_negate so that this will work
  value = 0xC66DB400;
  result = float_negate(value);
  printf("%x in float bit notation when negated is: %x\n", value, result);
  // 4.625 is  40940000  in bit notation for floating point
  // -4.25 is C0940000


  // add more of your own choosing, including both normalized and denormalized values

  // make sure you also try the NaN case


}
