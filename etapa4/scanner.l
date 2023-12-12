/*
AUTORES:
GABRIEL PIRES E PEIXOTTO - 00326403
JOÃO DAVI M NUNES - 00285639
*/

%option noyywrap
%option yylineno
%{
	#include "parser.tab.h"
	extern YYSTYPE yylval;
%}

%option yylineno
%option noyywrap

%%
"//".*	{ }
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]	{ }
[/][*]	{ }
\n 	{ }
\t	{ }
\r 	{ }
\ 	{ }
int 	{ 
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = TK_PR_INT;
			yylval.valor_lexico->token_value = strdup(yytext);
			return TK_PR_INT; 
		}

float 	{ 
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = TK_PR_FLOAT;
			yylval.valor_lexico->token_value = strdup(yytext);
			return TK_PR_FLOAT; 
		}

bool 	{ 
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = TK_PR_BOOL;
			yylval.valor_lexico->token_value = strdup(yytext);	
			return TK_PR_BOOL; 
		}

if 		{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = TK_PR_IF;
			yylval.valor_lexico->token_value = strdup(yytext); 
			return TK_PR_IF; 
		}

else 	{ 
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = TK_PR_ELSE;
			yylval.valor_lexico->token_value = strdup(yytext);
			return TK_PR_ELSE; 
		}

while 	{ 
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = TK_PR_WHILE;
			yylval.valor_lexico->token_value = strdup(yytext);
			return TK_PR_WHILE; 
		}

return 	{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = TK_PR_RETURN;
			yylval.valor_lexico->token_value = strdup(yytext); 
			return TK_PR_RETURN; 
		}

false	{ 
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = TK_LIT_FALSE;
			yylval.valor_lexico->token_value = strdup(yytext);
			return TK_LIT_FALSE; 
		}

true	{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = TK_LIT_TRUE;
			yylval.valor_lexico->token_value = strdup(yytext); 
			return TK_LIT_TRUE; 
		}

\<\=	{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = TK_OC_LE;
			yylval.valor_lexico->token_value = strdup(yytext); 
			return TK_OC_LE; 
		}

\>\=	{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = TK_OC_GE;
			yylval.valor_lexico->token_value = strdup(yytext); 
			return TK_OC_GE; 
		}

\=\=	{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = TK_OC_EQ;
			yylval.valor_lexico->token_value = strdup(yytext); 
			return TK_OC_EQ; 
		}

\!\=	{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = TK_OC_NE;
			yylval.valor_lexico->token_value = strdup(yytext); 
			return TK_OC_NE; 
		}

\&		{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = TK_OC_AND;
			yylval.valor_lexico->token_value = strdup(yytext);
			return TK_OC_AND; 
		}

\|		{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = TK_OC_OR;
			yylval.valor_lexico->token_value = strdup(yytext);
			return TK_OC_OR; 
		}

\!		{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = (int) '!';
			yylval.valor_lexico->token_value = strdup(yytext);
			return (int) '!'; 
		}

\-		{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = (int) '-';
			yylval.valor_lexico->token_value = strdup(yytext);
			return (int) '-'; 
		}

\*		{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = (int) '*';
			yylval.valor_lexico->token_value = strdup(yytext);
			return (int) '*'; 
		}

\/		{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = (int) '/';
			yylval.valor_lexico->token_value = strdup(yytext);
			return (int) '/'; 
		}

\% 		{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = (int) '%';
			yylval.valor_lexico->token_value = strdup(yytext);
			return (int) '%'; 
		}

\+		{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = (int) '+';
			yylval.valor_lexico->token_value = strdup(yytext);
			return (int) '+'; 
		}

\<		{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = (int) '<';
			yylval.valor_lexico->token_value = strdup(yytext);
			return (int) '<'; 
		}

\>		{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = (int) '>';
			yylval.valor_lexico->token_value = strdup(yytext);
			return (int) '>'; 
		}

\{		{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = (int) '{';
			yylval.valor_lexico->token_value = strdup(yytext);
			return (int) '{'; 
		}

\}		{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = (int) '}';
			yylval.valor_lexico->token_value = strdup(yytext);
			return (int) '}'; 
		}

\(		{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = (int) '(';
			yylval.valor_lexico->token_value = strdup(yytext);
			return (int) '('; 
		}

\)		{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = (int) ')';
			yylval.valor_lexico->token_value = strdup(yytext);
			return (int) ')'; 
		}

\=		{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = (int) '=';
			yylval.valor_lexico->token_value = strdup(yytext);
			return (int) '='; 
		}

\,		{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = (int) ',';
			yylval.valor_lexico->token_value = strdup(yytext);
			return (int) ','; 
		}

\;		{
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = (int) ';';
			yylval.valor_lexico->token_value = strdup(yytext);
			return (int) ';'; 
		}

[0-9]+	{ 
			yylval.valor_lexico = malloc(sizeof (VL));
			yylval.valor_lexico->line_number = yylineno;
			yylval.valor_lexico->token_type = TK_LIT_INT;
			yylval.valor_lexico->token_value = strdup(yytext);
			return TK_LIT_INT; 
		}

[0-9]*\.[0-9]+	{
					yylval.valor_lexico = malloc(sizeof (VL));
					yylval.valor_lexico->line_number = yylineno;
					yylval.valor_lexico->token_type = TK_LIT_FLOAT;
					yylval.valor_lexico->token_value = strdup(yytext); 
					return TK_LIT_FLOAT; 
				}

[_a-z][_a-z0-9]*	{ 
						yylval.valor_lexico = malloc(sizeof (VL));
						yylval.valor_lexico->line_number = yylineno;
						yylval.valor_lexico->token_type = TK_IDENTIFICADOR;
						yylval.valor_lexico->token_value = strdup(yytext);
						return TK_IDENTIFICADOR; 
					}

. 		{ 
			return TK_ERRO; 
		}

%%
