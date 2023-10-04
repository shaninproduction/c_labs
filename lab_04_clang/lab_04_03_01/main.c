#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "getting_string.h"
#include "input_output.h"

#define MAX_STR_LEN 257
#define MAX_WORDS 127
#define MAX_WORD_LEN 18


int check_word_len(char *string)
{
    const char *ptr;
    int counter = 0;

    for (ptr = string; *ptr != '\0'; ptr++)
    {
        if (counter == MAX_WORD_LEN - 1)
            return EXIT_FAILURE;

        if (*ptr != ',' && *ptr != ';' && *ptr != ':' && *ptr != ' ' \
            && *ptr != '-' && *ptr != '.' && *ptr != '!' && *ptr != '?')
            counter++;
        else
            counter = 0;
    }
    

    return EXIT_SUCCESS;
}

int read_str(char *s)
{
    int ch;
    size_t len = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (len < MAX_STR_LEN)
            s[len++] = ch;
        else
            return EXIT_FAILURE;
    if (len == 0)
        return EXIT_FAILURE;
    s[len] = '\0';
    return EXIT_SUCCESS;
}

int main(void)
{
    int len_arr = -1, err, *plen = &len_arr;
    
    char string[MAX_STR_LEN];
    char words_array[MAX_WORDS][MAX_WORD_LEN];
    char new_string[MAX_STR_LEN] = "\0";

    if (read_str(string) == EXIT_FAILURE)
        return EXIT_FAILURE;

    if (strlen(string) == 257 || check_word_len(string) == EXIT_FAILURE)
        return EXIT_FAILURE;

    err = get_words_array(words_array, string, plen);

    if (err == EXIT_FAILURE || len_arr > MAX_WORDS || len_arr == 1)
        return EXIT_FAILURE;

    err = get_string(new_string, words_array, len_arr);

    if (err == EXIT_FAILURE)
        return EXIT_FAILURE;

    if (strlen(new_string) == 0)
        return EXIT_FAILURE;

    printf("Result: %s\n", new_string);

    return EXIT_SUCCESS;
}