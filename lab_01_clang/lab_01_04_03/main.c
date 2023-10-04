// Шанин Матвей ИУ7-21Б, Вариант 4, Задача №3

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int num, p, num1, num2, num3;
    printf("Insert 3char number: "); // Блок ввода
    scanf("%d", &num);
    num1 = num / 100; // Первая цифра числа
    num2 = num / 10 % 10; // Вторая цифра числа
    num3 = num % 10; // Третья цифра числа
    p = abs(num1 * num2 * num3); // Подсчет произведения цифр
    printf("p = %d\n", p); // Блок вывода
    return 0;
}
