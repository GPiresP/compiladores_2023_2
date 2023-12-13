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
    T_SCOPE_TABLE *table = calloc(1, sizeof (int));
    table->rows_number = 0;

    return table;
}

T_SCOPE_TABLE* add_row(T_SCOPE_TABLE *table, T_SCOPE_TABLE_ROW *row)
{
    table->rows_number = table->rows_number + 1;
    int rows_number = table->rows_number;
    table = realloc(table, sizeof (int) + ((rows_number)*sizeof (T_SCOPE_TABLE_ROW*)));
    table->rows[rows_number - 1] = row;

    return table; 
}

T_SCOPE_TABLE_ROW* create_row(int line, char *symbol, char *origin, char *data_type, char *data_value)
{
    T_SCOPE_TABLE_ROW *table_row = calloc(1, sizeof (int) + 3*(sizeof (char*)));
    table_row->line = line;
    table_row->symbol = symbol;
    table_row->origin = origin;
    table_row->data_type = data_type;
    table_row->data_value = data_value;

    return table_row;
}

void print_table(T_SCOPE_TABLE *table)
{
    int rows_number = table->rows_number;

    printf("*****TABLE_PRINTING*****\n");
    printf("SYMBOL\t||LINE\t||ORIGIN\t||DATA_TYPE\t||DATA_VALUE\n");

    for(int i = 0; i < rows_number; i++)
    {
        T_SCOPE_TABLE_ROW* row = table->rows[i];

        printf("%s\t||%d\t||%s\t||%s\t||%s\n", row->symbol, row->line, row->origin, row->data_type, row->data_value);
    }
}

T_SCOPE_TABLE_ROW* find_symbol(T_SCOPE_TABLE *table, char *symbol)
{
    int found = 0;
    int i = 0;
    int rows_number = table->rows_number;
    T_SCOPE_TABLE_ROW *return_row = NULL;
    
    while(found == 0 && i < rows_number)
    {
        T_SCOPE_TABLE_ROW *row = table->rows[i];

        if(strcmp(symbol, row->symbol) == 0)
        {
            found = 1;
            return_row = row;
        }

        i += 1;
    }

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
    }

    return stack;
}

T_SCOPE_TABLE_ROW* find_symbol_stack(T_SCOPE_TABLE_STACK *stack, char *symbol)
{
    int tables_number = stack->tables_number;
    int i;
    T_SCOPE_TABLE_ROW *return_row = NULL;
    T_SCOPE_TABLE *table;

    for(i = tables_number - 1; i >= 0; i--)
    {
        table = stack->tables[i];
        return_row = find_symbol(table, symbol);

        if(return_row != NULL)
        {
            return return_row;
        }
    }

    return return_row;
}