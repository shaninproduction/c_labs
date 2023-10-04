#include <stdio.h>
#include <stdlib.h>
#define N 10
#include "input_output.h"
#include "calculations.h"


int main(void)
{
    int matrix[N][N], result_arr[N], check;
    size_t rows = 0, columns = 0;
    size_t *prows = &rows, *pcolumns = &columns;

    check = input_matrix(matrix, prows, pcolumns);

    if (check != 0)
        return EXIT_FAILURE;

    get_result(matrix, result_arr, rows, columns);

    printf("Result array: ");

    show_arr(result_arr, rows);

    return EXIT_SUCCESS;
}