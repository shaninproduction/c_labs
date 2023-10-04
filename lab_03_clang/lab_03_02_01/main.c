#include <stdio.h>
#include <stdlib.h>
#define N 10
#include "input_output.h"
#include "calculations.h"

int main(void)
{
    int matrix[N][N], check, row_index, column_index;
    int *prow_index = &row_index, *pcolumn_index = &column_index;

    size_t rows = 0, columns = 0;
    size_t *prows = &rows, *pcolumns = &columns; 

    check = input_matrix(matrix, prows, pcolumns);

    if (check != 0)
        return EXIT_FAILURE;

    find_minim(matrix, rows, columns, prow_index, pcolumn_index);

    del_row_column(matrix, row_index, column_index, rows, columns);
    
    rows--;
    columns--;

    if (rows == 0 || columns == 0)
        return EXIT_FAILURE;

    show_matrix(matrix, rows, columns);

    return EXIT_SUCCESS;
}
