// Шанин Матвей ИУ7-21Б, Задача 3.5, 3 вариант 

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPS 1e-10

double calc_function()
{
    int i = 1, check;
    long double x = 0, function_value = 1, result;

    while (1)
    {
        printf("Insert x: ");

        check = scanf("%Lf", &x);
        if (check != 1 || (i == 1 && x < 0))
            return -1;

        if (x < 0)
            break;

        function_value *= (1 / (x + i));
        i++;
    }

    result = exp(function_value);
    return result;
}

int main(void)
{
    long double result = calc_function();

    if (result + 1 < EPS)
        return EXIT_FAILURE;

    printf("Your function = %Lf\n", result);
    
    return EXIT_SUCCESS;
}
