/*
AUTORES:
GABRIEL PIRES E PEIXOTTO - 00326403
JOÃO DAVI M NUNES - 00285639
*/

#ifndef AST_HEADER
#define AST_HEADER

typedef struct ast_node {
    char *label;
    char *type;
    int number_of_children;
    struct ast_node **children;
} AST;

AST *ast_new(const char *label, char *type);

void ast_add_child(AST *tree, AST *child);
void exporta (AST *tree);

char* calc_type(char *type_one, char *type_two);

#endif //AST_HEADER