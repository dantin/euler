CC=gcc
CFLAGS=-std=c99 -Wall

EXE=names_scores

$(EXE): $(EXE).c

.PHONY : test
test: $(EXE)
	./$(EXE) < names.txt

.PHONY : clean
clean:
	rm -f $(EXE) *~