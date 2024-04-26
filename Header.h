
typedef struct
{
    int pSize;
    int lSize;
    char *title;
    int *data;
}COLUMN;

/* Basic Function */

COLUMN *create_column(char *title);
int insert_value(COLUMN *col, int value);
void delete_column(COLUMN *col);
void print_col(COLUMN *col);
int number_of_occurences(COLUMN *col, int value);
int number_at_pos(COLUMN *col, int index);
int greater(COLUMN *col, int value);
int less(COLUMN *col, int value);
int equal2(COLUMN *col, int value);

/* CDataFrame Function */

typedef struct{
    int pSize;
    int lSize;
    COLUMN **list_col;
}CDATAFRAME;

CDATAFRAME *create_cdf();
int fill_cdf(CDATAFRAME *cdataframe, COLUMN *column);
