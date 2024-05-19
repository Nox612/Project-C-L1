#include <stdio.h>
#include "Header.h"
#include "malloc.h"

#define REALOC_SIZE 256

/*COLUMN *create_column1(char *title){
    COLUMN *col = (COLUMN*)malloc(sizeof(COLUMN));
    col->lSize = 0;
    col->pSize = 0;
    col->title = title;
    col->data = 0;
    return col;
}*/

/*int insert_value1(COLUMN *col, int value){
    if (col->lSize == col->pSize)
    {
        col->data = malloc(REALOC_SIZE*sizeof(int));
        col->lSize += REALOC_SIZE;
    }
    if (col->data!=NULL)
    {
        col->data[col->pSize] = value;
        col->pSize += 1;
        return 1;
    }

    return 0;
}

void delete_column(COLUMN *col){
    free(col->data);
    free(col);
}

void print_col(COLUMN *col){
    for (int i = 0; i < col->pSize; i++) {
        printf("[%d] %d\n", i, col->data[i]);
    }
}

int number_of_occurences(COLUMN *col, int value){
    int res = 0;
    for (int i = 0; i < col->pSize; ++i) {
        if(col->data[i] == value){
            res++;
        }
    }
    return res;
}


int number_at_pos(COLUMN *col, int index){
    if(index>col->pSize){
        return -1;
    }else{
        return col->data[index];
    }
}



int greater(COLUMN *col, int value){
    int res = 0;
    for (int i = 0; i < col->pSize; ++i) {
        if(col->data[i] > value){
            res++;
        }
    }
    return res;
}



int less(COLUMN *col, int value){
    int res = 0;
    for (int i = 0; i < col->pSize; ++i) {
        if(col->data[i] < value){
            res++;
        }
    }
    return res;
}
int equal2(COLUMN *col, int value){
    int res = 0;
    for (int i = 0; i < col->pSize; ++i) {
        if(col->data[i] == value){
            res++;
        }
    }
    return res;
}*/

COLUMN *create_column2(ENUM_TYPE type, char *title)
{
    COLUMN *col = (COLUMN*)malloc(sizeof(COLUMN));
    col -> title = title;
    col -> size = 0;
    col -> max_size = 0;
    col->column_type = type; //jsp cmt faire pr cette ligne
    col -> data = 0;
    col -> index = 0;

    return col;
}

int insert_value2(COLUMN *col, void *value)
{
    if(col->size < col->max_size){
        switch (col->column_type) {
            case INT:
                col->data[col->size] = (int*) malloc((sizeof(int )));
                *((int*)col->data[col->size])=*((int*)value);
                break;
            case UINT:
                col->data[col->size] = (unsigned int*) malloc((sizeof(unsigned int)));
                *((unsigned int*)col->data[col->size])=*((unsigned int*)value);
                break;
            case CHAR:
                col->data[col->size] = (char*) malloc((sizeof(char )));
                *((char*)col->data[col->size])=*((char*)value);
                break;
            case FLOAT:
                col->data[col->size] = (float *) malloc((sizeof(float )));
                *((float *)col->data[col->size])=*((float *)value);
                break;
            case DOUBLE:
                col->data[col->size] = (double *) malloc((sizeof(double )));
                *((double *)col->data[col->size])=*((double *)value);
                break;
            case STRING:
                col->data[col->size] = (char*) malloc((sizeof(char )));
                *((char**)col->data[col->size])=*((char**)value);
                break;
            case STRUCTURE:
                col->data[col->size] = ( int*) malloc((sizeof(int)));
                *((int*)col->data[col->size])=*((int*)value);
                break;
        }
        col->size++;
        return 1;
    }

    return 0;
}

void delete_column2(COLUMN **col)
{
    COLUMN *column = *col;
    free(column->title);
    for(int i=0; i<column->size; i++){
        free(column->data[i]);
    }
    free(column);
    column->size = 0;
    column->data = NULL;
}

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size)
{
    switch(col->column_type)
    {
        case INT :
        snprintf(str, size, "%d", *((int*)col->data[i]));
        break;

        case UINT :
        snprintf(str, size, "%d", *((unsigned int*)col->data[i]));
        break;

        case CHAR :
        snprintf(str, size, " %c", *((char*)col->data[i]));
        break;

        case FLOAT :
        snprintf(str, size, "%f", *((float*)col->data[i]));
        break;

        case DOUBLE:
        snprintf(str, size, "%ld", *((double*)col->data[i]));
        break;

        case STRING:
        snprintf(str, size, "%s", ((char*)col->data[i]));
        break;

        case STRUCTURE:
        snprintf(str, size, "%s", ((struct*)col->data[i]));
        break;
    }
}