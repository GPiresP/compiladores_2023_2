/*
AUTORES:
GABRIEL PIRES E PEIXOTTO - 00326403
JOÃO DAVI M NUNES - 00285639
*/

#ifndef VL_HEADER
#define VL_HEADER

typedef struct valor_lexico {
    int line_number;
    int token_type;
    char *token_value;
} VL;

typedef struct string_list {
    int strings_number;
    char *strings[];
} T_STRING_LIST;

VL *vl_new(int line_number, int token_type, char *token_value);

T_STRING_LIST *create_string_list();

T_STRING_LIST *add_string(T_STRING_LIST *list, char *string);

#endif //VL_HEADER