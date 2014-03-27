CC=gcc
CFLAGS=-std=c99 -lm

EXE=large_sum

$(EXE): $(EXE).c

.PHONY : test
test: $(EXE)
	./$(EXE) < input.txt

.PHONY : clean
clean:
	rm -f $(EXE) *~