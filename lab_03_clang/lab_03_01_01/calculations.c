#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10

void get_result(int matrix[N][N], int result[], size_t rows, size_t columns)
{
    bool is_symmetric = true;

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns / 2; j++)
        {
            if (matrix[i][j] != matrix[i][columns - j - 1])
                is_symmetric = false;
        }
        
        result[i] = is_symmetric;
        is_symmetric = true;
    }
}