/*
AUTORES:
GABRIEL PIRES E PEIXOTTO - 00326403
JOÃO DAVI M NUNES - 00285639
*/

#ifndef ILOC_HEADER
#define ILOC_HEADER

extern int curr_temp;
extern int curr_label;

typedef enum {
    LTE = 1,
    GTE = 2,
    EQU = 3,
    NEQ = 4,
    AND = 5,
    ORR = 6,
    NOT = 7,
    SUB = 8,
    MUL = 9,
    DIV = 10,
    SUM = 11,
    LTH = 12,
    GTH = 13,
    ASG = 14,
    IFF = 15,
    JMP = 16,
    LOD = 17,
    LBL = 18,
    INT = 19
} CODE_OPTION;

typedef struct iloc_arg {
    /*
    TYPE:
        - -1: NULL ARG
        -  0: Constant
        -  1: Temporary
        -  2: Label
    */
    int type;
    /*
    Address or temporary value of the argument
    SPECIAL VALUES:
        - -3: RFP
        - -2: RBSS
        - -1: NULL ARG
    
    RESERVED VALUES FOR TEMPORARIES:
        0, 1 and 2.
    */
    int value;
} iloc_arg;

typedef struct iloc_op {
    char *opcode;
    iloc_arg arg_1;
    iloc_arg arg_2;
    iloc_arg arg_3;
} iloc_op;

typedef struct iloc_code {
    int num_ops;
    iloc_op *ops[];
} iloc_code;

/*
Appends an iloc operation to an iloc code object
*/
iloc_code *append_op(iloc_code *code, iloc_op *op);

/*
Appends an iloc code block to another one
*/
iloc_code *append_code(iloc_code *base_code, iloc_code *new_code);

void print_code(iloc_code *code);

/*
Generates a new code object based on an code enum and
a list of arguments
See implementation for code_option values
*/
iloc_code *generate_iloc_code(CODE_OPTION code_option, iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3);

iloc_code *generate_1_arg_iloc_code(CODE_OPTION code_option, iloc_arg arg_1);

iloc_code *generate_2_arg_iloc_code(CODE_OPTION code_option, iloc_arg arg_1, iloc_arg arg_2);

int get_temp();

int get_label();

iloc_arg get_null_arg();

#endif //ILOC_HEADER