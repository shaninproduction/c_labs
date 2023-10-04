#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define N 10


void show_arr(int arr[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int armstrong_num(int num)
{
    double length = log10(num) + 1;
    int summa = 0, num_copy = num;

    while (num > 0)
    {
        summa += pow(num % 10, (int) length);
        num /= 10;
    }

    if (summa == num_copy)
        return true;
    
    return false;
}


int main(void)
{
    int count, arr[N], armstrong_arr[N], j;

    // Заполнение массива
    printf("Insert number of elems: ");
    if (scanf("%d", &count) != 1 || count > 10 || count < 1)
        return EXIT_FAILURE;

    for (int i = 0; i < count; i++)
    {
        printf("Insert arr%d: ", i);
        if (scanf("%d", &arr[i]) != 1)
            return EXIT_FAILURE;
    }

    // Формирование нового массива
    j = 0;
    for (int i = 0; i < count; i++)
    {
        if (armstrong_num(arr[i]))
            armstrong_arr[j++] = arr[i];
    }

    if (j == 0)
        return EXIT_FAILURE;
        
    // Вывод нового массива
    printf("Сформированный массив:\n");
    show_arr(armstrong_arr, j);


    return EXIT_SUCCESS;
}
