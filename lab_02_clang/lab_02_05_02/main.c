#include <stdio.h>
#include <stdlib.h>
#define N 10

// Функция суммы
int summa(const int *pstart, const int *pend)
{
    int summa = 0, mult = 1;

    for (const int *pcurr = pstart; pcurr < pend; pcurr++)
    {
        mult *= *pcurr;
        summa += mult;

        if (*pcurr < 0)
            break;
    }
    
    return summa;
}

// Функция ввода массива
int input(int *pstart, size_t *plen)
{
    size_t n;
    
    // Заполнение массива
    printf("Insert number of elems: ");
    if (scanf("%zu", &n) != 1 || n > 10 || n < 1)
        return EXIT_FAILURE;

    *plen = n;

    for (size_t i = 0; i < n; i++)
    {
        printf("Insert num%ld: ", i);
        if (scanf("%d", pstart + i) != 1)
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


int main(void)
{
    int arr[N], exit = 0, result;
    size_t len = 0;
    size_t *plen = &len;

    exit = input(arr, plen);

    if (exit == EXIT_FAILURE)
        return exit;

    result = summa(arr, arr + len);
    printf("Sum: ");
    printf("%d\n", result);
    
    return EXIT_SUCCESS;
}
