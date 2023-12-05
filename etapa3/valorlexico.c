/*
AUTORES:
GABRIEL PIRES E PEIXOTTO - 00326403
JOÃO DAVI M NUNES - 00285639
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "valorlexico.h"

VL *vl_new(int line_number, int token_type, char *token_value){
    VL *valor_lexico = NULL;
    valor_lexico = calloc(1, sizeof(VL));
    if (valor_lexico != NULL){
      valor_lexico->line_number = line_number;
      valor_lexico->token_type = token_type;
      valor_lexico->token_value = strdup(token_value);
    }
    return valor_lexico;
}