#include <stdio.h>

extern int yylineno;

int get_line_number()
{
	return yylineno;
};
