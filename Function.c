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
    if (col -> lSize == col -> pSize)
    {
        col->data = malloc(REALOC_SIZE*sizeof(int));
        col->max_size += REALOC_SIZE;
    }
    
    if (value == NULL)
    {
        *value = NULL;
        col -> data[col->pSize] = *value;
    }
    if (col->data!=NULL)
        {
            col->data[col->pSize] = *value;
            col->pSize += 1;
            return 1;
        }

    return 0;
}
void delete_column2(COLUMN **col)
{
    free(col->data);
    free(col);
}

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size)
{
    switch(col->column_type)
    {
        case INT :
        snprintf(str, size, "%d", *((int*)col->data[i]));
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
        snprintf(str, size, "%s", ((char)col->data[i]));
        break;

        case STRUCTURE:
        snprintf(str, size, "%s", ((void*)col->data[i]));
        break;
    }
    if (col->data!=NULL)
    {
        col->data[col->size] = value;
        col->size += 1;
        return 1;
    }
    return 0;
}

