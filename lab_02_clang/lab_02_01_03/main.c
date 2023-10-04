#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-10
#define N 10

// Фукнция среднего геометрического 

double calc_sr_geom(int arr[], int length)
{
    long int mult = 1, counter = 0;
    double result;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > 0)
        {
            mult *= arr[i];
            counter += 1;
        }
    }
 
    if (counter == 0)
        return -1;

    result = pow(mult, (1 / ((double) counter))); 

    return result;
}


int main(void)
{
    int count, arr[N];
    double result;

    // Заполнение массива

    printf("Insert number of elems: ");
    if (scanf("%d", &count) != 1 || count > 10 || count < 0)
        return EXIT_FAILURE;

    for (int i = 0; i < count; i++)
    {
        printf("Insert arr%d: ", i);
        if (scanf("%d", &arr[i]) != 1)
            return EXIT_FAILURE;
    }

    // Подсчет среднего геометрического

    result = calc_sr_geom(arr, count);

    if (result + 1 < EPS)
        return EXIT_FAILURE;

    printf("Result = %lf\n", result);

    return EXIT_SUCCESS;
}