/*
AUTORES:
GABRIEL PIRES E PEIXOTTO - 00326403
JOÃO DAVI M NUNES - 00285639
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scopetable.h"

T_SCOPE_TABLE* create_table()
{
    T_SCOPE_TABLE *table = malloc(sizeof (int));
    table->rows_number = 0;

    // printf("A TABLE HAS BEEN CREATED\n");
    // print_table(table);
    // printf("NEWLY CREATED TABLE HAS %d ROWS\n", table->rows_number);

    return table;
}

T_SCOPE_TABLE* add_row(T_SCOPE_TABLE *table, T_SCOPE_TABLE_ROW *row)
{
    table->rows_number = table->rows_number + 1;
    int rows_number = table->rows_number;
    table = realloc(table, sizeof (int) + ((rows_number)*sizeof (T_SCOPE_TABLE_ROW*)));
    table->rows[rows_number - 1] = row;

    // printf("ADDING ROW > TOTAL ROWS: %d\n", table->rows_number);

    return table; 
}

T_SCOPE_TABLE_ROW* create_row(int line, char *symbol, char *nature, char *data_type, char *data_value)
{
    T_SCOPE_TABLE_ROW *table_row = calloc(1, sizeof (int) + 3*(sizeof (char*)));
    table_row->line = line;
    table_row->symbol = symbol;
    table_row->nature = nature;
    table_row->data_type = data_type;
    table_row->data_value = data_value;

    return table_row;
}

void print_table(T_SCOPE_TABLE *table)
{
    int rows_number = table->rows_number;

    printf("SYMBOL\t||LINE\t||NATURE\t||DATA_TYPE\t||DATA_VALUE\n");

    for(int i = 0; i < rows_number; i++)
    {
        T_SCOPE_TABLE_ROW* row = table->rows[i];

        printf("%s\t||%d\t||%s\t||%s\t\t||%s\n", row->symbol, row->line, row->nature, row->data_type, row->data_value);
    }
}

T_SCOPE_TABLE_ROW* find_symbol(T_SCOPE_TABLE *table, char *symbol)
{
    // printf("A TABLE IS BEING SEARCHED FOR: %s\n", symbol);
    // print_table(table);

    int found = 0;
    int i = 0;
    int rows_number = table->rows_number;
    T_SCOPE_TABLE_ROW *return_row = NULL;
    
    // printf("???????SEARCHING A TABLE???????\n");

    while(found == 0 && i < rows_number)
    {

        // printf("ROW: %d // ROWS_TOTAL: %d\n", i, rows_number);
        T_SCOPE_TABLE_ROW *row = table->rows[i];

        // printf("DEBUG A (ROWS IN CURRENTLY SEARCHED TABLE: %d\n", rows_number);
        int is_equal = strcmp(symbol, row->symbol);
        if(is_equal == 0)
        {
            found = 1;
            return_row = row;
        }

        i += 1;
    }

    // printf("???????????????????\n");

    return return_row;
}

T_SCOPE_TABLE_STACK* create_stack()
{
    T_SCOPE_TABLE_STACK* stack = (T_SCOPE_TABLE_STACK*) calloc(1, sizeof (int));
    stack->tables_number = 0;

    return stack;
}

T_SCOPE_TABLE_STACK* add_table(T_SCOPE_TABLE_STACK *stack)
{
    if(stack == NULL)
    {
        stack = create_stack();
    }

    T_SCOPE_TABLE *new_table = create_table();
    new_table->rows_number = 0;
    int tables_number = stack->tables_number + 1;
    stack = (T_SCOPE_TABLE_STACK*) realloc(stack, sizeof (int) + (sizeof (T_SCOPE_TABLE*))*tables_number);
    stack->tables_number = tables_number;
    stack->tables[tables_number - 1] = new_table;

    return stack;
}

T_SCOPE_TABLE_STACK* pop_table(T_SCOPE_TABLE_STACK *stack)
{
    if(stack->tables_number > 0)
    {
        int tables_number = stack->tables_number - 1;
        free(stack->tables[tables_number]);
        stack = (T_SCOPE_TABLE_STACK*) realloc(stack, sizeof (int) + (sizeof (T_SCOPE_TABLE*))*tables_number);
        stack->tables_number = tables_number;

        // printf("A TABLE HAS BEEN FREED\n");
        // print_stack(stack);
    }

    return stack;
}

T_SCOPE_TABLE_ROW* find_symbol_stack(T_SCOPE_TABLE_STACK *stack, char *symbol)
{
    // printf("A STACK IS BEING SEARCHED FOR: %s\n", symbol);
    // print_stack(stack);
    int tables_number = stack->tables_number;
    int i;
    T_SCOPE_TABLE_ROW *return_row = NULL;
    T_SCOPE_TABLE *table;

    if(tables_number > 0)
    {
        for(i = tables_number - 1; i >= 0; i--)
        {
            // printf("CURRENTLY SEARCHED TABLE IS NUMBER: %d\n", i);
            table = stack->tables[i];
            // print_table(table);
            // printf("THIS TABLE HAS %d ROWS\n", table->rows_number);

            return_row = find_symbol(table, symbol);

            if(return_row != NULL)
            {
                return return_row;
            }
        }
    }

    return return_row;
}

void print_stack(T_SCOPE_TABLE_STACK *stack)
{
    int tables_number = stack->tables_number;
    
    printf("*****STACK_PRINTING*****\n");

    for(int i = 0; i < tables_number; i++)
    {
        T_SCOPE_TABLE *table = stack->tables[i];

        printf("--------------\n");
        printf("TABLE NUMBER %d:\n", i);
        print_table(table);
        printf("--------------\n");
    }
}

T_SCOPE_TABLE_ROW* find_value(T_SCOPE_TABLE *table, char *value)
{
    int found = 0;
    int i = 0;
    int rows_number = table->rows_number;
    T_SCOPE_TABLE_ROW *return_row = NULL;
    
    while(i < rows_number)
    {
        T_SCOPE_TABLE_ROW *row = table->rows[i];

        if(strcmp(value, row->data_value) == 0)
        {
            return_row = row;
        }

        i += 1;
    }

    return return_row;
}

T_SCOPE_TABLE_ROW* find_value_stack(T_SCOPE_TABLE_STACK *stack, char *value)
{
    int tables_number = stack->tables_number;
    int i;
    T_SCOPE_TABLE_ROW *return_row = NULL;
    T_SCOPE_TABLE *table;

    for(i = tables_number - 1; i >= 0; i--)
    {
        table = stack->tables[i];
        return_row = find_value(table, value);

        if(return_row != NULL)
        {
            return return_row;
        }
    }

    return return_row;
}