#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#define N 10

void swap_rows(int matrix[N][N], size_t columns, int index_1, int index_2)
{
    int temp;
    for (size_t j = 0; j < columns; j++)
    {
        temp = matrix[index_1][j];
        matrix[index_1][j] = matrix[index_2][j];
        matrix[index_2][j] = temp;
    }       
}


int max(int *pstart, int columns)
{
    int maxim = *pstart;
    for (int j = 0; j < columns; j++)
    {
        if (*(pstart + j) > maxim)
        {
            maxim = *(pstart + j);
        }        
    }

    return maxim; 
}


void sort_matrix(int matrix[N][N], size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < rows - i - 1; j++)
        {
            if (max(&matrix[j][0], columns) < max(&matrix[j + 1][0], columns))
            {
                swap_rows(matrix, columns, j, j + 1);
            }
        }
    }
}
