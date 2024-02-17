/*
AUTORES:
GABRIEL PIRES E PEIXOTTO - 00326403
JOÃO DAVI M NUNES - 00285639
*/

#ifndef CONTROLFLOWGRAPH_HEADER
#define CONTROLFLOWGRAPH_HEADER

#include "iloc.h"

typedef struct control_flow_node {
    char *key;
    int num_relations;
    char *code;
    char *relations[];
} control_flow_node;

typedef struct control_flow_graph {
    int num_nodes;
    control_flow_node *nodes[];
} control_flow_graph;

control_flow_graph *parse_control_flow_graph(iloc_code *code);

void print_graph_to_dot(control_flow_graph *graph);

#endif //CONTROLFLOWGRAPH_HEADER