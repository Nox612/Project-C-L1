#include "Header.h"

#ifndef PROJECT_C_L1_CDATAFRAME_H
#define PROJECT_C_L1_CDATAFRAME_H

#endif //PROJECT_C_L1_CDATAFRAME_H

/* CDataFrame Function */
typedef struct{
    int pSize;
    int lSize;
    COLUMN **list_col;
}CDATAFRAME;

CDATAFRAME *create_cdf();
int fill_cdf(CDATAFRAME *cdataframe, COLUMN *column);
void print_cdf(CDATAFRAME *cdataframe);
void print_row_cdf(CDATAFRAME *cdataframe, int index);
void print_col_cdf(CDATAFRAME *cdataframe, int index);
void add_row(CDATAFRAME *cdataframe, void* value);
void delete_row(CDATAFRAME *cdataframe);
void add_column(CDATAFRAME *cdataframe, COLUMN* column);
void delete_column(CDATAFRAME *cdataframe, COLUMN *col);
void rename_col(CDATAFRAME *cdataframe, int index, char* name);
int search_cdf(CDATAFRAME *cdataframe, void* value);
void replace_cdf(CDATAFRAME *cdataframe, void* value, int row, int col);
void name_cdf(CDATAFRAME *cdataframe);
void display_row(CDATAFRAME *cdataframe, int index);
void display_col(CDATAFRAME *cdataframe);