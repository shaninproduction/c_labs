#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#define N 10
#include "input_output.h"
#include "swaps.h"

    

int main(void)
{
    int matrix[N][N], check;
    size_t rows = 0, columns = 0;
    size_t *prows = &rows, *pcolumns = &columns; 

    check = input_matrix(matrix, prows, pcolumns);

    if (check != 0)
        return EXIT_FAILURE;

    swapper(matrix, rows, columns);

    show_matrix(matrix, rows, columns);

    return EXIT_SUCCESS;
}
