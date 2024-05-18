
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
// prj part 2

//  5.1
enum enum_type
{
NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

union column_type{
unsigned int uint_value;
signed int int_value;
char char_value;
float float_value;
double double_value;
char* string_value;
void* struct_value;
};
typedef union column_type COL_TYPE ;

struct column {
char *title;
unsigned int size; //logical size
unsigned int max_size; //physical size
ENUM_TYPE column_type;
COL_TYPE **data; // array of pointers to stored data
unsigned long long int *index; // array of integers
};
typedef struct column COLUMN;

//5.1.1
COLUMN *create_column(ENUM_TYPE type, char *title);
int insert_value(COLUMN *col, void *value);
