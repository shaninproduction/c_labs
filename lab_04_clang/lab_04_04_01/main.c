#include <stdio.h>

#include "find_num.h"
#define STR_MAX 256
#define WORD_MAX 16

int main(void)
{
    char string[STR_MAX + 1];
    int err = read_str(string);
    
    if (err == EXIT_FAILURE)
        return EXIT_FAILURE;

    if (err == EXIT_ZERO_LEN)
    {
        printf("NO");
        return EXIT_SUCCESS;
    }

    if (find_num(string) == YES)
        printf("YES");
    else
        printf("NO");

    return EXIT_SUCCESS;
}