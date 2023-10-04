#include <stdio.h>
#include <stdlib.h>
#define N 10

int get_sum_of_chars(int num)
{
    int sum = 0;
    num = abs(num);

    while (num != 0)
    {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

void find_minim(int matrix[N][N], size_t rows, size_t columns, int *prow_index, int *pcolumn_index)
{
    int min_sum = get_sum_of_chars(matrix[0][0]), temp;

    *prow_index = 0;
    *pcolumn_index = 0;

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            temp = get_sum_of_chars(matrix[i][j]);

            if (temp < min_sum)
            {
                min_sum = temp;
                *prow_index = i;
                *pcolumn_index = j;
            }     
        }   
    }
}

void del_row_column(int matrix[N][N], int row_index, int column_index, size_t rows, size_t columns)
{
    for (size_t i = row_index + 1; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            matrix[i - 1][j] = matrix[i][j];
        }
    }

    for (size_t i = 0; i < rows - 1; i++)
    {
        for (size_t j = column_index + 1; j < columns; j++)
        {
            matrix[i][j - 1] = matrix[i][j];
        }
    }
}