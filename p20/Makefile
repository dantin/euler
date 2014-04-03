CC=gcc
CFLAGS=-std=c99 -Wall

EXE=factorial_digit_sum

$(EXE): $(EXE).c

.PHONY : test
test: $(EXE)
	./$(EXE)

.PHONY : clean
clean:
	rm -f $(EXE) *~