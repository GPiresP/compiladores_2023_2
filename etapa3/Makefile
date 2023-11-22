CC=gcc
CFLAGS=
DEPS = main.c utils.c lex.yy.c parser.tab.c
OBJ = main.o utils.o lex.yy.o parser.tab.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

etapa2: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

lex.yy.c: scanner.l parser.tab.c
	flex scanner.l

parser.tab.c: parser.y
	bison -d parser.y

clean:
	rm -f *.o etapa2 lex.yy.c parser.tab.*