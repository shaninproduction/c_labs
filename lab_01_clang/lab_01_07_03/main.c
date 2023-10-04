// Шанин Матвей ИУ7-21Б, 3 вариант, Задание 3.2  

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPS 1e-10

double calc_function(double x, double eps)
{
    double notaccurate_func = 0;
    long long int sign = 1, i = 1;
    double member = sign * (pow(x, i) / i);
    while (fabs(member) > eps)
    {
        notaccurate_func += member;
        sign *= -1;
        i += 2;
        member = sign * (pow(x, i) / i);   
    }
    return notaccurate_func;
}

int main(void)
{
    double eps, x, notaccurate_func, accurate_func, delta, delta_otn;
    int check;

    printf("Insert x, epsilon: ");
    check = scanf("%lf%lf", &x, &eps);
    if (check != 2 || eps > 1 || eps < 0 || fabs(x) > 1 || fabs(x) < EPS)
        return EXIT_FAILURE;
    
    accurate_func = atan(x);
    notaccurate_func = calc_function(x, eps);

    delta = fabs(accurate_func - notaccurate_func);
    delta_otn = fabs(accurate_func - notaccurate_func) / fabs(accurate_func);
    printf("S(x) = %lf\nF(x) = %lf\nDelta = %lf\nDelta otn = %lf\n", notaccurate_func, accurate_func, delta, delta_otn);
    return EXIT_SUCCESS;
}
