#include <stdio.h>

extern int yylineno;
extern void *arvore;

typedef enum {identificador, literal} TIPO_TOKEN_ENUM;

struct dados_token {
		int num_linha;
		TIPO_TOKEN_ENUM tipo_token;
		char *val_token;
};

struct no_arvore {
		struct dados_token dados;
		struct no_arvore *pai;
		struct no_arvore *filhos[];
};

int get_line_number()
{
	return yylineno;
};

void yyerror(char const *errorMessage)
{
	printf("[Erro] - Linha %d: %s\n", get_line_number(), errorMessage);
};

void exporta (void *arvore)
{
	return;
};

void batata (struct dados_token batata2)
{
	printf("AAAAAAAAAAAAAAA\n");	
	printf("%d\n", batata2.num_linha);
	printf("%s\n", batata2.val_token);
}

