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

T_STRING_LIST *create_string_list()
{
  T_STRING_LIST *string_List = (T_STRING_LIST*) calloc(1, sizeof (int));
  string_List->strings_number = 0;

  return string_List;
}

T_STRING_LIST *add_string(T_STRING_LIST *list, char *string)
{
  int strings_number = list->strings_number + 1;
  list = (T_STRING_LIST*) realloc(list, sizeof (int) + (sizeof (char*))*strings_number);
  list->strings[strings_number - 1] = string;
  list->strings_number = strings_number;

  return list;
}

