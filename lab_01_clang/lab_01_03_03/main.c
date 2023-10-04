// Шанин Матвей ИУ7-21Б, Вариант 3, Задача №3

#include <stdio.h>
#include <math.h>

int main(void)
{
    float v0, a, t, s;
    printf("Insert v0, a, t: "); 
    scanf("%f%f%f", &v0, &a, &t);
    s = v0 * t + (a * t * t) / 2; // Подсчет расстояния 
    printf("S = %f\n", s); // Вывод
    return 0;
}
