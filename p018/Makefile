CC=gcc
CFLAGS=-std=c99 -Wall

EXE=max_path

$(EXE): $(EXE).c

.PHONY : test
test: $(EXE)
	./$(EXE) < input.txt

.PHONY : clean
clean:
	rm -f $(EXE) *~