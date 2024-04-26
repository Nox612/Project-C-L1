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
        cdataframe->list_col[cdataframe->pSize] = **column;
        return 0;
    }
    return 1;
}

