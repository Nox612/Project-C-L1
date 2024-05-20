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

    }
}