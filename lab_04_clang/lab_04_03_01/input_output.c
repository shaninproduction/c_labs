#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 257
#define MAX_WORDS 127
#define MAX_WORD_LEN 18

void show_words(char words[MAX_WORDS][MAX_WORD_LEN], size_t words_count)
{
    printf("Result: ");

    if (words_count == 1)
    {
        printf("%s", words[0]);
    }
    else
    {
        for (size_t i = 0; i < words_count; i++)
        {
            if (i == words_count - 1)
            {
                printf("%s", words[i]);
            }
            else
            {
                printf("%s ", words[i]);
            }        
        }
    }
}

int get_words_array(char words[MAX_WORDS][MAX_WORD_LEN], const char *string, int *wc)
{
    int is_word = 0, cur = 0;
    char temp[MAX_WORD_LEN];

    for (const char *p = string; *p != '\0'; p++)
    {
        if ((*p == ',' || *p == ';' || *p == ':' || *p == ' ' \
            || *p == '-' || *p == '.' || *p == '!' || *p == '?') && is_word == 1)
        {
            temp[cur] = '\0';
            strcpy(words[++(*wc)], temp);
            is_word = 0;
            cur = 0;
        }
        else if ((*p != ',' && *p != ';' && *p != ':' && *p != ' ' \
            && *p != '-' && *p != '.' && *p != '!' && *p != '?'))
        {
            is_word = 1;
            temp[cur++] = *p;
        }  
        if (*(p + 1) == '\0')
        {
            if (is_word == 1)
            {
                temp[cur] = '\0';
                strcpy(words[++(*wc)], temp);
            }
        }
    }

    if (*wc == -1)
        return EXIT_FAILURE;

    (*wc)++;

    return EXIT_SUCCESS;
}