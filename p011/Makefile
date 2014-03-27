CC=gcc
CFLAGS=-std=c99 -lm

largest_product: largest_product.c

.PHONY : test
test: largest_product
	./largest_product < input.txt

.PHONY : clean
clean:
	rm -f largest_product *~