#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define N 10
#include "input_output.h"
#include "calculations.h"


int main(void)
{
    int matrix[N][N], over_ten[N*N], coord_i[N*N], coord_j[N*N], check;
    size_t rows = 0, columns = 0, length_of_array = 0;
    size_t *prows = &rows, *pcolumns = &columns, *plength = &length_of_array; 

    check = input_matrix(matrix, prows, pcolumns);

    if (check != 0)
        return EXIT_FAILURE;

    check = get_array(matrix, over_ten, coord_i, coord_j, rows, columns, plength);

    if (check != 0)
        return EXIT_FAILURE;

    cycle_move(over_ten, length_of_array);

    input_elems(matrix, over_ten, coord_i, coord_j, length_of_array);

    show_matrix(matrix, rows, columns);

    return EXIT_SUCCESS;
}