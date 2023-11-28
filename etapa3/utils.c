#include <stdio.h>
#include <stdlib.h>

extern int yylineno;
extern void *arvore;

struct dados_token {
		int num_linha;
		int tipo_token;
		char *val_token;
};

struct no_arvore {
		struct dados_token dados;
		int num_filhos;
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
	// printf("*********\n");	
	// printf("Linha do token: %d\n", batata2.num_linha);
	// printf("Tipo do token: %i\n", batata2.tipo_token);
	// printf("Valor do token: %s\n", batata2.val_token);
}

struct no_arvore* alocar_memoria(int numero_filhos)
{
	// printf("TAMANHO STRUCT NO: %ld\nTAMANHO STRUCT DADOS: %ld\n", sizeof (struct no_arvore), sizeof (struct dados_token));
	return (struct no_arvore*) malloc((sizeof (struct dados_token)) + (sizeof (int)) + (sizeof (struct no_arvore*) * (numero_filhos)));
}

struct no_arvore* criar_folha(struct dados_token dados)
{
	struct no_arvore *novo_no = alocar_memoria(0);

	novo_no->dados = dados;
	novo_no->num_filhos = 0;

	return novo_no;
}

struct no_arvore* criar_no(struct dados_token dados, int num_filhos, struct no_arvore *filhos[num_filhos])
{
	struct no_arvore *novo_no = alocar_memoria(num_filhos);

	novo_no->dados = dados;
	novo_no->num_filhos = num_filhos;

	for(int i = 0; i < num_filhos; i++)
	{
		novo_no->filhos[i] = filhos[i];
	}

	return novo_no;
}

void imprimir_no(struct no_arvore *no)
{
	printf("*****NO*****\n");	
	printf("Linha do token: %d\n", no->dados.num_linha);
	printf("Tipo do token: %i\n", no->dados.tipo_token);
	printf("Valor do token: %s\n", no->dados.val_token);
	printf("Numero de filhos: %d\n", no->num_filhos);
	for(int i = 0; i < no->num_filhos; i++)
	{
		printf("Endereco filho %d: %p\n", i, no->filhos[i]);
	}
	printf("***********\n");
}
