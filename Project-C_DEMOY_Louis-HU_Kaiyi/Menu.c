#include <stdio.h>
#include "CDataFrame.c"

void Instruction(){
    printf("Enter the following command to naviguate through the code.\n");
    printf("1- Enters the CDataframe mode.");
    printf("2- Enters the Column mode.");
}

void Cdata_menu(){
    printf("CD1- Create an empty Cdataframe.");
    printf("CD2- Fill the Cdataframe.");
    printf("CD3- print Cdataframe.");
    printf("CD4- print Cdataframe row.");
    printf("CD5- print Cdataframe column.");
    printf("CD6- add a row.");
    printf("CD7- delete a row.");
    printf("CD8- add a column.");
    printf("CD9- delete a row.");
    printf("return to go back");
}

void Col_menu(){
    printf("C1- Create an empty Column.");
    printf("C2- Insert a value in Column.");
    printf("C3- Delete a Column.");
    printf("C4- Convert value.");
    printf("C5- Print column");
    printf("C6- number of occurence");
    printf("return to go back");
}

// Main Menu to start //

void MenuStart(){
    CDATAFRAME *cdataframe;
    COLUMN *column;
    char input[100] = "";
    printf("Welcome to our project, made by DEMOY Louis and HU Kaiyi. Use the help command to find what is possible\n");
    Instruction();
    while(input != "stop"){
        gets(input);
        if(input == "help"){
            Instruction();
        }
        if(input == "1"){
            if(input == "CD1"){
                 cdataframe = create_cdf();
            }
            if(input == "CD2"){
                fill_cdf(cdataframe, column);
            }
            if(input == "CD3"){
                print_cdf(cdataframe);
            }
            if(input == "CD4"){
                printf("enter an index\n");
                gets(input);
                print_row_cdf(cdataframe,(int)input);
            }
            if(input == "CD5"){
                printf("enter an index\n");
                gets(input);
                print_col_cdf(cdataframe,(int)input);
            }
            if(input == "CD6"){
                printf("Choose a type");
                gets(input);
                if(input == "int"){
                    int *value;
                    scanf("%d", value);
                    add_row(cdataframe, value);
                }
                if(input == "char"){
                    char *value;
                    scanf("%c", value);
                    add_row(cdataframe, value);
                }
                if(input == "float"){
                    float *value;
                    scanf("%f", value);
                    add_row(cdataframe, value);
                }
            }
            if(input == "CD7"){
                delete_row(cdataframe);
            }
            if(input == "CD8"){
                add_column(cdataframe,column);
            }
            if(input == "CD9"){
                delete_column(cdataframe,column);
            }
            if(input == "return"){
                break;
            }
        }
        if(input == "2"){
            if(input == "CD1"){
                char *title;
                printf("Choose a type and a title");
                gets(input);
                if(input == "int"){
                    int *value;
                    scanf("%d %s", value,title);
                    column = create_column(INT, title);
                }
                if(input == "char"){
                    char *value;
                    scanf("%c %s", value,title);
                    column = create_column(CHAR,title);
                }
                if(input == "float"){
                    float *value;
                    scanf("%f %s", value, title);
                    column = create_column(FLOAT, title);
                }
            }
            if(input == "CD2"){
                printf("Choose a value");
                gets(input);
                insert_value(column,input);
            }
            if(input == "CD3"){
                delete_column2(&column);
            }
            if(input == "CD4"){
                //convert_value(column);
            }
            if(input == "CD5"){
                print_col(column);
            }
            if(input == "CD6") {
                printf("Choose a value");
                gets(input);
                number_of_occurences(column,input);
            }
            if(input == "return"){
                break;
            }
        }
    }
}