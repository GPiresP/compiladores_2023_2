#include <stdio.h>

extern int yylineno;

int get_line_number()
{
	return yylineno;
};

void yyerror(char* errorMessage)
{
	printf("[Erro] - Linha %d: %s\n", get_line_number(), errorMessage);
};
