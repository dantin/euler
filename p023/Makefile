CC=gcc
CFLAGS=-std=c99 -Wall

EXE=non_abundant_sums

$(EXE): $(EXE).c

.PHONY : test
test: $(EXE)
	./$(EXE)

.PHONY : clean
clean:
	rm -f $(EXE) *~