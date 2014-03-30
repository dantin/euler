CC=gcc
CFLAGS=-std=c99 -Wall

EXE=longest_collatz

$(EXE): $(EXE).c

.PHONY : test
test: $(EXE)
	./$(EXE)

.PHONY : clean
clean:
	rm -f $(EXE) *~