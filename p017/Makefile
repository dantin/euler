CC=gcc
CFLAGS=-std=c99 -Wall -lm

EXE=letter_count

$(EXE): $(EXE).c

.PHONY : test
test: $(EXE)
	./$(EXE)

.PHONY : clean
clean:
	rm -f $(EXE) *~