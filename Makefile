# Makefile for data activities
# author: Libby Shoop  [change this to your own name]

all: fp_coding_ex

fp_coding_ex:  test.c fp_coding_ex.c fp_coding_ex.h show_bytes.c show_bytes.h
	gcc -lm -o fp_coding_ex test.c fp_coding_ex.c show_bytes.c

clean:
	rm fp_coding_ex
