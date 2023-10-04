// Шанин Матвей ИУ7-21б, Задание №8, 3 вариант

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t swap_bits(uint32_t num)
{
    uint32_t result;
    uint32_t even_bits = num & 0xAAAAAAAA;
    uint32_t odd_bits = num & 0x55555555;    
    even_bits >>= 1;
    odd_bits <<= 1;
    result = even_bits | odd_bits;

    return result;
}

void show_binary(uint32_t num, int count)
{
    if (count == 32)
        return;
    
    show_binary(num / 2, ++count);
    printf("%u", num % 2);
}

int main(void)
{
    uint32_t number;
    printf("Insert your num: ");

    if (scanf("%u", &number) != 1)
    {
        printf("Error: Type Error");
        return EXIT_FAILURE;
    }

    number = swap_bits(number);
    
    printf("Result: ");

    show_binary(number, 0);
    puts("");

    return EXIT_SUCCESS;
}