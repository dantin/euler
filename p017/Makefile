CC=gcc
CFLAGS=-std=c99 -Wall

EXE=letter_count

$(EXE): $(EXE).c

.PHONY : test
test: $(EXE)
	./$(EXE)

.PHONY : clean
clean:
	rm -f $(EXE) *~