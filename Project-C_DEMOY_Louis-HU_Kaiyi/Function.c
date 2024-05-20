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

COLUMN *create_column(ENUM_TYPE type, char *title)
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

int insert_value(COLUMN *col, void *value)
{
    if(col->size < col->max_size){
        switch (col->column_type) {
            case INT:
                col->data[col->size] = malloc((sizeof(int)));
                *((int*)col->data[col->size])=*((int*)value);
                break;
            case UINT:
                col->data[col->size] = malloc((sizeof(unsigned int)));
                *((unsigned int*)col->data[col->size])=*((unsigned int*)value);
                break;
            case CHAR:
                col->data[col->size] = malloc((sizeof(char )));
                *((char*)col->data[col->size])=*((char*)value);
                break;
            case FLOAT:
                col->data[col->size] = malloc((sizeof(float )));
                *((float *)col->data[col->size])=*((float *)value);
                break;
            case DOUBLE:
                col->data[col->size] = malloc((sizeof(double )));
                *((double *)col->data[col->size])=*((double *)value);
                break;
            case STRING:
                col->data[col->size] = malloc((sizeof(char )));
                *((char**)col->data[col->size])=*((char**)value);
                break;
            case STRUCTURE:
                col->data[col->size] = malloc((sizeof(int)));
                *((int*)col->data[col->size])=*((int*)value);
                break;
        }
        col->size++;
        return 1;
    }

    return 0;
}

void delete_column(COLUMN **col)
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
        snprintf(str, size, "%s", ((int*)col->data[i]));
        break;
    }
}

void print_col(COLUMN* col){
    for (int i = 0; i < col->size; ++i) {
        printf("[%d] %d\n",i,col->data[i]);
    }
}


int number_of_occurences(COLUMN *col, void* value){
    int res = 0;
    for (int i = 0; i < col->size; ++i) {
        if(col->data[i] == value){
            res++;
        }
    }
    return res;
}


void* number_at_pos(COLUMN *col, int index){
    if(index>col->size){
        return NULL;
    }else{
        return col->data[index];
    }
}



int greater(COLUMN *col, void* value){
    int res = 0;

    switch (col->column_type) {
        case INT:
            for (int i = 0; i < col->size; ++i) {
                if((*(int*)col->data[i]) > *((int*)value)){
                    res++;
                }
            }
            break;
        case UINT:
            for (int i = 0; i < col->size; ++i) {
                if(*((unsigned int*)col->data[i]) > *((unsigned int*)value)){
                    res++;
                }
            }
            break;
        case CHAR:
            for (int i = 0; i < col->size; ++i) {
                if(*((char*)col->data[i]) > *((char*)value)){
                    res++;
                }
            }
            break;
        case FLOAT:
            for (int i = 0; i < col->size; ++i) {
                if(*((float*)col->data[i]) > *((float*)value)){
                    res++;
                }
            }
            break;
        case DOUBLE:
            for (int i = 0; i < col->size; ++i) {
                if(*((double*)col->data[i]) > *((double*)value)){
                    res++;
                }
            }
            break;
        case STRING:
            for (int i = 0; i < col->size; ++i) {
                if(*((char*)col->data[i]) > *((char*)value)){
                    res++;
                }
            }
            break;
        case STRUCTURE:
            for (int i = 0; i < col->size; ++i) {
                if(*((int*)col->data[i]) > *((int*)value)){
                    res++;
                }
            }
            break;
    }
    return -1;
}

int equal2(COLUMN *col, void* value) {
    int res = 0;
    for (int i = 0; i < col->size; ++i) {
        if (col->data[i] == value) {
            res++;
        }
    }
    return res;
}

