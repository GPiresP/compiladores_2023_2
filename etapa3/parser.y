/*
AUTORES:
GABRIEL PIRES E PEIXOTTO - 00326403
JOÃO DAVI M NUNES - 00285639
*/

%{
        #include <stddef.h>
        #include <string.h>
        #include "ast.h"
        #include "valorlexico.h"
        int yylex(void);
        void yyerror (char const *mensagem);
        extern int yylineast;
        extern void *arvore;
%}

%code requires {
        #include "ast.h"
        #include "valorlexico.h"
}

%union {
        VL *valor_lexico;
        AST *ast;
}

%define parse.error verbose

%token<valor_lexico> TK_PR_INT
%token<valor_lexico> TK_PR_FLOAT
%token<valor_lexico> TK_PR_BOOL
%token<valor_lexico> TK_PR_IF
%token<valor_lexico> TK_PR_ELSE
%token<valor_lexico> TK_PR_WHILE
%token<valor_lexico> TK_PR_RETURN
%token<valor_lexico> TK_OC_LE
%token<valor_lexico> TK_OC_GE
%token<valor_lexico> TK_OC_EQ
%token<valor_lexico> TK_OC_NE
%token<valor_lexico> TK_OC_AND
%token<valor_lexico> TK_OC_OR
%token<valor_lexico> TK_IDENTIFICADOR
%token<valor_lexico> TK_LIT_INT
%token<valor_lexico> TK_LIT_FLOAT
%token<valor_lexico> TK_LIT_FALSE
%token<valor_lexico> TK_LIT_TRUE
%token<valor_lexico> '!'
%token<valor_lexico> '-'
%token<valor_lexico> '*'
%token<valor_lexico> '/'
%token<valor_lexico> '%'
%token<valor_lexico> '+'
%token<valor_lexico> '<'
%token<valor_lexico> '>'
%token<valor_lexico> '{'
%token<valor_lexico> '}'
%token<valor_lexico> '('
%token<valor_lexico> ')'
%token<valor_lexico> '='
%token<valor_lexico> ','
%token<valor_lexico> ';'
%token TK_ERRO

%type<ast> programa
%type<ast> declaracoes
%type<ast> declaracao
%type<ast> variaveis_globais
%type<ast> identificadores
%type<ast> tipo
%type<ast> funcao
%type<ast> cabecalho
%type<ast> lista_parametros
%type<ast> parametros
%type<ast> parametro
%type<ast> corpo
%type<ast> bloco_comandos
%type<ast> comandos
%type<ast> comando
%type<ast> variaveis_locais
%type<ast> atribuicao
%type<ast> chamada_funcao
%type<ast> lista_argumentos
%type<ast> argumentos
%type<ast> argumento
%type<ast> retorno
%type<ast> controle_fluxo
%type<ast> bloco_if_else
%type<ast> bloco_if
%type<ast> bloco_else
%type<ast> bloco_while
%type<ast> expressao
%type<ast> term0
%type<ast> term1
%type<ast> term2
%type<ast> term4
%type<ast> term8
%type<ast> term10
%type<ast> term13
%type<ast> term14
%type<ast> operando



%%

programa:
        declaracoes { $$ = $1; arvore = (void*) $$; }
        | %empty { $$ = NULL; }
        ;

declaracoes:
        declaracao declaracoes { if ($1 == NULL) $$ = $2; else { $$ = $1; ast_add_child($1, $2); } }
        | declaracao { $$ = $1; }
        ;

declaracao:
        funcao { $$ = $1; }
        | variaveis_globais { $$ = NULL; }
        ;

variaveis_globais:
        tipo identificadores ';' { $$ = NULL; }
        ;

identificadores:
        identificadores ',' TK_IDENTIFICADOR { $$ = NULL; }
        | TK_IDENTIFICADOR { $$ = NULL; }
        ;

tipo:
        TK_PR_INT { $$ = NULL; }
        | TK_PR_FLOAT { $$ = NULL; }
        | TK_PR_BOOL { $$ = NULL; }
        ;

funcao:
        cabecalho corpo { $$ = $1; if($2 != NULL) { ast_add_child($$, $2); } }
        ;

cabecalho:
        '(' lista_parametros ')' TK_OC_GE tipo '!' TK_IDENTIFICADOR { $$ = ast_new($7->token_value); }
        ;

lista_parametros:
        parametros { $$ = NULL; }
        | %empty { $$ = NULL; }
        ;

parametros:
        parametros ',' parametro { $$ = NULL; }
        | parametro { $$ = NULL; }
        ;

parametro:
        tipo TK_IDENTIFICADOR { $$ = NULL; }
        ;

corpo:
        bloco_comandos { $$ = $1; }
        ;

bloco_comandos:
        '{' comandos '}' { $$ = $2; }
        | '{' '}' { $$ = NULL; }
        ;

comandos:
        comando ';' comandos { 
                                if($1 != NULL) {
                                    $$ = $1;
                                    if ($3 != NULL) {
                                        ast_add_child($1, $3);
                                    }
                                } else if($3 != NULL) {
                                    $$ = $3;
                                } else {
                                    $$ = NULL;
                                }
                            }
        | comando ';' { $$ = $1; }
        ;

comando:
        variaveis_locais { $$ = $1; }
        | atribuicao { $$ = $1; }
        | chamada_funcao { $$ = $1; }
        | retorno { $$ = $1; }
        | controle_fluxo { $$ = $1; }
        | bloco_comandos { $$ = $1; }
        ;

variaveis_locais:
        tipo identificadores  { $$ = $2; }
        ;

atribuicao:
        TK_IDENTIFICADOR '=' expressao { $$ = ast_new("="); ast_add_child($$, ast_new($1->token_value)); ast_add_child($$, $3); }
        ;

chamada_funcao:
        TK_IDENTIFICADOR '(' lista_argumentos ')' { char call[] = "call "; $$ = ast_new(strcat(call,$1->token_value)); ast_add_child($$, $3); }
        ;

lista_argumentos:
        argumentos { $$ = $1; }
        | %empty { $$ = NULL; }
        ;

argumentos:
        argumento { $$ = $1; }
        | argumento ',' argumentos { $$ = $1; ast_add_child($1, $3); } 
        ;

argumento:
        expressao { $$ = $1; }
        ;

retorno:
        TK_PR_RETURN expressao { $$ = ast_new($1->token_value); ast_add_child($$, $2); }
        ;

controle_fluxo:
        bloco_if_else { $$ = $1; }
        | bloco_while { $$ = $1; }
        ;

bloco_if_else:
        bloco_if bloco_else {  $$ = $1; if($2 != NULL){ ast_add_child($$, $2); } }
        ;

bloco_if:
        TK_PR_IF '(' expressao ')' bloco_comandos { $$ = ast_new($1->token_value); ast_add_child($$, $3); if($5 != NULL){ ast_add_child($$, $5); } }
        ;

bloco_else:
        TK_PR_ELSE bloco_comandos { $$ = $2; }
        | %empty { $$ = NULL; }
        ;

bloco_while:
        TK_PR_WHILE '(' expressao ')' bloco_comandos { $$ = ast_new($1->token_value); ast_add_child($$, $3); ast_add_child($$, $5); }
        ;

expressao:
        term0 { $$ = $1; }
        ;

term0:
        term0 TK_OC_OR term1 { $$ = ast_new($2->token_value); ast_add_child($$, $1); ast_add_child($$, $3); }
        | term1 { $$ = $1; }
        ;

term1:
        term1 TK_OC_AND term2 { $$ = ast_new($2->token_value); ast_add_child($$, $1); ast_add_child($$, $3); }
        | term2 { $$ = $1; }
        ;

term2:
        term2 TK_OC_EQ term4 { $$ = ast_new($2->token_value); ast_add_child($$, $1); ast_add_child($$, $3); }
        | term2 TK_OC_NE term4 { $$ = ast_new($2->token_value); ast_add_child($$, $1); ast_add_child($$, $3); }
        | term4 { $$ = $1; }
        ;

term4:
        term4 '<' term8 { $$ = ast_new($2->token_value); ast_add_child($$, $1); ast_add_child($$, $3); }
        | term4 '>' term8 { $$ = ast_new($2->token_value); ast_add_child($$, $1); ast_add_child($$, $3); }
        | term4 TK_OC_LE term8 { $$ = ast_new($2->token_value); ast_add_child($$, $1); ast_add_child($$, $3); }
        | term4 TK_OC_GE term8 { $$ = ast_new($2->token_value); ast_add_child($$, $1); ast_add_child($$, $3); }
        | term8 { $$ = $1; }
        ;

term8:
        term8 '+' term10 { $$ = ast_new($2->token_value); ast_add_child($$, $1); ast_add_child($$, $3); }
        | term8 '-' term10 { $$ = ast_new($2->token_value); ast_add_child($$, $1); ast_add_child($$, $3); }
        | term10 { $$ = $1; }
        ;


term10:
        term10 '*' term13 { $$ = ast_new($2->token_value); ast_add_child($$, $1); ast_add_child($$, $3); }
        | term10 '/' term13 { $$ = ast_new($2->token_value); ast_add_child($$, $1); ast_add_child($$, $3); }
        | term10 '%' term13 { $$ = ast_new($2->token_value); ast_add_child($$, $1); ast_add_child($$, $3); }
        | term13 { $$ = $1; }
        ;

term13:  
        '-' term13 { $$ = ast_new($1->token_value); ast_add_child($$, $2); }
        | '!' term13 { $$ = ast_new($1->token_value); ast_add_child($$, $2); }
        | term14 { $$ = $1; }
        ;

term14:
        '(' expressao ')' { $$ = $2; }
        | chamada_funcao { $$ = $1; }
        | operando { $$ = $1; }
        ;

operando:
        TK_IDENTIFICADOR { $$ = ast_new($1->token_value); }
        | TK_LIT_FALSE { $$ = ast_new($1->token_value); }
        | TK_LIT_TRUE { $$ = ast_new($1->token_value); }
        | TK_LIT_INT { $$ = ast_new($1->token_value); }
        | TK_LIT_FLOAT { $$ = ast_new($1->token_value); }
        ;

%%
