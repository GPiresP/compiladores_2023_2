/*
AUTORES:
GABRIEL PIRES E PEIXOTTO - 00326403
JOÃO DAVI M NUNES - 00285639
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "iloc.h"

/*
--------------------------------------------------
--------------- OTHER FUNCTIONS ------------------
--------------------------------------------------
*/

int curr_temp = 3;

int get_temp()
{
    return curr_temp++;
};

int curr_label = 1;

int get_label()
{
    return curr_label++;
};

iloc_arg get_null_arg()
{
    iloc_arg arg;
    arg.type = -1;
    arg.value = -1;

    return arg;
};

/*
--------------------------------------------------
----------- BASIC OBJECT CONSTRUCTORS ------------
--------------------------------------------------
*/

iloc_op *iloc_op_new(const char *opcode)
{
    iloc_op *ret = NULL;

    ret = calloc(1, sizeof(iloc_op));

    ret->opcode = strdup(opcode);

    iloc_arg null_arg;
    null_arg.type = -1;
    null_arg.value = -1;

    ret->arg_1 = null_arg;
    ret->arg_2 = null_arg;
    ret->arg_3 = null_arg;

    return ret;
};

iloc_code *iloc_code_new()
{
    iloc_code *ret = NULL;
    ret = calloc(1, sizeof(iloc_code));
    ret->num_ops = 0;

    return ret;
}

//****************************************************************************************************

/*
--------------------------------------------------
------------ BASIC OBJECT UTILITIES --------------
--------------------------------------------------
*/

void print_code(iloc_code *code)
{
    if(code != NULL)
    {
        int i, num_ops = code->num_ops;

        printf("*******************************\n");
        printf("***** PRINTING CODE BLOCK *****\n");
        printf("*******************************\n");

        for(i = 0; i < num_ops; i++)
        {
            printf("%d:\t%s\t %d %d %d\n", i, code->ops[i]->opcode, code->ops[i]->arg_1.value, code->ops[i]->arg_2.value, code->ops[i]->arg_3.value);
        }

        printf("*******************************\n");
    }
};

iloc_code *append_op(iloc_code *code, iloc_op *op)
{
    code->num_ops++;

    code = realloc(code, sizeof(iloc_code) + sizeof(iloc_op)*code->num_ops);

    code->ops[code->num_ops - 1] = op;

    return code;
};

iloc_code *append_code(iloc_code *base_code, iloc_code *new_code)
{
    if(new_code != NULL && base_code != NULL)
    {
        int i;

        int old_size = base_code->num_ops;

        base_code->num_ops += new_code->num_ops;

        base_code = realloc(base_code, sizeof(iloc_code) + sizeof(iloc_op)*base_code->num_ops);

        for(i = 0; i < new_code->num_ops; i++)
        {
            base_code->ops[old_size + i] = new_code->ops[i]; 
        }
    }

    return base_code;
};

//****************************************************************************************************

/*
--------------------------------------------------
------------ ILOC OPERATION GENERATORS -----------
--------------------------------------------------
*/

iloc_op *generate_0_arg_iloc_op(char *opcode)
{
    iloc_op *op = iloc_op_new(opcode);

    return op;    
};


iloc_op *generate_1_arg_iloc_op(char *opcode, iloc_arg arg_1)
{
    iloc_op *op = iloc_op_new(opcode);
    op->arg_1 = arg_1;

    return op;    
};

iloc_op *generate_2_arg_iloc_op(char *opcode, iloc_arg arg_1, iloc_arg arg_2)
{
    iloc_op *op = iloc_op_new(opcode);
    op->arg_1 = arg_1;
    op->arg_2 = arg_2;

    return op;    
};


iloc_op *generate_3_arg_iloc_op(char *opcode, iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    iloc_op *op = iloc_op_new(opcode);
    op->arg_1 = arg_1;
    op->arg_2 = arg_2;
    op->arg_3 = arg_3;

    return op;    
};

/*
--------------------------------------------------
----------------- NOP GENERATORS -----------------
--------------------------------------------------
*/

iloc_op *generate_nop()
{
    return generate_0_arg_iloc_op("nop");
};

/*
--------------------------------------------------
----------------- LABEL GENERATORS ---------------
--------------------------------------------------
*/

iloc_op *generate_label(iloc_arg arg_1)
{
    return generate_1_arg_iloc_op("label", arg_1);
};

/*
--------------------------------------------------
----------------- CBR GENERATORS -----------------
--------------------------------------------------
*/

iloc_op *generate_cbr(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("cbr", arg_1, arg_2, arg_3);
};

/*
--------------------------------------------------
----------------- JUMP GENERATORS ----------------
--------------------------------------------------
*/

iloc_op *generate_jumpI(iloc_arg arg_1)
{
    return generate_1_arg_iloc_op("jumpI", arg_1);
};

/*
--------------------------------------------------
----------------- ADD GENERATORS -----------------
--------------------------------------------------
*/

iloc_op *generate_add(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("add", arg_1, arg_2, arg_3);
};

iloc_op *generate_addI(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("addI", arg_1, arg_2, arg_3);
};

/*
--------------------------------------------------
------------------ SUB GENERATORS ----------------
--------------------------------------------------
*/

iloc_op *generate_sub(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("sub", arg_1, arg_2, arg_3);
};

iloc_op *generate_subI(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("subI", arg_1, arg_2, arg_3);
};

iloc_op *generate_rsubI(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("rsubI", arg_1, arg_2, arg_3);
};

/*
--------------------------------------------------
----------------- MULT GENERATORS ----------------
--------------------------------------------------
*/

iloc_op *generate_mult(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("mult", arg_1, arg_2, arg_3);
};

iloc_op *generate_multI(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("multI", arg_1, arg_2, arg_3);
};

/*
--------------------------------------------------
----------------- DIV GENERATORS ----------------
--------------------------------------------------
*/

iloc_op *generate_div(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("div", arg_1, arg_2, arg_3);
};

iloc_op *generate_divI(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("divI", arg_1, arg_2, arg_3);
};

iloc_op *generate_rdivI(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("rdivI", arg_1, arg_2, arg_3);
};

/*
--------------------------------------------------
----------------- AND GENERATORS ----------------
--------------------------------------------------
*/

iloc_op *generate_and(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("and", arg_1, arg_2, arg_3);
};

iloc_op *generate_andI(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("andI", arg_1, arg_2, arg_3);
};

/*
--------------------------------------------------
----------------- OR GENERATORS ----------------
--------------------------------------------------
*/

iloc_op *generate_or(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("or", arg_1, arg_2, arg_3);
};

iloc_op *generate_orI(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("orI", arg_1, arg_2, arg_3);
};

/*
--------------------------------------------------
----------------- XOR GENERATORS ----------------
--------------------------------------------------
*/

iloc_op *generate_xorI(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("xorI", arg_1, arg_2, arg_3);
};

/*
--------------------------------------------------
----------------- CMP GENERATORS ----------------
--------------------------------------------------
*/

iloc_op *generate_cmp_LE(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("cmp_LE", arg_1, arg_2, arg_3);
};

iloc_op *generate_cmp_GE(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("cmp_GE", arg_1, arg_2, arg_3);
};

iloc_op *generate_cmp_EQ(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("cmp_EQ", arg_1, arg_2, arg_3);
};

iloc_op *generate_cmp_NE(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("cmp_NE", arg_1, arg_2, arg_3);
};

iloc_op *generate_cmp_LT(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("cmp_LT", arg_1, arg_2, arg_3);
};

iloc_op *generate_cmp_GT(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("cmp_GT", arg_1, arg_2, arg_3);
};

/*
--------------------------------------------------
---------------- LOAD GENERATORS -----------------
--------------------------------------------------
*/

iloc_op *generate_loadAI(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("loadAI", arg_1, arg_2, arg_3);
};

iloc_op *generate_loadI(iloc_arg arg_1, iloc_arg arg_2)
{
    return generate_2_arg_iloc_op("loadI", arg_1, arg_2);

};

/*
--------------------------------------------------
---------------- STORE GENERATORS ----------------
--------------------------------------------------
*/

iloc_op *generate_storeAI(iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    return generate_3_arg_iloc_op("storeAI", arg_1, arg_2, arg_3);
};

//****************************************************************************************************

/*
--------------------------------------------------
---------------- CODE GENERATORS -----------------
--------------------------------------------------
*/

/*
--------------------------------------------------
------------- NOP CODE GENERATORS ----------------
--------------------------------------------------
*/

iloc_code *generate_nop_code()
{
    iloc_code *code = iloc_code_new();

    iloc_op* op = generate_nop();

    code = append_op(code, op);

    return code;
};

/*
--------------------------------------------------
------------- SUM CODE GENERATORS ----------------
--------------------------------------------------
*/

iloc_code *generate_reg_const_sum(iloc_arg l_sum, iloc_arg r_sum, iloc_arg t_sum)
{
    iloc_code *code = iloc_code_new();

    iloc_op *add_op = generate_addI(l_sum, r_sum, t_sum);

    code = append_op(code, add_op);

    return code;
};

iloc_code *generate_const_reg_sum(iloc_arg l_sum, iloc_arg r_sum, iloc_arg t_sum)
{
    return generate_reg_const_sum(r_sum, l_sum, t_sum);
};

iloc_code *generate_lr_const_sum(iloc_arg l_sum, iloc_arg r_sum, iloc_arg t_sum)
{
    iloc_arg temp;
    temp.type = 1;
    temp.value = 0;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op = generate_loadI(l_sum, temp);
    iloc_op *add_op = generate_addI(temp, r_sum, t_sum);

    code = append_op(code, load_op);
    code = append_op(code, add_op);

    return code;
};

iloc_code *generate_lr_reg_sum(iloc_arg l_sum, iloc_arg r_sum, iloc_arg t_sum)
{
    iloc_code *code = iloc_code_new();

    iloc_op *add_op = generate_add(l_sum, r_sum, t_sum);

    code = append_op(code, add_op);

    return code;  
};


iloc_code *generate_sum_code(iloc_arg l_sum, iloc_arg r_sum, iloc_arg t_sum)
{
    if(l_sum.type == 0)
    {
        //Constant + Constant
        if(r_sum.type == 0)
        {
            return generate_lr_const_sum(l_sum, r_sum, t_sum);
        }
        //Constant + Register
        else
        {
            return generate_const_reg_sum(l_sum, r_sum, t_sum);
        }
    }
    else
    {
        //Register + Constant
        if(r_sum.type == 0)
        {
            return generate_reg_const_sum(l_sum, r_sum, t_sum);
        }
        //Constant + Register
        else
        {
            return generate_lr_reg_sum(l_sum, r_sum, t_sum);
        }
    }
};

/*
--------------------------------------------------
--------------- SUB CODE GENERATORS --------------
--------------------------------------------------
*/

iloc_code *generate_lr_const_sub(iloc_arg l_val, iloc_arg r_val, iloc_arg t_sub)
{
    iloc_arg temp;
    temp.type = 1;
    temp.value = 0;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op = generate_loadI(l_val, temp);
    iloc_op *sub_op = generate_subI(temp, r_val, t_sub);

    code = append_op(code, load_op);
    code = append_op(code, sub_op);

    return code;
};

iloc_code *generate_reg_const_sub(iloc_arg l_val, iloc_arg r_val, iloc_arg t_sub)
{
    iloc_code *code = iloc_code_new();

    iloc_op *sub_op = generate_subI(l_val, r_val, t_sub);

    code = append_op(code, sub_op);

    return code;
};

iloc_code *generate_const_reg_sub(iloc_arg l_val, iloc_arg r_val, iloc_arg t_sub)
{
    iloc_code *code = iloc_code_new();

    iloc_op *sub_op = generate_rsubI(r_val, l_val, t_sub);

    code = append_op(code, sub_op);

    return code;
};

iloc_code *generate_lr_reg_sub(iloc_arg l_val, iloc_arg r_val, iloc_arg t_sub)
{
    iloc_code *code = iloc_code_new();

    iloc_op *sub_op = generate_sub(l_val, r_val, t_sub);

    code = append_op(code, sub_op);

    return code;  
};

iloc_code *generate_sub_code(iloc_arg l_val, iloc_arg r_val, iloc_arg t_sub)
{
    if(l_val.type == 0)
    {
        //Constant + Constant
        if(r_val.type == 0)
        {
            return generate_lr_const_sub(l_val, r_val, t_sub);
        }
        //Constant + Register
        else
        {
            return generate_const_reg_sub(l_val, r_val, t_sub);
        }
    }
    else
    {
        //Register + Constant
        if(r_val.type == 0)
        {
            return generate_reg_const_sub(l_val, r_val, t_sub);
        }
        //Constant + Register
        else
        {
            return generate_lr_reg_sub(l_val, r_val, t_sub);
        }
    }
};

/*
--------------------------------------------------
-------------- MUL CODE GENERATORS ---------------
--------------------------------------------------
*/

iloc_code *generate_lr_const_mul(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_arg temp;
    temp.type = 1;
    temp.value = 0;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op = generate_loadI(l_val, temp);
    iloc_op *mul_op = generate_multI(temp, r_val, t_val);

    code = append_op(code, load_op);
    code = append_op(code, mul_op);

    return code;
};

iloc_code *generate_reg_const_mul(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_code *code = iloc_code_new();

    iloc_op *mul_op = generate_multI(l_val, r_val, t_val);

    code = append_op(code, mul_op);

    return code;
};

iloc_code *generate_const_reg_mul(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    return generate_reg_const_mul(r_val, l_val, t_val);
};

iloc_code *generate_lr_reg_mul(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_code *code = iloc_code_new();

    iloc_op *mul_op = generate_mult(l_val, r_val, t_val);

    code = append_op(code, mul_op);

    return code;  
};

iloc_code *generate_mul_code(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    if(l_val.type == 0)
    {
        //Constant + Constant
        if(r_val.type == 0)
        {
            return generate_lr_const_mul(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_const_reg_mul(l_val, r_val, t_val);
        }
    }
    else
    {
        //Register + Constant
        if(r_val.type == 0)
        {
            return generate_reg_const_mul(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_lr_reg_mul(l_val, r_val, t_val);
        }
    }
};

/*
--------------------------------------------------
-------------- DIV CODE GENERATORS ---------------
--------------------------------------------------
*/

iloc_code *generate_lr_const_div(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_arg temp;
    temp.type = 1;
    temp.value = 0;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op = generate_loadI(l_val, temp);
    iloc_op *div_op = generate_divI(temp, r_val, t_val);

    code = append_op(code, load_op);
    code = append_op(code, div_op);

    return code;
};

iloc_code *generate_reg_const_div(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_code *code = iloc_code_new();

    iloc_op *div_op = generate_divI(l_val, r_val, t_val);

    code = append_op(code, div_op);

    return code;
};

iloc_code *generate_const_reg_div(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_code *code = iloc_code_new();

    iloc_op *div_op = generate_rdivI(r_val, l_val, t_val);

    code = append_op(code, div_op);

    return code;
};

iloc_code *generate_lr_reg_div(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_code *code = iloc_code_new();

    iloc_op *div_op = generate_div(l_val, r_val, t_val);

    code = append_op(code, div_op);

    return code;  
};

iloc_code *generate_div_code(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    if(l_val.type == 0)
    {
        //Constant + Constant
        if(r_val.type == 0)
        {
            return generate_lr_const_div(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_const_reg_div(l_val, r_val, t_val);
        }
    }
    else
    {
        //Register + Constant
        if(r_val.type == 0)
        {
            return generate_reg_const_div(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_lr_reg_div(l_val, r_val, t_val);
        }
    }
};

/*
--------------------------------------------------
-------------- AND CODE GENERATORS ---------------
--------------------------------------------------
*/

iloc_code *generate_lr_const_and(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_arg temp;
    temp.type = 1;
    temp.value = 0;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op = generate_loadI(l_val, temp);
    iloc_op *and_op = generate_andI(temp, r_val, t_val);

    code = append_op(code, load_op);
    code = append_op(code, and_op);

    return code;
};

iloc_code *generate_reg_const_and(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_code *code = iloc_code_new();

    iloc_op *and_op = generate_andI(l_val, r_val, t_val);

    code = append_op(code, and_op);

    return code;
};

iloc_code *generate_const_reg_and(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    return generate_reg_const_and(r_val, l_val, t_val);
};

iloc_code *generate_lr_reg_and(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_code *code = iloc_code_new();

    iloc_op *and_op = generate_and(l_val, r_val, t_val);

    code = append_op(code, and_op);

    return code;  
};

iloc_code *generate_and_code(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    if(l_val.type == 0)
    {
        //Constant + Constant
        if(r_val.type == 0)
        {
            return generate_lr_const_and(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_const_reg_and(l_val, r_val, t_val);
        }
    }
    else
    {
        //Register + Constant
        if(r_val.type == 0)
        {
            return generate_reg_const_and(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_lr_reg_and(l_val, r_val, t_val);
        }
    }
};

/*
--------------------------------------------------
-------------- OR CODE GENERATORS ----------------
--------------------------------------------------
*/

iloc_code *generate_lr_const_or(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_arg temp;
    temp.type = 1;
    temp.value = 0;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op = generate_loadI(l_val, temp);
    iloc_op *or_op = generate_orI(temp, r_val, t_val);

    code = append_op(code, load_op);
    code = append_op(code, or_op);

    return code;
};

iloc_code *generate_reg_const_or(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_code *code = iloc_code_new();

    iloc_op *or_op = generate_orI(l_val, r_val, t_val);

    code = append_op(code, or_op);

    return code;
};

iloc_code *generate_const_reg_or(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    return generate_reg_const_or(r_val, l_val, t_val);
};

iloc_code *generate_lr_reg_or(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_code *code = iloc_code_new();

    iloc_op *or_op = generate_or(l_val, r_val, t_val);

    code = append_op(code, or_op);

    return code;  
};

iloc_code *generate_or_code(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    if(l_val.type == 0)
    {
        //Constant + Constant
        if(r_val.type == 0)
        {
            return generate_lr_const_or(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_const_reg_or(l_val, r_val, t_val);
        }
    }
    else
    {
        //Register + Constant
        if(r_val.type == 0)
        {
            return generate_reg_const_or(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_lr_reg_or(l_val, r_val, t_val);
        }
    }
};

/*
--------------------------------------------------
-------------- NOT CODE GENERATORS ----------------
--------------------------------------------------
*/

iloc_code *generate_const_not(iloc_arg s_val, iloc_arg t_val)
{
    iloc_arg max_arg;
    max_arg.type = 0;
    max_arg.value = INT_MAX;

    iloc_arg temp;
    temp.type = 1;
    temp.value = 0;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op = generate_loadI(s_val, temp);
    iloc_op *xor_op = generate_xorI(temp, max_arg, t_val);

    code = append_op(code, load_op);
    code = append_op(code, xor_op);

    return code;
};

iloc_code *generate_reg_not(iloc_arg s_val, iloc_arg t_val)
{
    iloc_arg max_arg;
    max_arg.type = 0;
    max_arg.value = INT_MAX;

    iloc_code *code = iloc_code_new();

    iloc_op *xor_op = generate_xorI(s_val, max_arg, t_val);

    code = append_op(code, xor_op);

    return code;
};

iloc_code *generate_not_code(iloc_arg s_val, iloc_arg t_val)
{
    //Constant
    if(s_val.type == 0)
    {
        return generate_const_not(s_val, t_val);
    }
    //Register
    else
    {
        return generate_reg_not(s_val, t_val);
    }
};

/*
--------------------------------------------------
-------------- LTE CODE GENERATORS ----------------
--------------------------------------------------
*/

iloc_code *generate_lr_const_lte(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_arg temp0;
    temp0.type = 1;
    temp0.value = 0;
    
    iloc_arg temp1;
    temp1.type = 1;
    temp1.value = 1;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op_1 = generate_loadI(l_val, temp0);
    iloc_op *load_op_2 = generate_loadI(r_val, temp1);
    iloc_op *lte_op = generate_cmp_LE(temp0, temp1, t_val);

    code = append_op(code, load_op_1);
    code = append_op(code, load_op_2);
    code = append_op(code, lte_op);

    return code;
};

iloc_code *generate_reg_const_lte(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_arg temp;
    temp.type = 1;
    temp.value = 0;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op = generate_loadI(r_val, temp);
    iloc_op *lte_op = generate_cmp_LE(l_val, temp, t_val);

    code = append_op(code, load_op);
    code = append_op(code, lte_op);

    return code;
};

iloc_code *generate_const_reg_lte(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    return generate_reg_const_lte(r_val, l_val, t_val);
};

iloc_code *generate_lr_reg_lte(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_code *code = iloc_code_new();

    iloc_op *lte_op = generate_cmp_LE(l_val, r_val, t_val);

    code = append_op(code, lte_op);

    return code;  
};

iloc_code *generate_lte_code(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    if(l_val.type == 0)
    {
        //Constant + Constant
        if(r_val.type == 0)
        {
            return generate_lr_const_lte(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_const_reg_lte(l_val, r_val, t_val);
        }
    }
    else
    {
        //Register + Constant
        if(r_val.type == 0)
        {
            return generate_reg_const_lte(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_lr_reg_lte(l_val, r_val, t_val);
        }
    }
};

/*
--------------------------------------------------
-------------- GTE CODE GENERATORS ----------------
--------------------------------------------------
*/

iloc_code *generate_lr_const_gte(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_arg temp0;
    temp0.type = 1;
    temp0.value = 0;
    
    iloc_arg temp1;
    temp1.type = 1;
    temp1.value = 1;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op_1 = generate_loadI(l_val, temp0);
    iloc_op *load_op_2 = generate_loadI(r_val, temp1);
    iloc_op *gte_op = generate_cmp_GE(temp0, temp1, t_val);

    code = append_op(code, load_op_1);
    code = append_op(code, load_op_2);
    code = append_op(code, gte_op);

    return code;
};

iloc_code *generate_reg_const_gte(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_arg temp;
    temp.type = 1;
    temp.value = 0;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op = generate_loadI(r_val, temp);
    iloc_op *gte_op = generate_cmp_GE(l_val, temp, t_val);

    code = append_op(code, load_op);
    code = append_op(code, gte_op);

    return code;
};

iloc_code *generate_const_reg_gte(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    return generate_reg_const_gte(r_val, l_val, t_val);
};

iloc_code *generate_lr_reg_gte(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_code *code = iloc_code_new();

    iloc_op *gte_op = generate_cmp_GE(l_val, r_val, t_val);

    code = append_op(code, gte_op);

    return code;  
};

iloc_code *generate_gte_code(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    if(l_val.type == 0)
    {
        //Constant + Constant
        if(r_val.type == 0)
        {
            return generate_lr_const_gte(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_const_reg_gte(l_val, r_val, t_val);
        }
    }
    else
    {
        //Register + Constant
        if(r_val.type == 0)
        {
            return generate_reg_const_gte(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_lr_reg_gte(l_val, r_val, t_val);
        }
    }
};

/*
--------------------------------------------------
-------------- EQU CODE GENERATORS ----------------
--------------------------------------------------
*/

iloc_code *generate_lr_const_equ(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_arg temp0;
    temp0.type = 1;
    temp0.value = 0;
    
    iloc_arg temp1;
    temp1.type = 1;
    temp1.value = 1;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op_1 = generate_loadI(l_val, temp0);
    iloc_op *load_op_2 = generate_loadI(r_val, temp1);
    iloc_op *equ_op = generate_cmp_EQ(temp0, temp1, t_val);

    code = append_op(code, load_op_1);
    code = append_op(code, load_op_2);
    code = append_op(code, equ_op);

    return code;
};

iloc_code *generate_reg_const_equ(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_arg temp;
    temp.type = 1;
    temp.value = 0;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op = generate_loadI(r_val, temp);
    iloc_op *equ_op = generate_cmp_EQ(l_val, temp, t_val);

    code = append_op(code, load_op);
    code = append_op(code, equ_op);

    return code;
};

iloc_code *generate_const_reg_equ(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    return generate_reg_const_equ(r_val, l_val, t_val);
};

iloc_code *generate_lr_reg_equ(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_code *code = iloc_code_new();

    iloc_op *equ_op = generate_cmp_EQ(l_val, r_val, t_val);

    code = append_op(code, equ_op);

    return code;  
};

iloc_code *generate_equ_code(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    if(l_val.type == 0)
    {
        //Constant + Constant
        if(r_val.type == 0)
        {
            return generate_lr_const_equ(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_const_reg_equ(l_val, r_val, t_val);
        }
    }
    else
    {
        //Register + Constant
        if(r_val.type == 0)
        {
            return generate_reg_const_equ(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_lr_reg_equ(l_val, r_val, t_val);
        }
    }
};

/*
--------------------------------------------------
-------------- NEQ CODE GENERATORS ----------------
--------------------------------------------------
*/

iloc_code *generate_lr_const_neq(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_arg temp0;
    temp0.type = 1;
    temp0.value = 0;
    
    iloc_arg temp1;
    temp1.type = 1;
    temp1.value = 1;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op_1 = generate_loadI(l_val, temp0);
    iloc_op *load_op_2 = generate_loadI(r_val, temp1);
    iloc_op *neq_op = generate_cmp_NE(temp0, temp1, t_val);

    code = append_op(code, load_op_1);
    code = append_op(code, load_op_2);
    code = append_op(code, neq_op);

    return code;
};

iloc_code *generate_reg_const_neq(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_arg temp;
    temp.type = 1;
    temp.value = 0;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op = generate_loadI(r_val, temp);
    iloc_op *neq_op = generate_cmp_NE(l_val, temp, t_val);

    code = append_op(code, load_op);
    code = append_op(code, neq_op);

    return code;
};

iloc_code *generate_const_reg_neq(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    return generate_reg_const_neq(r_val, l_val, t_val);
};

iloc_code *generate_lr_reg_neq(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_code *code = iloc_code_new();

    iloc_op *neq_op = generate_cmp_NE(l_val, r_val, t_val);

    code = append_op(code, neq_op);

    return code;  
};

iloc_code *generate_neq_code(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    if(l_val.type == 0)
    {
        //Constant + Constant
        if(r_val.type == 0)
        {
            return generate_lr_const_neq(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_const_reg_neq(l_val, r_val, t_val);
        }
    }
    else
    {
        //Register + Constant
        if(r_val.type == 0)
        {
            return generate_reg_const_neq(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_lr_reg_neq(l_val, r_val, t_val);
        }
    }
};

/*
--------------------------------------------------
-------------- LTH CODE GENERATORS ----------------
--------------------------------------------------
*/

iloc_code *generate_lr_const_lth(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_arg temp0;
    temp0.type = 1;
    temp0.value = 0;
    
    iloc_arg temp1;
    temp1.type = 1;
    temp1.value = 1;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op_1 = generate_loadI(l_val, temp0);
    iloc_op *load_op_2 = generate_loadI(r_val, temp1);
    iloc_op *lth_op = generate_cmp_LT(temp0, temp1, t_val);

    code = append_op(code, load_op_1);
    code = append_op(code, load_op_2);
    code = append_op(code, lth_op);

    return code;
};

iloc_code *generate_reg_const_lth(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_arg temp;
    temp.type = 1;
    temp.value = 0;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op = generate_loadI(r_val, temp);
    iloc_op *lth_op = generate_cmp_LT(l_val, temp, t_val);

    code = append_op(code, load_op);
    code = append_op(code, lth_op);

    return code;
};

iloc_code *generate_const_reg_lth(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    return generate_reg_const_lth(r_val, l_val, t_val);
};

iloc_code *generate_lr_reg_lth(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_code *code = iloc_code_new();

    iloc_op *lth_op = generate_cmp_LT(l_val, r_val, t_val);

    code = append_op(code, lth_op);

    return code;  
};

iloc_code *generate_lth_code(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    if(l_val.type == 0)
    {
        //Constant + Constant
        if(r_val.type == 0)
        {
            return generate_lr_const_lth(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_const_reg_lth(l_val, r_val, t_val);
        }
    }
    else
    {
        //Register + Constant
        if(r_val.type == 0)
        {
            return generate_reg_const_lth(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_lr_reg_lth(l_val, r_val, t_val);
        }
    }
};

/*
--------------------------------------------------
-------------- GTH CODE GENERATORS ----------------
--------------------------------------------------
*/

iloc_code *generate_lr_const_gth(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_arg temp0;
    temp0.type = 1;
    temp0.value = 0;
    
    iloc_arg temp1;
    temp1.type = 1;
    temp1.value = 1;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op_1 = generate_loadI(l_val, temp0);
    iloc_op *load_op_2 = generate_loadI(r_val, temp1);
    iloc_op *gth_op = generate_cmp_GT(temp0, temp1, t_val);

    code = append_op(code, load_op_1);
    code = append_op(code, load_op_2);
    code = append_op(code, gth_op);

    return code;
};

iloc_code *generate_reg_const_gth(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_arg temp;
    temp.type = 1;
    temp.value = 0;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op = generate_loadI(r_val, temp);
    iloc_op *gth_op = generate_cmp_GT(l_val, temp, t_val);

    code = append_op(code, load_op);
    code = append_op(code, gth_op);

    return code;
};

iloc_code *generate_const_reg_gth(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    return generate_reg_const_gth(r_val, l_val, t_val);
};

iloc_code *generate_lr_reg_gth(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    iloc_code *code = iloc_code_new();

    iloc_op *gth_op = generate_cmp_GT(l_val, r_val, t_val);

    code = append_op(code, gth_op);

    return code;  
};

iloc_code *generate_gth_code(iloc_arg l_val, iloc_arg r_val, iloc_arg t_val)
{
    if(l_val.type == 0)
    {
        //Constant + Constant
        if(r_val.type == 0)
        {
            return generate_lr_const_gth(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_const_reg_gth(l_val, r_val, t_val);
        }
    }
    else
    {
        //Register + Constant
        if(r_val.type == 0)
        {
            return generate_reg_const_gth(l_val, r_val, t_val);
        }
        //Constant + Register
        else
        {
            return generate_lr_reg_gth(l_val, r_val, t_val);
        }
    }
};

/*
--------------------------------------------------
-------------- ASG CODE GENERATORS ----------------
--------------------------------------------------
*/

iloc_code *generate_const_asg(iloc_arg val_addr, iloc_arg offset_temp, iloc_arg assg_val)
{
    iloc_arg assg_temp;
    assg_temp.type = 1;
    assg_temp.value = 0;

    iloc_code *code = iloc_code_new();

    iloc_op *load_op = generate_loadI(assg_val, assg_temp);
    iloc_op *store_op = generate_storeAI(assg_temp, offset_temp, val_addr);

    code = append_op(code, load_op);
    code = append_op(code, store_op);

    return code;
};

iloc_code *generate_reg_asg(iloc_arg val_addr, iloc_arg offset_temp, iloc_arg assg_val)
{
    iloc_code *code = iloc_code_new();

    iloc_op *store_op = generate_storeAI(assg_val, offset_temp, val_addr);

    code = append_op(code, store_op);

    return code;
};

iloc_code *generate_asg_code(iloc_arg val_addr, iloc_arg offset_temp, iloc_arg assg_val)
{
    //Constant
    if(assg_val.type == 0)
    {
        return generate_const_asg(val_addr, offset_temp, assg_val);
    }
    //Register
    else
    {
        return generate_reg_asg(val_addr, offset_temp, assg_val);
    }
};

/*
--------------------------------------------------
-------------- LOD CODE GENERATORS ----------------
--------------------------------------------------
*/

iloc_code *generate_lod_code(iloc_arg val_addr, iloc_arg offset_temp, iloc_arg load_temp)
{
    iloc_code *code = iloc_code_new();

    iloc_op *store_op = generate_loadAI(offset_temp, val_addr, load_temp);

    code = append_op(code, store_op);

    return code;
};

/*
--------------------------------------------------
-------------- IF CODE GENERATORS ----------------
--------------------------------------------------
*/

iloc_code *generate_if_code(iloc_arg cond_temp, iloc_arg true_label, iloc_arg false_label)
{
    iloc_arg cmp_temp;
    cmp_temp.type = 1;
    cmp_temp.value = 0;

    iloc_arg true_val;
    true_val.type = 0;
    true_val.value = 1;

    iloc_code *code = iloc_code_new();

    iloc_op *eq_op = generate_cmp_EQ(cond_temp, true_val, cmp_temp);
    iloc_op *cbr_op = generate_cbr(cmp_temp, true_label, false_label);

    code = append_op(code, eq_op);
    code = append_op(code, cbr_op);

    return code;
};

/*
--------------------------------------------------
-------------- JUMP CODE GENERATORS --------------
--------------------------------------------------
*/

iloc_code *generate_jump_code(iloc_arg jmp_lbl)
{
    iloc_code *code = iloc_code_new();

    iloc_op *op = generate_jumpI(jmp_lbl);

    code = append_op(code, op);

    return code;
};

/*
--------------------------------------------------
------------- LABEL CODE GENERATORS --------------
--------------------------------------------------
*/

iloc_code *generate_label_code(iloc_arg label)
{
    iloc_code *code = iloc_code_new();

    iloc_op *op = generate_label(label);
    iloc_op *nop = generate_nop();

    code = append_op(code, op);
    code = append_op(code, nop);

    return code;
};

/*
--------------------------------------------------
------------- INT CODE GENERATORS ----------------
--------------------------------------------------
*/

iloc_code *generate_int_code(iloc_arg arg_1, iloc_arg arg_2)
{
    iloc_code *code = iloc_code_new();

    iloc_op *op = generate_loadI(arg_1, arg_2);

    code = append_op(code, op);

    return code;
};

/*
--------------------------------------------------
--------- TOP MOST ILOC CODE GENERATOR -----------
--------------------------------------------------
*/

iloc_code *generate_iloc_code(CODE_OPTION code_option, iloc_arg arg_1, iloc_arg arg_2, iloc_arg arg_3)
{
    switch(code_option)
    {
        //Less or equal then: <=
        case LTE:
            return generate_lte_code(arg_1, arg_2, arg_3);
            break;

        //Greater or equal then: >=
        case GTE:
            return generate_gte_code(arg_1, arg_2, arg_3);
            break;

        //Equal
        case EQU:
            return generate_equ_code(arg_1, arg_2, arg_3);
            break;

        //Not equal: !=
        case NEQ:
            return generate_neq_code(arg_1, arg_2, arg_3);
            break;

        //And: &
        case AND:
            return generate_and_code(arg_1, arg_2, arg_3);
            break;

        //Or: |
        case ORR:
            return generate_or_code(arg_1, arg_2, arg_3);
            break;

        //Not: !
        case NOT:
            return generate_not_code(arg_1, arg_2);
            break;

        //Subtraction: -
        case SUB:
            return generate_sub_code(arg_1, arg_2, arg_3);
            break;

        //Multiplication: *
        case MUL:
            return generate_mul_code(arg_1, arg_2, arg_3);
            break;

        //Division: /
        case DIV:
            return generate_div_code(arg_1, arg_2, arg_3);
            break;

        //Sum: +
        case SUM:
            return generate_sum_code(arg_1, arg_2, arg_3);
            break;

        //Less than: <
        case LTH:
            return generate_lth_code(arg_1, arg_2, arg_3);
            break;

        //Greater than: >
        case GTH:
            return generate_gth_code(arg_1, arg_2, arg_3);
            break;

        //Assignment: =
        //arg_1: var addr
        //arg_2: rbss or rfp
        //arg_3: value to be assigned
        case ASG:
            return generate_asg_code(arg_1, arg_2, arg_3);
            break;

        //If: if
        //arg_1: temporary to be checked
        //arg_2: true label
        //arg_3: false label
        case IFF:
            return generate_if_code(arg_1, arg_2, arg_3);
            break;

        //Jump
        case JMP:
            return generate_jump_code(arg_1);
            break;

        //Value load
        //arg_1: var addr
        //arg_2: rbss or rfp
        //arg_3: load temp
        case LOD:
            return generate_lod_code(arg_1, arg_2, arg_3);
            break;

        case LBL:
            return generate_label_code(arg_1);
            break;

        case INT:
            return generate_int_code(arg_1, arg_2);
            break;

        //Invalid argument
        default:
            printf("Error Log - Invalid code option at generate_iloc_code call, returning a NOP\n");
            return generate_nop_code();
    }
};

iloc_code *generate_1_arg_iloc_code(CODE_OPTION code_option, iloc_arg arg_1)
{
    return generate_iloc_code(code_option, arg_1, get_null_arg(), get_null_arg());
};

iloc_code *generate_2_arg_iloc_code(CODE_OPTION code_option, iloc_arg arg_1, iloc_arg arg_2)
{
    return generate_iloc_code(code_option, arg_1, arg_2, get_null_arg());
};

