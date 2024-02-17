CC=gcc
CFLAGS=
DEPS = main.c utils.c lex.yy.c parser.tab.c ast.c valorlexico.c scopetable.c iloc.c controlflowgraph.c
OBJ = main.o utils.o lex.yy.o parser.tab.o ast.o valorlexico.o scopetable.o iloc.o controlflowgraph.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) -lm

etapa7: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -lm -g

lex.yy.c: scanner.l parser.tab.c
	flex scanner.l

parser.tab.c: parser.y
	bison -d parser.y

clean:
	rm -f *.o etapa7 lex.yy.c parser.tab.*