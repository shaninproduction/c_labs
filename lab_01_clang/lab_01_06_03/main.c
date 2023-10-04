// Шанин Матвей ИУ7-21Б, 3 вариант, Задание 3.2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-10

double deter(double x1, double x2, double y1, double y2, double xp, double yp)
{
    double determinator = (x2 - x1) * (yp - y1) - (xp - x1) * (y2 - y1);
    return determinator;
}

int main(void)
{
    int check1, check2;
    double x1, x2, y1, y2, xp, yp, det;
    printf("Insert line's coordinates x1,y1,x2,y2: ");
    check1 = scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);

    if (check1 != 4)
        return EXIT_FAILURE;
    
    printf("Insert dot's coordinates x, y: ");
    check2 = scanf("%lf%lf", &xp, &yp);
    det = deter(x1, x2, y1, y2, xp, yp);

    if (check2 != 2 || (fabs(x2 - x1) < EPS && (det > 0 || det < 0)) || (fabs(x1 - x2) < EPS && fabs(y1 - y2) < EPS))
        return EXIT_FAILURE;
    
    if (det > 0)
    {
        printf("0 - точка лежит выше прямой\n");
    }
    else if (det < 0)
    {
        printf("2 - точка лежит под прямой\n");
    }
    else
    {
        printf("1 - точка лежит на прямой\n");
    }

    return EXIT_SUCCESS;
}