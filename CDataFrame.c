#include <stdio.h>
#include "Header.h"
#include "malloc.h"

CDATAFRAME *create_cdf(){
    CDATAFRAME *cdf = (CDATAFRAME*)malloc(sizeof(CDATAFRAME));
    cdf->lSize = 0;
    cdf->pSize = 0;
    cdf->list_col = 0;
    return cdf;
}

int fill_cdf(CDATAFRAME *cdataframe, COLUMN *column){
    if(cdataframe->lSize == cdataframe->pSize){
        cdataframe->list_col = malloc(16*sizeof(COLUMN));
    }
    if(cdataframe->list_col){
        cdataframe->list_col[cdataframe->pSize] = column;
        return 0;
    }
    return 1;
}

void print_cdf(CDATAFRAME *cdataframe){
    for (int i = 0; i < cdataframe->pSize; ++i) {
        printf("%s", cdataframe->list_col[i]);
    }
}

void print_row_cdf(CDATAFRAME *cdataframe, int index){

    for (int i = 0; i < cdataframe->pSize; ++i) {
        COLUMN* column = cdataframe->list_col[i];
        if(column->size >= index) {
            printf("%s", cdataframe->list_col[i][index]);
        }else{
            printf("Index out of range for column %d.\n", i);
        }
    }
}

void print_col_cdf(CDATAFRAME *cdataframe, int index){
    if(cdataframe->pSize >= index) {
        for (int i = 0; i < index; ++i) {
            printf("%s", cdataframe->list_col[i]);
        }
    }else{
        printf("Index out of range.\n");
    }
}

void add_row(CDATAFRAME *cdataframe, void* value){
    for (int i = 0; i < cdataframe->pSize; ++i) {
        COLUMN* column = cdataframe->list_col[i];
        column->size++;
        column->data[column->size] = value;
    }
}

void delete_row(CDATAFRAME *cdataframe){
    for (int i = 0; i < cdataframe->pSize; ++i) {
        COLUMN* column = cdataframe->list_col[i];
        column->data[column->size] = NULL;
        column->size--;
    }
}

void add_column(CDATAFRAME *cdataframe, COLUMN* column){
    cdataframe->pSize++;
    cdataframe->list_col[cdataframe->pSize] = column;
}

void delete_column(CDATAFRAME *cdataframe){
    cdataframe->list_col[cdataframe->pSize] = NULL;
    cdataframe->pSize--;
}

void rename_col(CDATAFRAME *cdataframe, int index, char* name){
    COLUMN *column = cdataframe->list_col[index];
    column->title = name;
}

int search_cdf(CDATAFRAME *cdataframe, void* value){
    for (int i = 0; i < cdataframe->pSize; ++i) {
        COLUMN *column = cdataframe->list_col[i];
        for (int j = 0; j < column->size; ++j) {
            if(column->data[j] == value){
                return 1;
            }
        }
    }
    return 0;
}

void replace_cdf(CDATAFRAME *cdataframe, void* value, int row, int col){
    COLUMN *column = cdataframe->list_col[col];
    column->data[row] = value;
}

void name_cdf(CDATAFRAME *cdataframe){
    for (int i = 0; i < cdataframe->pSize; ++i) {
        COLUMN *column = cdataframe->list_col[i];
        printf("%s", column->title);
    }
}

void display_row(CDATAFRAME *cdataframe, int index){
    COLUMN *column = cdataframe->list_col[index];
    for (int i = 0; i < column->size; ++i) {
        printf(column->data[i]);
    }
}

void display_col(CDATAFRAME *cdataframe){
    for (int i = 0; i < cdataframe->pSize; ++i) {
        COLUMN *column = cdataframe->list_col[i];
        for (int j = 0; j < column->size; ++j) {
            printf("%v", column->data[j]);
        }
    }
}

