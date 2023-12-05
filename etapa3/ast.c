/*
AUTORES:
GABRIEL PIRES E PEIXOTTO - 00326403
JOÃO DAVI M NUNES - 00285639
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ast.h"
#define ARQUIVO_SAIDA "saida.dot"

AST *ast_new(const char *label){
    AST *ret = NULL;
    ret = calloc(1, sizeof(AST));

    if (ret != NULL){
        ret->label = strdup(label);
        ret->number_of_children = 0;
        ret->children = NULL;
    }

    return ret;
}

void ast_add_child(AST *tree, AST *child){
    if (tree != NULL && child != NULL){
        tree->number_of_children++;
        tree->children = realloc(tree->children, tree->number_of_children * sizeof(AST*));
        tree->children[tree->number_of_children-1] = child;
    }else{
        fprintf(stderr, "Erro: %s recebeu parâmetro tree = %p / %p.\n", __FUNCTION__, tree, child);
    }
}

void exporta (AST *tree){
    if (tree != NULL) {
        printf("%p [label=\"%s\"];\n", (void*)tree, tree->label);

        for (int i = 0; i < tree->number_of_children; ++i) {
            printf("%p, %p\n", (void*)tree, (void*)tree->children[i]);
            exporta(tree->children[i]);
        }
    }
}
