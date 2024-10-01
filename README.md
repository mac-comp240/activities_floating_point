# Activity 8: Binary Floating Point Representation
## Put your name(s) here

In this activity, you will explore the bit-level representation of floating-point numbers. Recall that in the IEEE single precision representation:
- the leftmost, or most significant bit, is the sign bit
- the next 8 bits are the 'exp' value
- the next 23 bits, or the least significant 23 bits are the 'frac' value

For this activity, it is useful to also recall that the floating point numbers
fall into several categories, each of which encodes the above pieces differently
and which represent a range of possible represented values as follows:

![Floating Point Numberline](./img/FPRangeLine.jpg)

You will investigate each of these encodings by considering their bit level
representations, just like the machine does.
- You will test the range of normalized values and view their representation
- You will test the range of denormalized values and view their representation
- You will write a function to check if a float is infinity or NaN by evaluating its bit representation
- You will complete a function to negate a bit representation of a float


## Provided Code

This program has the typical split between a library of functions and other definitions, and a main program that tests them:
- `Makefile`
    - a makefile to automate the compilation process
- `fp_coding_ex.c` and `fp_coding_ex.h`
    - Library containing functions for examining bits of a floating point number
- `show_-_bytes.c` and `show_bytes.h`
    - A library file with code to display the bytes of an integer
- `test.c`
    - Main program that tests the functions in the  `fp_coding_ex` library


### The `fp_coding_ex.c` file contents

The file `fp_coding_ex.c` contains code designed to examine the bit-level
encodings of floating point numbers. This line near the top of the file is a key
aspect of the code:

    typedef unsigned float_bits;

We are going to look at how the machine actually treats the single precision
floating point numbers by treating their bit patterns as unsigned integers. This
typedef helps us use the moniker `float_bits` to refer to the bit-level
representation of a float.


The function `float_denorn_zero` is an example of how the
machine can manipulate the bits that make up the portions of a floating point
number. The unsigned data type, which is 32 bits long and is defined to have the
name `float_bits`, represents how a 32-bit floating point number could be stored
as a bit pattern. 

## Your Tasks


### Task 1: Normalized numbers

Let's start by looking at normalized numbers. Recall that the binary number are represented using this general equation: $(-1)^s \times M \times 2^E$, where $s$ is the sign bit, $E$ is the biased exponent, and $M$ is the mantissa or significand.

With normalized numbers, the exponent is not zero.

Discuss the following questions with your teammates:
1. How is the exponent E computed for the *normalized* numbers in 32-bit single precision representation?
2. How is the significand, M, encoded?
3. Determine the largest and smallest normalized values, both positive and
   negative (that means: the positive normalized value that is closest to zero, and the largest positive normalized value, the negative normalized value that is closest to zero, and the most negative (largest magnitude) negative normalized value). Give your answers as binary sequences written in hex.

See the references below for help determining these values.

Test your answers in `main` by passing `float_denorn_zero` the four values you determined above (largest and smallest positive and negative normalized numbers).  Additionally, create a few other values between those endpoints and
test them as well.  

### Task 2: Denormalized values 

Your next task is to determine some positive and negative denormalized
bit-pattern values for 32-bit single precision and test the `float_denorm_zero` function with them.


Recall that for denormalized values, which are used for small numbers, the exponent bits are all zero.  

Discuss with your teammates:
1. How is the exponent E computed for the *denormalized* numbers in 32-bit
   single precision representation?
2. How is the significand, M, encoded?
3. For 32-bit single precision IEEE floats, what are the largest possible and
   smallest possible denormalized values? Write the answers for both the
   positive and negative ranges in hex.

See the references below for help determining these values.

Once you have answered these questions, test your answers by calling `float_denorn_zero` in `main` and passing the smallest and largest denormalized values. Additionally, create values between those endpoints and
test them as well.  

### Task 3: Infinity and NaN 

How might you write a similar function to test whether a value is either
infinity or NaN (not a number)? Implement this function in `fp_coding_ex.c` and include test calls in `main`.

## Task 4: Negation

Complete the function called `float_negate` in `fp_coding_ex.c` and add test calls in `main`. Your function should build the new bit representation of the negated number, using shifting and masking. 

## Task 5: Optional Challenge

Suppose you wished to test out the full range of 32-bit patterns for floats.
Recall from previous activities that we can use a pointer to unsigned char
(`unsigned char*`) to inspect individual bytes of various types, including
floats. This was done in the `show_bytes` example code provided again here.

Let's start this process by creating a function that will make a float from its
given bit pattern:

- Complete a function called `generate_float` that returns a float from a given
input set of bits represented by the `float_bits` type. You will need to create
the float value using the formula: $(-1)^s\times  M \times  2^E$

where you compute M and E from the rules for IEEE single precision floating
point. You will need to use the exp and frac portions from the original bit
pattern, along with the sign bit.

Note that once you have the floating point representation, you can check whether
the bytes match your original bytes from the input bit pattern. Add a test in
`main` that checks this on some bit patterns.

Now that this seems to work, you can use `generate_float` on a range of
denormalized bit patterns in a loop and use assert to ensure that
`float_denorn_zero` returns what you expect. The you can try it for ranges of
normalized numbers.


## References

- Floating point representations
   - [Reference by Steve Hollasch](http://steve.hollasch.net/cgindex/coding/ieeefloat.html)
   - [Binary Fractions and Floating Point](https://ryanstutorials.net/binary-tutorial/binary-floating-point.php) 
   - [Wikipedia, IEEE 754](https://en.wikipedia.org/wiki/IEEE_754#References)
   - [Digipen page on Floating Points](https://azrael.digipen.edu/~mmead/www/Courses/CS220/IEEE754.html)

- Printf formatting codes
  - [printf format specifier reference from cplusplus.com](http://www.cplusplus.com/reference/cstdio/printf/).
  [_Format Specifiers in C_](https://www.thecrazyprogrammer.com/2016/10/format-specifiers-c.html) by The Crazy Programmer
- General C syntax help
  - [Chapter 1 of _Dive into Systems_](https://diveintosystems.org/book/C1-C_intro/index.html)
  - _The C Programming Language_, often just known as K&R for Kernighan and Ritchie
  - _C: A Reference Manual_, by Harbitson and Steele

