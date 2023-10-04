#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int calc_nod(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    return a;
}

int main(void)
{
    int a, b, nod, check;
    printf("Insert a, b: ");
    check = scanf("%d%d", &a, &b);
    if (check != 2 || a <= 0 || b <= 0)
        return EXIT_FAILURE;
    printf("NOD = %d\n", nod = calc_nod(a, b));

    return EXIT_SUCCESS;
}
