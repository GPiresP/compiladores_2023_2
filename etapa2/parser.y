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

programa: declaracoes funcoes
        | funcoes declaracoes
        | declaracoes
        | funcoes
        |
        ;

declaracoes: vars_glob
        ;

vars_glob: tipo lista_vars_global ';'
        ;

lista_vars_global: TK_IDENTIFICADOR
                | lista_vars_global ',' TK_IDENTIFICADOR
                ;

funcoes: funcao
        | funcoes funcao
        ;

funcao: cabecalho corpo
        ;

cabecalho: '(' lista_params ')' TK_OC_GE tipo '!' TK_IDENTIFICADOR 
        ;

lista_params: lista_params ',' tipo TK_IDENTIFICADOR
            | tipo TK_IDENTIFICADOR
            |
            ;

corpo: bloco_cmd
        ;

bloco_cmd: '{' lista_cmd_simples '}'
            | '{' '}'
            ;

lista_cmd_simples: lista_cmd_simples cmd ';'
                | cmd ';'
                ;

cmd: decl_var_local
    | atrib
    | cont_fluxo_controle
    | op_ret
    | bloco_cmd
    | call_func
    ;

decl_var_local: tipo lista_var_local
                ;

lista_var_local: lista_var_local ',' TK_IDENTIFICADOR
                | TK_IDENTIFICADOR
                ;

atrib: TK_IDENTIFICADOR '=' expressao
        ;

cont_fluxo_controle: condicional
                    | iterativa
                    ;

condicional: TK_PR_IF '(' expressao ')' bloco_cmd 
            | TK_PR_IF '(' expressao ')' bloco_cmd TK_PR_ELSE bloco_cmd
            ;

iterativa: TK_PR_WHILE '(' expressao ')' bloco_cmd
            ;

op_ret: TK_PR_RETURN expressao
        ;

call_func: TK_IDENTIFICADOR '(' lista_args ')'
        | TK_IDENTIFICADOR '(' ')'
        ;

lista_args: lista_args ',' expressao
        | expressao
        ;

expressao: 

tipo: TK_PR_INT 
    | TK_PR_FLOAT
    | TK_PR_BOOL
    ;

%%