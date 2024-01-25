/*
AUTORES:
GABRIEL PIRES E PEIXOTTO - 00326403
JOÃO DAVI M NUNES - 00285639
*/

#ifndef ILOC_HEADER
#define ILOC_HEADER

typedef union iloc_arg_union {
    int i;
    char *c;
} iloc_arg_union;

typedef struct iloc_arg {
    /*
    TYPE:
        - 0: Constant
        - 1: Address
    */
    int type;
    /*
    Address or constant value of the argument
    */
    int value;
} iloc_arg;

typedef struct iloc_func {
    /*
    Operation code of the function
    */
    char *opcode;
    /*
    Pointer to next function of the program
    */
    struct iloc_func *next_func;
    /*
    Function arguments array. 
    Arguments are int or char*, representing either address values, constant values or register names.
    If it has less than 3 arguments, remaining ones are NULL
    */
    iloc_arg_union args[3];
} iloc_func;

/*
Generates a new function object based on an opcode and
a list of arguments
See implementation for func_code values
*/
iloc_func *generate_func(int func_code, iloc_arg *arg_1, iloc_arg *arg_2, iloc_arg *arg_3);

#endif //ILOC_HEADER