#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#define N 10

void swap_rows(int matrix[N][N], int index, size_t columns)
{
    int temp;
    for (size_t j = index; j < columns - index; j++)
    {
        temp = matrix[index][j];
        matrix[index][j] = matrix[columns - index - 1][j];
        matrix[columns - index - 1][j] = temp;
    }       
}

void swapper(int matrix[N][N], size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows / 2; i++)
    {
        swap_rows(matrix, i, columns);
    }
}