#include <stdio.h>
#include <string.h>
#define MAX_WORD_LEN 17
#define MAX_WORDS 127
#define MAX_STRING_LEN 257


void sort_words(char words[MAX_WORDS][MAX_WORD_LEN], size_t wc)
{
    char temp[MAX_WORD_LEN];

    for (size_t i = 0; i < wc; i++)
    {
        for (size_t j = 0; j < wc - i - 1; j++)
        {
            if (strcmp(words[j], words[j + 1]) > 0)
            {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }
}
