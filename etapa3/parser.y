/*
AUTORES:
GABRIEL PIRES E PEIXOTTO - 00326403
JOÃO DAVI M NUNES - 00285639
*/
%{
        #include <stddef.h>

        int yylex(void);
        void yyerror (char const *mensagem);
%}

%code requires {
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

        extern void *arvore;
        extern void batata();
        extern struct no_arvore* criar_folha();
        extern struct no_arvore* criar_no(struct dados_token dados, int num_filhos, struct no_arvore *filhos[num_filhos]);
        extern void imprimir_no(struct no_arvore *no);

        struct no_arvore* prev_declaracao;
}

%union {
        struct dados_token valor_lexico;
        struct no_arvore *no;
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

%type<no> programa
%type<no> declaracoes
%type<no> declaracao
%type<no> variaveis_globais
%type<no> identificadores
%type<no> tipo
%type<no> funcao
%type<no> cabecalho
%type<no> lista_parametros
%type<no> parametros
%type<no> parametro
%type<no> corpo
%type<no> bloco_comandos
%type<no> lista_comandos
%type<no> comandos
%type<no> comando
%type<no> variaveis_locais
%type<no> atribuicao
%type<no> chamada_funcao
%type<no> lista_argumentos
%type<no> argumentos
%type<no> argumento
%type<no> retorno
%type<no> controle_fluxo
%type<no> bloco_if_else
%type<no> bloco_if
%type<no> bloco_else
%type<no> bloco_while
%type<no> expressao
%type<no> term0
%type<no> term1
%type<no> term2
%type<no> term3
%type<no> term4
%type<no> term5
%type<no> term6
%type<no> term7
%type<no> term8
%type<no> term9
%type<no> term10
%type<no> term11
%type<no> term12
%type<no> term13
%type<no> term14
%type<no> operando



%%

programa:
        declaracoes { $$ = $1; arvore = (void*) $$; }
        | %empty { $$ = NULL; }
        ;

declaracoes:
        declaracoes declaracao { $$ = $2; }
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
        cabecalho corpo { $$ = $1; if($2 != NULL) { ADICIONAR_FILHO($$, $2); } }
        ;

cabecalho:
        '(' lista_parametros ')' TK_OC_GE tipo '!' TK_IDENTIFICADOR { $$ = criar_no($7->val_token) }
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
        '{' lista_comandos '}' { $$ = $2; }
        ;

lista_comandos:
        comandos ';' { //FALTA ESSA PARTE }
        | %empty { $$ = NULL; }
        ;

comandos:
        comandos ';' comando { 
                                if($1 != NULL) 
                                        { $$ = $1;
                                                if($3 != NULL)
                                                {
                                                        if (!strcmp($1->label, "if"))
                                                        {
                                                                ADICIONAR_FILHO($1, $3);
                                                        }
                                                        else {
                                                                no_arvore *last_node = $1;
                                                                while(last_node->number_of_children == 3) {
                                                                        last_node = last_node->children[2];
                                                                }
                                                                ADICIONAR_FILHO(last_node, $3);
                                                        }
                                                }
                                        } 
                                       else if($3 != NULL) {$$ = $3;}
                                }
        | comando { $$ = $1; }
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
        TK_IDENTIFICADOR '=' expressao { $$ = criar_no("="); ADICIONAR_FILHO($$, criar_no($1->token_value)); ADICIONAR_FILHO($$, $3); }
        ;

chamada_funcao:
        TK_IDENTIFICADOR '(' lista_argumentos ')' { struct no_arvore *_3 = criar_folha($3); struct no_arvore *filhos[1] = {_3}; $$ = criar_no($1, 1, filhos); }
        ;

lista_argumentos:
        argumentos { $$ = $1; }
        | %empty { $$ = NULL; }
        ;

argumentos:
        argumentos ',' argumento { struct no_arvore *filhos[1] = {$2}; $$ = criar_no($1, 1, filhos); }
        | argumento { $$ = $1; }
        ;

argumento:
        expressao { $$ = $1; }
        ;

retorno:
        TK_PR_RETURN expressao { struct no_arvore *filhos[1] = {$2}; $$ = criar_no($1, 1, filhos); }
        ;

controle_fluxo:
        bloco_if_else { $$ = $1; }
        | bloco_while { $$ = $1; }
        ;

bloco_if_else:
        bloco_if bloco_else { struct no_arvore *filhos[1] = {$2}; $$ = criar_no($1->dados, 1, filhos); }
        ;

bloco_if:
        TK_PR_IF '(' expressao ')' bloco_comandos { struct no_arvore *filhos[2] = {$3, $5}; $$ = criar_no($1, 2, filhos); }
        ;

bloco_else:
        TK_PR_ELSE bloco_comandos { struct no_arvore *filhos[1] = {$2}; $$ = criar_no($1, 1, filhos); }
        | %empty { $$ = NULL; }
        ;

bloco_while:
        TK_PR_WHILE '(' expressao ')' bloco_comandos { struct no_arvore *filhos[2] = {$3, $5}; $$ = criar_no($1, 2, filhos); }
        ;

expressao:
        term0 { $$ = $1; }
        ;

term0:
        term0 TK_OC_OR term1 { struct no_arvore *filhos[2] = {$1, $3}; $$ = criar_no($2, 2, filhos); }
        | term1 { $$ = $1; }
        ;

term1:
        term1 TK_OC_AND term2 { struct no_arvore *filhos[2] = {$1, $3}; $$ = criar_no($2, 2, filhos); }
        | term2 { $$ = $1; }
        ;

term2:
        term2 TK_OC_EQ term3 { struct no_arvore *filhos[2] = {$1, $3}; $$ = criar_no($2, 2, filhos); }
        | term3 { $$ = $1; }
        ;


term3:  
        term3 TK_OC_NE term4 { struct no_arvore *filhos[2] = {$1, $3}; $$ = criar_no($2, 2, filhos); }
        | term4 { $$ = $1; }
        ;

term4:
        term4 '<' term5 { struct no_arvore *filhos[2] = {$1, $3}; $$ = criar_no($2, 2, filhos); }
        | term5 { $$ = $1; }
        ;

term5:  
        term5 '>' term6 { struct no_arvore *filhos[2] = {$1, $3}; $$ = criar_no($2, 2, filhos); }
        | term6 { $$ = $1; }
        ;

term6:  
        term6 TK_OC_LE term7 { struct no_arvore *filhos[2] = {$1, $3}; $$ = criar_no($2, 2, filhos); }
        | term7 { $$ = $1; }
        ;

term7:  
        term7 TK_OC_GE term8 { struct no_arvore *filhos[2] = {$1, $3}; $$ = criar_no($2, 2, filhos); }
        | term8 { $$ = $1; }
        ;

term8:
        term8 '+' term9 { struct no_arvore *filhos[2] = {$1, $3}; $$ = criar_no($2, 2, filhos); }
        | term9 { $$ = $1; }
        ;

term9:  
        term9 '-' term10 { struct no_arvore *filhos[2] = {$1, $3}; $$ = criar_no($2, 2, filhos); }
        | term10 { $$ = $1; }
        ;


term10:
        term10 '*' term11 { struct no_arvore *filhos[2] = {$1, $3}; $$ = criar_no($2, 2, filhos); }
        | term11 { $$ = $1; }
        ;

term11:  
        term11 '/' term12 { struct no_arvore *filhos[2] = {$1, $3}; $$ = criar_no($2, 2, filhos); }
        | term12 { $$ = $1; }
        ;

term12:  
        term12 '%' term13 { struct no_arvore *filhos[2] = {$1, $3}; $$ = criar_no($2, 2, filhos); }
        | term13 { $$ = $1; }
        ;

term13:  
        '-' term13 { struct no_arvore *filhos[1] = {$2}; $$ = criar_no($1, 1, filhos); }
        | '!' term13 { struct no_arvore *filhos[1] = {$2}; $$ = criar_no($1, 1, filhos); }
        | term14 { $$ = $1; }
        ;

term14:
        '(' expressao ')' { $$ = $2; }
        | operando { $$ = $1; }
        ;

operando:
        TK_IDENTIFICADOR { $$ = criar_folha($1); }
        | TK_LIT_FALSE { $$ = criar_folha($1); }
        | TK_LIT_TRUE { $$ = criar_folha($1); }
        | TK_LIT_INT { $$ = criar_folha($1); }
        | TK_LIT_FLOAT { $$ = criar_folha($1); }
        ;

%%