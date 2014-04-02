CC=gcc
CFLAGS=-std=c99

EXE=fibonacci

$(EXE): $(EXE).c

.PHONY : test
test : $(EXE)
	./$(EXE)

.PHONY : clean
clean:
	rm -f $(EXE) *~