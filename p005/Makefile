CC=gcc
CFLAGS=-std=c99 -lm

EXE=smallest_multiple

$(EXE): $(EXE).c

.PHONY : test
test : $(EXE)
	./$(EXE)

.PHONY : clean
clean:
	rm -f $(EXE) *~