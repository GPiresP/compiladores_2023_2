/*
AUTORES:
GABRIEL PIRES E PEIXOTTO - 00326403
JOÃO DAVI M NUNES - 00285639
*/

#ifndef SCOPE_TABLE_HEADER
#define SCOPE_TABLE_HEADER

typedef struct scope_table_row {
    int line;
    char *symbol;
    char *origin;
    char *data_type;
    char *data_value;
} T_SCOPE_TABLE_ROW;

typedef struct scope_table {
    int rows_number;
    T_SCOPE_TABLE_ROW *rows[];
} T_SCOPE_TABLE;

T_SCOPE_TABLE* create_table();

T_SCOPE_TABLE* add_row(T_SCOPE_TABLE *table, T_SCOPE_TABLE_ROW *row);

T_SCOPE_TABLE_ROW* create_row(int line, char *symbol, char *origin, char *data_type, char *data_value);

void print_table(T_SCOPE_TABLE *table);

int find_symbol(T_SCOPE_TABLE *table, char *symbol);

#endif //SCOPE_TABLE_HEADER