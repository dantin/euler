CC=gcc
CFLAGS=-std=c99 -Wall

EXE=fibonacci_number

$(EXE): $(EXE).c

.PHONY : test
test: $(EXE)
	./$(EXE)

.PHONY : clean
clean:
	rm -f $(EXE) *~