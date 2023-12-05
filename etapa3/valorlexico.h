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

VL *vl_new(int line_number, int token_type, char *token_value);

#endif //VL_HEADER