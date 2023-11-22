/*
AUTORES:
GABRIEL PIRES E PEIXOTTO - 00326403
JOÃO DAVI M NUNES - 00285639
*/
%option noyywrap
%option yylineno
%{
	#include "parser.tab.h"
%}

%%
"//".*	{ }
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]	{ }
[/][*]	{ }
\n 	{ }
\ 	{ }
int 	{ return TK_PR_INT; }
float 	{ return TK_PR_FLOAT; }
bool 	{ return TK_PR_BOOL; }
if 	{ return TK_PR_IF; }
else 	{ return TK_PR_ELSE; }
while 	{ return TK_PR_WHILE; }
return 	{ return TK_PR_RETURN; }
false	{ return TK_LIT_FALSE; }
true	{ return TK_LIT_TRUE; }
\<\=	{ return TK_OC_LE; }
\>\=	{ return TK_OC_GE; }
\=\=	{ return TK_OC_EQ; }
\!\=	{ return TK_OC_NE; }
\&	{ return TK_OC_AND; }
\|	{ return TK_OC_OR; }
\!	{ return (int) '!'; }
\-	{ return (int) '-'; }
\*	{ return (int) '*'; }
\/	{ return (int) '/'; }
\% 	{ return (int) '%'; }
\+	{ return (int) '+'; }
\<	{ return (int) '<'; }
\>	{ return (int) '>'; }
\{	{ return (int) '{'; }
\}	{ return (int) '}'; }
\(	{ return (int) '('; }
\)	{ return (int) ')'; }
\=	{ return (int) '='; }
\,	{ return (int) ','; }
\;	{ return (int) ';'; }
[0-9]+	{ return TK_LIT_INT; }
[0-9]*\.[0-9]+	{ return TK_LIT_FLOAT; }
[_a-z][_a-z0-9]*	{ return TK_IDENTIFICADOR; }
. 	{ return TK_ERRO; }
%%
