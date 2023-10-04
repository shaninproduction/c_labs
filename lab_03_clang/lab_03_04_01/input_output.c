#include <stdio.h>
#include <stdlib.h>
#define N 10

void show_arr(int arr[], size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}


void show_matrix(int matrix[N][N], size_t rows, size_t columns)
{
    printf("Matrix:\n");
    
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


int input_matrix(int matrix[N][N], size_t *prows, size_t *pcolumns)
{
    size_t rows, columns;

    printf("Insert rows, columns: ");

    if (scanf("%zu%zu", &rows, &columns) != 2 || rows < 1 || columns < 1 || rows > 10 || columns > 10 || rows != columns)
        return EXIT_FAILURE;

    *prows = rows;
    *pcolumns = columns;

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("Insert m%zu%zu: ", i + 1, j + 1);
            if (scanf("%d", &matrix[i][j]) != 1)
                return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}