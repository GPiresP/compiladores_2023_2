#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "iloc.h"
#include "controlflowgraph.h"

int get_code_buffer_size(iloc_code *code)
{
    return 30*code->num_ops;
}

int get_key_buffer_size(int key_num)
{
    return sizeof(char)*((int)log10(key_num)+1);
};

control_flow_node *control_flow_node_new(char *code, char *key)
{
    control_flow_node *ret = NULL;
    ret = calloc(1, sizeof(control_flow_node));
    ret->code = code;
    ret->key = strdup(key);
    ret->num_relations = 0;

    return ret;
};

control_flow_graph *control_flow_graph_new()
{
    control_flow_graph *ret = NULL;
    ret = calloc(1, sizeof(control_flow_graph));
    ret->num_nodes = 0;

    return ret;
};

control_flow_node *add_node_relation(control_flow_node *node, char *relation_key)
{
    node->num_relations = node->num_relations + 1;

    node = realloc(node, sizeof(control_flow_node) + sizeof(char *)*(node->num_relations));
    node->relations[node->num_relations - 1] = strdup(relation_key);

    return node;
};

control_flow_graph *add_control_flow_node(control_flow_graph *graph, control_flow_node *node)
{
    graph->num_nodes = graph->num_nodes + 1;

    graph = realloc(graph, sizeof(control_flow_graph) + sizeof(control_flow_node)*(graph->num_nodes));
    graph->nodes[graph->num_nodes - 1] = node;

    return graph;
};

control_flow_graph *parse_control_flow_graph(iloc_code *code)
{
    if(code != NULL)
    {
        int i, num_ops = code->num_ops;
        int is_next_op_leader = 4;
        int current_block = 1;
        int current_node_idx = 0;

        //Stores a label after it is found
        int last_label_val;
        //Stores target label of a jump
        int last_target_label;
        //Stores true label of a cbr
        int last_true_label;
        //Stores false label of a cbr
        int last_false_label;
        
        //Key is a special char + a number
        char *key_buffer = NULL;
        char *current_opcode = NULL;
        char *code_buffer = NULL;

        iloc_code *current_code_block = iloc_code_new();
        iloc_op *current_op = NULL;
        control_flow_graph *graph = control_flow_graph_new();
        control_flow_node *current_node = NULL;

        for(i = 0; i < num_ops; i++)
        {
            current_op = code->ops[i];
            current_opcode = current_op->opcode;

            //If this op was marked as a leader,
            //start a new code block
            if(is_next_op_leader > 0)
            {
                //Create a new node on graph
                //New block after a jump
                if(is_next_op_leader == 1)
                {
                    //Close current block
                    code_buffer = malloc(get_code_buffer_size(current_code_block));
                    print_code(current_code_block, code_buffer);

                    current_node->code = strdup(code_buffer);

                    //Add relations
                    key_buffer = malloc(get_key_buffer_size(last_target_label));
                    sprintf(key_buffer, "L%d", last_target_label);
                    current_node = add_node_relation(current_node, key_buffer);

                    graph->nodes[current_node_idx] = current_node;
                    current_node_idx = current_node_idx + 1;

                    //Start a new node               
                    key_buffer = malloc(get_key_buffer_size(current_block));

                    sprintf(key_buffer, "J%d", current_block);
                    current_node = control_flow_node_new(NULL, key_buffer);
                    current_block += 1;

                    current_code_block = iloc_code_new();

                    //Add node to graph
                    graph = add_control_flow_node(graph, current_node);
                }
                //New block after a cbr
                else if(is_next_op_leader == 2)
                {
                    //Close current block
                    code_buffer = malloc(get_code_buffer_size(current_code_block));
                    print_code(current_code_block, code_buffer);

                    current_node->code = strdup(code_buffer);

                    //Add relations
                    key_buffer = malloc(get_key_buffer_size(last_true_label));
                    sprintf(key_buffer, "L%d", last_true_label);
                    current_node = add_node_relation(current_node, key_buffer);

                    key_buffer = malloc(get_key_buffer_size(last_false_label));
                    sprintf(key_buffer, "L%d", last_false_label);
                    current_node = add_node_relation(current_node, key_buffer);

                    graph->nodes[current_node_idx] = current_node;
                    current_node_idx = current_node_idx + 1;

                    //Start a new node               
                    key_buffer = malloc(get_key_buffer_size(current_block));

                    sprintf(key_buffer, "C%d", current_block);
                    current_node = control_flow_node_new(NULL, key_buffer);
                    current_block += 1;

                    current_code_block = iloc_code_new();

                    //Add node to graph
                    graph = add_control_flow_node(graph, current_node);
                }
                //New block after a label
                else if(is_next_op_leader == 3)
                {
                    //Close current block
                    code_buffer = malloc(get_code_buffer_size(current_code_block));
                    print_code(current_code_block, code_buffer);

                    current_node->code = strdup(code_buffer);

                    //Add relations
                    key_buffer = malloc(get_key_buffer_size(last_label_val));
                    sprintf(key_buffer, "L%d", last_label_val);
                    current_node = add_node_relation(current_node, key_buffer);

                    graph->nodes[current_node_idx] = current_node;
                    current_node_idx = current_node_idx + 1;

                    //Start a new node               
                    current_node = control_flow_node_new(NULL, key_buffer);

                    current_code_block = iloc_code_new();

                    //Add node to graph
                    graph = add_control_flow_node(graph, current_node);
                }
                //First op in code
                else if(is_next_op_leader == 4)
                {
                    key_buffer = malloc(get_key_buffer_size(current_block));
                    sprintf(key_buffer, "S%d", current_block);
                    current_block += 1;

                    current_node = control_flow_node_new(NULL, key_buffer);

                    //Add node to graph
                    graph = add_control_flow_node(graph, current_node);
                }

                is_next_op_leader = 0;
            }

            //Check if the next op will be a leader
            if(strcmp(current_opcode, "jumpI") == 0)
            {
                is_next_op_leader = 1;
                last_target_label = current_op->arg_1.value;
                current_code_block = append_op(current_code_block, current_op);
            }
            else if(strcmp(current_opcode, "cbr") == 0)
            {
                is_next_op_leader = 2;
                last_true_label = current_op->arg_2.value;
                last_false_label = current_op->arg_3.value;
                current_code_block = append_op(current_code_block, current_op);
            }
            else if(strcmp(current_opcode, "label") == 0)
            {
                is_next_op_leader = 3;
                last_label_val = current_op->arg_1.value;
            }
            else
            {
                current_code_block = append_op(current_code_block, current_op);
            }
        }
        code_buffer = malloc(get_code_buffer_size(current_code_block));
        print_code(current_code_block, code_buffer);

        current_node->code = strdup(code_buffer);

        graph->nodes[current_node_idx] = current_node;

        return graph;
    }

    return NULL;
};

void print_graph_to_dot(control_flow_graph *graph)
{
    int i, j;
    control_flow_node *current_node;

    printf("digraph g {\n");
    printf("\t{\n");
    printf("\t\tnode [shape=square]\n");

    for(i = 0; i < graph->num_nodes; i++)
    {
        current_node = graph->nodes[i];

        printf("\t\tnode%s[label=\"BLOCK %s\n\n%s\"]\n", current_node->key, current_node->key, current_node->code);
    }

    printf("\t}\n");

    for(i = 0; i < graph->num_nodes; i++)
    {
        current_node = graph->nodes[i];

        if(current_node->num_relations > 0)
        {
            printf("\tnode%s -> {", current_node->key);

            for(j = 0; j < current_node->num_relations; j++)
            {
                printf("node%s ", current_node->relations[j]);
            }

            printf(" }\n");
        }
    }

    printf("}\n");
};