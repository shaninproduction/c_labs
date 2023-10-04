// Шанин Матвей ИУ7-21Б, Вариант 3, Задача №2

#include <stdio.h>
#include <math.h>
#define PI 3.141592

int main(void)
{
    float a, b, angle, square;
    printf("Insert a, b, angle: ");
    scanf("%f%f%f", &a, &b, &angle);
    square = 0.5 * a * b * sin(angle * PI / 180); // Подсчет площади
    printf("Square of your triangle is - %f\n", square);
    return 0;
}
