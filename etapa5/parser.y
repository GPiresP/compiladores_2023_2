/*
AUTORES:
GABRIEL PIRES E PEIXOTTO - 00326403
JOÃO DAVI M NUNES - 00285639
*/

%{
        #include <stddef.h>
        #include <string.h>
        #include <stdio.h>
        #include <stdlib.h>
        #include "ast.h"
        #include "valorlexico.h"
        #include "scopetable.h"
        #include "iloc.h"

        #define ERR_UNDECLARED 10 //2.2
        #define ERR_DECLARED 11 //2.2
        #define ERR_VARIABLE 20 //2.3
        #define ERR_FUNCTION 21 //2.3

        int yylex(void);
        void yyerror (char const *mensagem);
        extern int yylineast;
        extern void *arvore;
        T_SCOPE_TABLE_STACK *table_stack = NULL;

        
%}

%code requires {
        #include "ast.h"
        #include "valorlexico.h"
        #include "scopetable.h"
        #include "iloc.h"
}

%union {
        VL *valor_lexico;
        AST *ast;
        T_STRING_LIST *string_list;
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

%type<valor_lexico> tipo
%type<string_list> identificadores

%type<ast> programa
%type<ast> declaracoes
%type<ast> declaracao
%type<ast> variaveis_globais
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
        abrir_escopo declaracoes fechar_escopo 
        { 
                $$ = $2; arvore = (void*) $$;
        }
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
        tipo identificadores ';' 
        { 
                $$ = NULL; 
                int line_num = $1->line_number;
                char *nature = "identificador";
                int stack_idx = (table_stack->tables_number) - 1;
                T_SCOPE_TABLE* stack_top = table_stack->tables[stack_idx];
                for(int i = 0; i < $2->strings_number; i++)
                {
                        char *string = $2->strings[i];

                        T_SCOPE_TABLE_ROW *existing_row = find_symbol_stack(table_stack, string);

                        if(existing_row != NULL)
                        {
                                printf("ERROR AT LINE %d. EXITING WITH CODE: %d (VARIABLE ALREADY DECLARED!). VARIABLE NAME: %s.\n", $1->line_number, ERR_DECLARED, string);
                                exit(ERR_DECLARED); 
                        }

                        T_SCOPE_TABLE_ROW *row = create_row(line_num, string, nature, $1->token_value, string);
                        stack_top = add_row(stack_top, row);
                        table_stack->tables[stack_idx] = stack_top;
                }
        }
        ;

identificadores:
        identificadores ',' TK_IDENTIFICADOR 
        { 
                T_SCOPE_TABLE_ROW *existing_row = find_symbol_stack(table_stack, $3->token_value);

                if(existing_row != NULL)
                {
                        printf("ERROR AT LINE %d. EXITING WITH CODE: %d (VARIABLE ALREADY DECLARED!). VARIABLE NAME: %s.\n", $3->line_number, ERR_DECLARED, $3->token_value);
                        exit(ERR_DECLARED); 
                }

                $$ = add_string($1, $3->token_value); 
        }
        | TK_IDENTIFICADOR 
        { 
                T_SCOPE_TABLE_ROW *existing_row = find_symbol_stack(table_stack, $1->token_value);

                if(existing_row != NULL)
                {
                        printf("ERROR AT LINE %d. EXITING WITH CODE: %d (VARIABLE ALREADY DECLARED!). VARIABLE NAME: %s.\n", $1->line_number, ERR_DECLARED, $1->token_value);
                        exit(ERR_DECLARED); 
                }

                $$ = create_string_list(); 
                $$ = add_string($$, $1->token_value);
        }
        ;

tipo:
        TK_PR_INT 
        { 
                $$ = $1;
        }
        | TK_PR_FLOAT 
        { 
                $$ = $1;
        }
        | TK_PR_BOOL
        { 
                $$ = $1;
        }
        ;

funcao:
        abrir_escopo cabecalho corpo fechar_escopo
        { 
                $$ = $2; 
                if($3 != NULL) 
                { 
                        ast_add_child($$, $3); 
                }
        }
        ;

cabecalho:
        '(' lista_parametros ')' TK_OC_GE tipo '!' TK_IDENTIFICADOR 
        { 
                $$ = ast_new($7->token_value, $5->token_value);

                int line_num = $1->line_number;
                char *nature = "função";
                int stack_idx = (table_stack->tables_number) - 2;
                T_SCOPE_TABLE* stack_top = table_stack->tables[stack_idx];

                char *string = $7->token_value;

                T_SCOPE_TABLE_ROW *existing_row = find_symbol_stack(table_stack, string);

                if(existing_row != NULL)
                {
                        printf("ERROR AT LINE %d. EXITING WITH CODE: %d (FUNCTION ALREADY DECLARED!). FUNCTION NAME: %s.\n", $1->line_number, ERR_DECLARED, string);
                        exit(ERR_DECLARED); 
                }

                T_SCOPE_TABLE_ROW *row = create_row(line_num, string, nature, $5->token_value, string);
                stack_top = add_row(stack_top, row);
                
                table_stack->tables[stack_idx] = stack_top;
        }
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
        tipo TK_IDENTIFICADOR 
        { 
                $$ = NULL;
                int line_num = $1->line_number;
                char *nature = "identificador";
                int stack_idx = (table_stack->tables_number) - 1;
                T_SCOPE_TABLE* stack_top = table_stack->tables[stack_idx];

                char *string = $2->token_value;

                T_SCOPE_TABLE_ROW *existing_row = find_symbol_stack(table_stack, string);

                if(existing_row != NULL)
                {
                        printf("ERROR AT LINE %d. EXITING WITH CODE: %d (VARIABLE ALREADY DECLARED!). VARIABLE NAME: %s.\n", $1->line_number, ERR_DECLARED, string);
                        exit(ERR_DECLARED); 
                }

                T_SCOPE_TABLE_ROW *row = create_row(line_num, string, nature, $1->token_value, string);
                stack_top = add_row(stack_top, row);
                
                table_stack->tables[stack_idx] = stack_top;
        }
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
        | abrir_escopo bloco_comandos fechar_escopo { $$ = $2; }
        ;

variaveis_locais:
        tipo identificadores  
        { 
                $$ = NULL; 
                int line_num = $1->line_number;
                char *nature = "identificador";
                int stack_idx = (table_stack->tables_number) - 1;
                T_SCOPE_TABLE* stack_top = table_stack->tables[stack_idx];
                for(int i = 0; i < $2->strings_number; i++)
                {
                        char *string = $2->strings[i];

                        T_SCOPE_TABLE_ROW *existing_row = find_symbol_stack(table_stack, string);

                        if(existing_row != NULL)
                        {
                                printf("ERROR AT LINE %d. EXITING WITH CODE: %d (VARIABLE ALREADY DECLARED!). VARIABLE NAME: %s.\n", $1->line_number, ERR_DECLARED, string);
                                exit(ERR_DECLARED); 
                        }

                        T_SCOPE_TABLE_ROW *row = create_row(line_num, string, nature, $1->token_value, string);
                        stack_top = add_row(stack_top, row);
                        table_stack->tables[stack_idx] = stack_top;
                }
        
        }
        ;

atribuicao:
        TK_IDENTIFICADOR '=' expressao 
        { 
                char *symbol = $1->token_value;

                T_SCOPE_TABLE_ROW *row = find_symbol_stack(table_stack, symbol);

                if(row == NULL)
                {
                        printf("ERROR AT LINE %d. EXITING WITH CODE: %d (VARIABLE NOT YET DECLARED!). VARIABLE NAME: %s.\n", $1->line_number, ERR_UNDECLARED, symbol);
                        exit(ERR_UNDECLARED);
                }
                else
                {
                        char *nature = "identificador";
                        int is_equal = strcmp(row->nature, nature);
                        if(is_equal != 0)
                        {
                                printf("ERROR AT LINE %d. EXITING WITH CODE: %d (FUNCTION BEING USED AS VARIABLE!). FUNCTION NAME: %s.\n", $1->line_number, ERR_FUNCTION, symbol);
                                exit(ERR_UNDECLARED);
                        } 
                }

                $$ = ast_new("=", $3->type); 
                ast_add_child($$, ast_new($1->token_value, row->data_type)); 
                ast_add_child($$, $3); 
        }
        ;

chamada_funcao:
        TK_IDENTIFICADOR '(' lista_argumentos ')' 
        { 
                char *symbol = $1->token_value;

                T_SCOPE_TABLE_ROW *row = find_symbol_stack(table_stack, symbol);

                if(row == NULL)
                {
                        printf("ERROR AT LINE %d. EXITING WITH CODE: %d  (FUNCTION NOT YET DECLARED!). FUNCTION NAME: %s.\n", $1->line_number, ERR_UNDECLARED, symbol);
                        exit(ERR_UNDECLARED);
                }
                else
                {
                        char *nature = "função";
                        int is_equal = strcmp(row->nature, nature);
                        if(is_equal != 0)
                        {
                                printf("ERROR AT LINE %d. EXITING WITH CODE: %d (VARIABLE BEING CALLED AS FUNCTION!). VARIABLE NAME: %s.\n", $1->line_number, ERR_VARIABLE, symbol);
                                exit(ERR_UNDECLARED);
                        }
                }

                char call[] = "call ";
                $$ = ast_new(strcat(call, $1->token_value), row->data_type); 
                ast_add_child($$, $3); 
        }
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
        TK_PR_RETURN expressao 
        { 
                $$ = ast_new($1->token_value, $2->type); 
                ast_add_child($$, $2); 
        }
        ;

controle_fluxo:
        bloco_if_else { $$ = $1; }
        | bloco_while { $$ = $1; }
        ;

bloco_if_else:
        bloco_if bloco_else {  $$ = $1; if($2 != NULL){ ast_add_child($$, $2); } }
        ;

bloco_if:
        TK_PR_IF '(' expressao ')' bloco_comandos 
        { 
                $$ = ast_new($1->token_value, $3->type); 
                ast_add_child($$, $3); 
                if($5 != NULL)
                { 
                        ast_add_child($$, $5); 
                } 
        }
        ;

bloco_else:
        TK_PR_ELSE bloco_comandos { $$ = $2; }
        | %empty { $$ = NULL; }
        ;

bloco_while:
        TK_PR_WHILE '(' expressao ')' bloco_comandos 
        { 
                $$ = ast_new($1->token_value, $3->type); 
                ast_add_child($$, $3); 
                ast_add_child($$, $5); 
        }
        ;

expressao:
        term0 { $$ = $1; }
        ;

term0:
        term0 TK_OC_OR term1 
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type($1->type, $3->type);
                $$ = ast_new($2->token_value, type);  
                ast_add_child($$, $1); 
                ast_add_child($$, $3); 
        }
        | term1 { $$ = $1; }
        ;

term1:
        term1 TK_OC_AND term2 
        {
                char *type = malloc(sizeof (char*));
                type = calc_type($1->type, $3->type);
                $$ = ast_new($2->token_value, type);  
                ast_add_child($$, $1); 
                ast_add_child($$, $3); 
        }
        | term2 { $$ = $1; }
        ;

term2:
        term2 TK_OC_EQ term4 
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type($1->type, $3->type);
                $$ = ast_new($2->token_value, type);  
                ast_add_child($$, $1); 
                ast_add_child($$, $3); 
        }
        | term2 TK_OC_NE term4 
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type($1->type, $3->type);
                $$ = ast_new($2->token_value, type);  
                ast_add_child($$, $1); 
                ast_add_child($$, $3); 
        }
        | term4 { $$ = $1; }
        ;

term4:
        term4 '<' term8 
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type($1->type, $3->type);
                $$ = ast_new($2->token_value, type);  
                ast_add_child($$, $1); 
                ast_add_child($$, $3); 
        }
        | term4 '>' term8 
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type($1->type, $3->type);
                $$ = ast_new($2->token_value, type);  
                ast_add_child($$, $1); 
                ast_add_child($$, $3); 
        }
        | term4 TK_OC_LE term8 
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type($1->type, $3->type);
                $$ = ast_new($2->token_value, type);  
                ast_add_child($$, $1); 
                ast_add_child($$, $3); 
        }
        | term4 TK_OC_GE term8 
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type($1->type, $3->type);
                $$ = ast_new($2->token_value, type);  
                ast_add_child($$, $1); 
                ast_add_child($$, $3); 
        }
        | term8 { $$ = $1; }
        ;

term8:
        term8 '+' term10 
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type($1->type, $3->type);
                $$ = ast_new($2->token_value, type); 
                ast_add_child($$, $1); 
                ast_add_child($$, $3); 
        }
        | term8 '-' term10 
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type($1->type, $3->type);
                $$ = ast_new($2->token_value, type); 
                ast_add_child($$, $1); 
                ast_add_child($$, $3); 
        }
        | term10 { $$ = $1; }
        ;


term10:
        term10 '*' term13 
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type($1->type, $3->type);
                $$ = ast_new($2->token_value, type); 
                ast_add_child($$, $1); 
                ast_add_child($$, $3); 
        }
        | term10 '/' term13 
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type($1->type, $3->type);
                $$ = ast_new($2->token_value, type); 
                ast_add_child($$, $1); 
                ast_add_child($$, $3); 
        }
        | term10 '%' term13 
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type($1->type, $3->type);
                $$ = ast_new($2->token_value, type); 
                ast_add_child($$, $1); 
                ast_add_child($$, $3); 
        }
        | term13 { $$ = $1; }
        ;

term13:  
        '-' term13 { $$ = ast_new($1->token_value, $2->type); ast_add_child($$, $2); }
        | '!' term13 { $$ = ast_new($1->token_value, $2->type); ast_add_child($$, $2); }
        | term14 { $$ = $1; }
        ;

term14:
        '(' expressao ')' { $$ = $2; }
        | chamada_funcao { $$ = $1; }
        | operando { $$ = $1; }
        ;

operando:
        TK_IDENTIFICADOR 
        { 
                char *symbol = $1->token_value;

                T_SCOPE_TABLE_ROW *row = find_symbol_stack(table_stack, symbol);

                if(row == NULL)
                {
                        printf("ERROR AT LINE %d. EXITING WITH CODE: %d (VARIABLE NOT YET DECLARED!). VARIABLE NAME: %s.\n", $1->line_number, ERR_UNDECLARED, symbol);
                        exit(ERR_UNDECLARED);
                }
                else
                {
                        char *nature = "identificador";
                        int is_equal = strcmp(row->nature, nature);
                        if(is_equal != 0)
                        {
                                printf("ERROR AT LINE %d. EXITING WITH CODE: %d (FUNCTION BEING USED AS VARIABLE!). FUNCTION NAME: %s.\n", $1->line_number, ERR_FUNCTION, symbol);
                                exit(ERR_UNDECLARED);
                        }
                }

                $$ = ast_new($1->token_value, row->data_type); 
        }
        | TK_LIT_FALSE 
        { 
                char *type = "bool";
                $$ = ast_new($1->token_value, type);
                int line_num = $1->line_number;
                char *nature = "literal";
                int stack_idx = (table_stack->tables_number) - 1;
                T_SCOPE_TABLE* stack_top = table_stack->tables[stack_idx];

                char *string = $1->token_value;

                T_SCOPE_TABLE_ROW *prev_row = find_value_stack(table_stack, string);

                char *key = (char*) calloc(1, sizeof (char*));
                strcpy(key, string);

                if(prev_row == NULL)
                {
                        char *key_val = "#0";

                        strcat(key, key_val);
                }
                else
                {
                        char *key_val;
                        char del[2] = "#";
                        char *row_val = prev_row->symbol;
                        char *val_cpy = (char*) calloc(1, sizeof (char*));
                        strcpy(val_cpy, row_val);
                        key_val = strtok(val_cpy, del);
                        key_val = strtok(NULL, del);

                        int next_val = atoi(key_val) + 1;
                        sprintf(key_val, "%d", next_val);

                        char new_key[3] = {'#'};
                        strcat(new_key, key_val);
                        strcat(key, new_key);
                }

                T_SCOPE_TABLE_ROW *row = create_row(line_num, key, nature, type, string);
                stack_top = add_row(stack_top, row);
                
                table_stack->tables[stack_idx] = stack_top;
        }
        | TK_LIT_TRUE 
        { 
                char *type = "bool";
                $$ = ast_new($1->token_value, type); 

                int line_num = $1->line_number;
                char *nature = "literal";
                int stack_idx = (table_stack->tables_number) - 1;
                T_SCOPE_TABLE* stack_top = table_stack->tables[stack_idx];

                char *string = $1->token_value;

                T_SCOPE_TABLE_ROW *prev_row = find_value_stack(table_stack, string);

                char *key = (char*) calloc(1, sizeof (char*));
                strcpy(key, string);

                if(prev_row == NULL)
                {
                        char *key_val = "#0";

                        strcat(key, key_val);
                }
                else
                {
                        char *key_val;
                        char del[2] = "#";
                        char *row_val = prev_row->symbol;
                        char *val_cpy = (char*) calloc(1, sizeof (char*));
                        strcpy(val_cpy, row_val);
                        key_val = strtok(val_cpy, del);
                        key_val = strtok(NULL, del);

                        int next_val = atoi(key_val) + 1;
                        sprintf(key_val, "%d", next_val);

                        char new_key[3] = {'#'};
                        strcat(new_key, key_val);
                        strcat(key, new_key);
                }

                T_SCOPE_TABLE_ROW *row = create_row(line_num, key, nature, type, string);
                stack_top = add_row(stack_top, row);
                
                table_stack->tables[stack_idx] = stack_top;
        }
        | TK_LIT_INT 
        { 
                char *type = "int";
                $$ = ast_new($1->token_value, type); 

                int line_num = $1->line_number;
                char *nature = "literal";
                int stack_idx = (table_stack->tables_number) - 1;
                T_SCOPE_TABLE* stack_top = table_stack->tables[stack_idx];

                char *string = $1->token_value;

                T_SCOPE_TABLE_ROW *prev_row = find_value_stack(table_stack, string);

                char *key = (char*) calloc(1, sizeof (char*));
                strcpy(key, string);

                if(prev_row == NULL)
                {
                        char *key_val = "#0";

                        strcat(key, key_val);
                }
                else
                {
                        char *key_val;
                        char del[2] = "#";
                        char *row_val = prev_row->symbol;
                        char *val_cpy = (char*) calloc(1, sizeof (char*));
                        strcpy(val_cpy, row_val);
                        key_val = strtok(val_cpy, del);
                        key_val = strtok(NULL, del);

                        int next_val = atoi(key_val) + 1;
                        sprintf(key_val, "%d", next_val);

                        char new_key[3] = {'#'};
                        strcat(new_key, key_val);
                        strcat(key, new_key);
                }

                T_SCOPE_TABLE_ROW *row = create_row(line_num, key, nature, type, string);
                stack_top = add_row(stack_top, row);
                
                table_stack->tables[stack_idx] = stack_top;
        }
        | TK_LIT_FLOAT 
        { 
                char *type = "float";
                $$ = ast_new($1->token_value, type); 

                int line_num = $1->line_number;
                char *nature = "literal";
                int stack_idx = (table_stack->tables_number) - 1;
                T_SCOPE_TABLE* stack_top = table_stack->tables[stack_idx];

                char *string = $1->token_value;

                T_SCOPE_TABLE_ROW *prev_row = find_value_stack(table_stack, string);

                char *key = (char*) calloc(1, sizeof (char*));
                strcpy(key, string);

                if(prev_row == NULL)
                {
                        char *key_val = "#0";

                        strcat(key, key_val);
                }
                else
                {
                        char *key_val;
                        char del[2] = "#";
                        char *row_val = prev_row->symbol;
                        char *val_cpy = (char*) calloc(1, sizeof (char*));
                        strcpy(val_cpy, row_val);
                        key_val = strtok(val_cpy, del);
                        key_val = strtok(NULL, del);

                        int next_val = atoi(key_val) + 1;
                        sprintf(key_val, "%d", next_val);

                        char new_key[3] = {'#'};
                        strcat(new_key, key_val);
                        strcat(key, new_key);
                }

                T_SCOPE_TABLE_ROW *row = create_row(line_num, key, nature, type, string);
                stack_top = add_row(stack_top, row);
                
                table_stack->tables[stack_idx] = stack_top;
        }
        ;

abrir_escopo:
        %empty
        {
                table_stack = add_table(table_stack);
                // printf("***--***--***\n");
                // printf("ESCOPO CRIADO\n");
                // printf("NÚMERO DE TABELAS NA PILHA: %d\n", table_stack->tables_number);
                // printf("***--***--***\n");
        }
        ;

fechar_escopo:
        %empty
        {
                print_stack(table_stack);
                // printf("***--***--***\n");
                // printf("ESCOPO FECHADO\n");
                // printf("NÚMERO DE TABELAS NA PILHA: %d\n", table_stack->tables_number - 1);
                // printf("***--***--***\n");
                table_stack = pop_table(table_stack);
        }
        ;

%%
