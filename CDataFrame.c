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

enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

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

