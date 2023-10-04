#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define N 10


int find_elem(size_t length, size_t index)
{
    for (size_t i = 0; i < 3; i++)
    {
        if (index == length - 1)
        {
            index = 0;
            continue;
        }

        index++;
    }

    return index;
}

void input_elems(int matrix[N][N], int elems[], int coord_i[], int coord_j[], size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        matrix[coord_i[i]][coord_j[i]] = elems[i];
    }
}

void cycle_move(int arr[], size_t length)
{
    int first;
    for (int i = 0; i < 3; i++)
    {
        first = arr[0];
        for (size_t j = 1; j < length; j++)
        {
            arr[j - 1] = arr[j];
        }
        arr[length - 1] = first;
    }
}

int get_sum_of_chars(int num)
{
    num = abs(num);
    int sum = 0;

    while (num != 0)
    {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int get_array(int matrix[N][N], int result[], int coord_i[], int coord_j[], size_t rows, size_t columns, size_t *plength)
{
    int new_elem_index = 0;
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
            if (get_sum_of_chars(matrix[i][j]) > 10)
            {
                result[new_elem_index] = matrix[i][j];
                coord_i[new_elem_index] = (int) i;
                coord_j[new_elem_index] = (int) j;

                new_elem_index++;
            }

    if (new_elem_index == 0)
        return EXIT_FAILURE;
    
    *plength = new_elem_index;

    return EXIT_SUCCESS;
}
