#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10

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
    size_t counter = 1;
    size_t rows, columns, j = 0;
    printf("Insert rows, columns: ");

    if (scanf("%zu%zu", &rows, &columns) != 2 || rows < 1 || columns < 1 || rows > 10 || columns > 10 || rows != columns) 
        return EXIT_FAILURE;

    *prows = rows;
    *pcolumns = columns;

    for (size_t n = 0; true; n++)    
    {
        // Вправо
        for (size_t i = n; i < columns - j; i++)
        {
            if (counter == rows * columns + 1)
                return EXIT_SUCCESS;

            matrix[j][i] = counter++;
        }

        // Вниз
        for (size_t i = n + 1; i < rows - j; i++)
        {
            if (counter == rows * columns + 1)
                return EXIT_SUCCESS;
            
            matrix[i][columns - j - 1] = counter++;
        }
        
        // Влево
        for (size_t k = columns - j - 2; k > n; k--)
        {
            if (counter == rows * columns + 1)
                return EXIT_SUCCESS;

            matrix[columns - j - 1][k] = counter++;
        }

        // Вверх
        for (size_t i = rows - j - 1; i > j; i--)
        {
            if (counter == rows * columns + 1)
                return EXIT_SUCCESS;

            matrix[i][j] = counter++;         
        }

        j++;
    }
    
    return EXIT_SUCCESS;
}