#include <stdio.h>
#include "Function.c"

int main(){
    /*
    COLUMN *col = create_column("My column");
    int val = 1;
    if(insert_value(col,val)){
        printf("Value added\n");
    }else{
        printf("Value couldnt be added\n");
    }

    printf("%d,%d\n",col->pSize, col->lSize);

    insert_value(col,3);
    insert_value(col,3);
    insert_value(col,3);
    insert_value(col,3);
    insert_value(col,2);
    insert_value(col,88);

    print_col(col);

    printf("%d\n", number_of_occurences(col,3));
    printf("%d\n", number_at_pos(col,3));
    printf("%d\n", less(col,6));
    printf("%d\n", greater(col,5));
    printf("%d\n", equal2(col,3));

    printf("%d,%d\n",col->pSize, col->lSize);

    */

    COLUMN *col = create_column(CHAR, "My Col");
    char a = 'A', c = 'C';
    insert_value(col, &a);
    insert_value(col, NULL);
    insert_value(col, &c);

    return 0;
}