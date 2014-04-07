CC=gcc
CFLAGS=-std=c99 -Wall

EXE=lex_perm

$(EXE): $(EXE).c

.PHONY : test
test: $(EXE)
	./$(EXE)

.PHONY : clean
clean:
	rm -f $(EXE) *~