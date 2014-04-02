CC=gcc
CFLAGS=-std=c99 -lm

EXE=largest_prime

$(EXE): $(EXE).c

.PHONY : test
test : $(EXE)
	./$(EXE)

.PHONY : clean
clean:
	rm -f $(EXE) *~