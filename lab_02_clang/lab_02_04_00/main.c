#include <stdio.h>
#include <stdlib.h>
#define N 10

// Функция ввода массива
int input(int arr[], size_t *p)
{
    size_t i = 0;
    int eof_error;

    while (i < N && (eof_error = scanf("%d", arr + i)) != 0 && eof_error != EOF)
    {
        i++;
    }
    *p = i;

    if (i == N && scanf("%d", &eof_error) != 0)
        return 100;

    if (i == 0)
        return EXIT_FAILURE;    

    return EXIT_SUCCESS;
}

// Функция вывода массива
void show_arr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
}

// Функция пузырьковой сортировки
void bubble_sort(int arr[], size_t length)
{
    int temp;
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    int arr[N], err = 0;

    size_t len = 0;
    size_t *p = &len;

    err = input(arr, p);

    if (err == EXIT_FAILURE)
        return err;

    bubble_sort(arr, len);

    printf("Отсортированный массив: ");
    
    show_arr(arr, len);

    return err;
}
