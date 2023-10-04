#include <stdio.h>
#include <stdlib.h>
#define N 10

// Функция вывода массива
void show_arr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", arr[i]);
    }
}

// Функция реверса
int reverse_num(int num)
{
    int result = 0;

    while (num > 0)
    {
        result = result * 10 + num % 10;
        num /= 10;
    }  

    return result;
}

// Функция вставки элементов 
int insert_elem(int arr[], int length)
{
    // Вставка элементов 
    int new_length = length;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > 0)
        {
            for (int j = length; j > i; j--)
            {
                arr[j] = arr[j - 1];
            }

            arr[i + 1] = reverse_num(arr[i]);
            i++;
            length++;
            new_length++;
        }    
    }

    return new_length;
}

int main(void)
{
    int length, arr[2 * N], new_length;

    // Заполнение массива
    printf("Insert number of elems: ");
    if (scanf("%d", &length) != 1 || length > 10 || length < 1)
        return EXIT_FAILURE;

    for (int i = 0; i < length; i++)
    {
        printf("Insert arr%d: ", i);
        if (scanf("%d", &arr[i]) != 1)
            return EXIT_FAILURE;
    }

    new_length = insert_elem(arr, length);
    
    printf("Новый массив:\n");
    show_arr(arr, new_length);

    return 0;
}
