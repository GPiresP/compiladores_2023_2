CC=gcc
CFLAGS=-lfl
DEPS = tokens.h
OBJ = main.o lex.yy.o utils.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

etapa1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

lex.yy.c: scanner.l
	flex scanner.l
