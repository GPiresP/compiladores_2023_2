CC=gcc
CFLAGS=
DEPS = main.c utils.c lex.yy.c parser.tab.c ast.c valorlexico.c
OBJ = main.o utils.o lex.yy.o parser.tab.o ast.o valorlexico.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

etapa3: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

lex.yy.c: scanner.l parser.tab.c
	flex scanner.l

parser.tab.c: parser.y
	bison -d parser.y

clean:
	rm -f *.o etapa3 lex.yy.c parser.tab.*