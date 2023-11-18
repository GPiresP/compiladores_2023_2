/*
AUTORES:
GABRIEL PIRES E PEIXOTTO - 00326403
JOÃO DAVI M NUNES - 00285639
*/
%{
int yylex(void);
void yyerror (char const *mensagem);
%}

%define parse.error verbose

%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_IF
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_RETURN
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_IDENTIFICADOR
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_ERRO

%%

programa:
        declaracoes
        | %empty
        ;

declaracoes:
        declaracoes declaracao
        | declaracao
        ;

declaracao:
        funcao
        | variaveis_globais
        ;

variaveis_globais:
        tipo identificadores ';'
        ;

identificadores:
        identificadores ',' TK_IDENTIFICADOR
        | TK_IDENTIFICADOR
        ;

tipo:
        TK_PR_INT
        | TK_PR_FLOAT
        | TK_PR_BOOL
        ;

funcao:
        cabecalho corpo
        ;

cabecalho:
        '(' lista_parametros ')' TK_OC_GE tipo '!' TK_IDENTIFICADOR
        ;

lista_parametros:
        parametros 
        | %empty
        ;

parametros:
        parametros ',' parametro
        | parametro
        ;

parametro:
        tipo TK_IDENTIFICADOR
        ;

corpo:
        bloco_comandos
        ;

bloco_comandos:
        '{' lista_comandos '}'
        ;

lista_comandos:
        comandos ';'
        | %empty
        ;

comandos:
        comandos ';' comando
        | comando
        ;

comando:
        variaveis_locais
        | atribuicao
        | chamada_funcao
        | retorno
        | controle_fluxo
        | bloco_comandos
        ;

variaveis_locais:
        tipo identificadores
        ;

atribuicao:
        TK_IDENTIFICADOR '=' expressao
        ;

chamada_funcao:
        TK_IDENTIFICADOR '(' lista_argumentos ')'
        ;

lista_argumentos:
        argumentos
        | %empty
        ;

argumentos:
        argumentos ',' argumento
        | argumento
        ;

argumento:
        expressao
        ;

retorno:
        TK_PR_RETURN expressao
        ;

controle_fluxo:
        bloco_if_else
        | bloco_while
        ;

bloco_if_else:
        bloco_if bloco_else
        ;

bloco_if:
        TK_PR_IF '(' expressao ')' bloco_comandos
        ;

bloco_else:
        TK_PR_ELSE bloco_comandos
        | %empty
        ;

bloco_while:
        TK_PR_WHILE '(' expressao ')' bloco_comandos
        ;

expressao:
        operador_unario termo_classe_0
        | termo_classe_0
        ;

operador_unario:
        '-'
        | '!'
        ;

termo_classe_0:
        termo_classe_0 TK_OC_OR termo_classe_1
        | termo_classe_1
        ;

termo_classe_1:
        termo_classe_1 TK_OC_AND termo_classe_2
        | termo_classe_2
        ;

termo_classe_2:
        termo_classe_2 TK_OC_EQ termo_classe_3
        termo_classe_2 TK_OC_NE termo_classe_3
        | termo_classe_3
        ;

termo_classe_3:
        termo_classe_3 '<' termo_classe_4
        | termo_classe_3 '>' termo_classe_4
        | termo_classe_3 TK_OC_LE termo_classe_4
        | termo_classe_3 TK_OC_GE termo_classe_4
        | termo_classe_4
        ;

termo_classe_4:
        termo_classe_4 '+' termo_classe_5
        | termo_classe_4 '-' termo_classe_5
        | termo_classe_5
        ;

termo_classe_5:
        termo_classe_5 '*' termo_classe_6
        | termo_classe_5 '/' termo_classe_6
        | termo_classe_5 '%' termo_classe_6
        | termo_classe_6
        ;

termo_classe_6:
        '(' expressao ')'
        | operando
        ;

operando:
        TK_IDENTIFICADOR
        | TK_LIT_FALSE
        | TK_LIT_TRUE
        | TK_LIT_INT
        | TK_LIT_FLOAT
        ;

%%