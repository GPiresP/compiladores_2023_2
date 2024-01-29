/*
AUTORES:
GABRIEL PIRES E PEIXOTTO - 00326403
JOÃO DAVI M NUNES - 00285639
*/

#ifndef SCOPE_TABLE_HEADER
#define SCOPE_TABLE_HEADER

typedef struct scope_table_row {
    char *symbol;
    int line;
    char *nature;
    char *data_type;
    char *data_value;
    int var_addr;
    int is_global;
} T_SCOPE_TABLE_ROW;

typedef struct scope_table {
    int is_global;
    int curr_var_addr;
    int rows_number;
    T_SCOPE_TABLE_ROW *rows[];
} T_SCOPE_TABLE;

typedef struct scope_table_stack {
    int tables_number;
    T_SCOPE_TABLE *tables[];
} T_SCOPE_TABLE_STACK;

T_SCOPE_TABLE* add_row(T_SCOPE_TABLE *table, T_SCOPE_TABLE_ROW *row);

T_SCOPE_TABLE_ROW* create_row(int line, char *symbol, char *nature, char *data_type, char *data_value, int is_global, int var_addr);

void print_table(T_SCOPE_TABLE *table);

T_SCOPE_TABLE_ROW* find_symbol(T_SCOPE_TABLE *table, char *symbol);

T_SCOPE_TABLE_STACK* create_stack();

T_SCOPE_TABLE_STACK* add_table(T_SCOPE_TABLE_STACK *stack);

T_SCOPE_TABLE_STACK* pop_table(T_SCOPE_TABLE_STACK *stack);

T_SCOPE_TABLE_ROW* find_symbol_stack(T_SCOPE_TABLE_STACK *stack, char *symbol);

void print_stack(T_SCOPE_TABLE_STACK *stack);

T_SCOPE_TABLE_ROW* find_value(T_SCOPE_TABLE *table, char *value);

T_SCOPE_TABLE_ROW* find_value_stack(T_SCOPE_TABLE_STACK *stack, char *value);

int get_and_increment_var_addr(T_SCOPE_TABLE *table);

#endif //SCOPE_TABLE_HEADER