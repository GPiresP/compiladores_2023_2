/*
AUTORES:
GABRIEL PIRES E PEIXOTTO - 00326403
JOÃO DAVI M NUNES - 00285639
*/

#include "iloc.h"

iloc_func *iloc_func_new(const char *opcode)
{
    iloc_func *ret = NULL;

    ret = calloc(1, sizeof(iloc_func));

    ret->opcode = strdup(opcode);
    ret->next_func = NULL;
    ret->args[0] = NULL;
    ret->args[1] = NULL;
    ret->args[2] = NULL;

    return ret;
};

iloc_func *generate_load(iloc_arg *arg, char *reg)
{
    iloc_func *ret = NULL;

    if(arg->type == 0)
    {
        char *loadI = "loadI";

        ret = iloc_func_new(loadI);
    }
    else
    {
        char *load = "load";

        ret = iloc_func_new(load);
    }

    ret->args[0].i = arg->value;
    ret->args[1].c = reg;
};

iloc_func *generate_sum(iloc_arg *l_sum, iloc_arg *r_sum, iloc_arg *t_sum)
{
    char *r0 = "r0";
    char *r1 = "r1";

    iloc_func *load_arg_1 = generate_load(l_sum, r0);
    iloc_func *load_arg_2 = generate_load(r_sum, r1);

};

iloc_func *generate_func(int func_code, iloc_arg *arg_1, iloc_arg *arg_2, iloc_arg *arg_3)
{
    switch(func_code)
    {
        //Less or equal then: <=
        case 1:
            break;

        //Greater or equal then: >=
        case 2:
            break;

        //Equal
        case 3:
            break;

        //Not equal: !=
        case 4:
            break;

        //And: &
        case 5:
            break;

        //Or: |
        case 6:
            break;

        //Not: !
        case 7:
            break;

        //Minus: -
        case 8:
            break;

        //Times: *
        case 9:
            break;

        //Division: /
        case 10:
            break;

        //Sum: +
        case 11:
            break;

        //Less than: <
        case 12:
            break;

        //Greater than: >
        case 13:
            break;

        //Assignment: =
        case 14:
            break;

        //If: if
        case 15:
            break;

        //While: while
        case 16:
            break;

        //return: return
        case 17:
            break;

        //Invalid argument
        default:
    }
};
