#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

#define MAX_WORD_LEN 17
#define MAX_WORDS 127
#define MAX_STRING_LEN 257


void show_words(char words[MAX_WORDS][MAX_WORD_LEN], size_t words_count)
{
    printf("Result: ");

    if (words_count == 1)
    {
        printf("%s\n", words[0]);
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


void delete_similar(char words[MAX_WORDS][MAX_WORD_LEN], int *wc)
{
    for (int i = 0; i < *wc - 1; i++)
    {
        for (int j = i + 1; j < *wc; j++)
        {
            if (strcmp(words[i], words[j]) != 0)
                continue;
            
            for (int k = j; k < *wc - 1; k++)
            {
                strcpy(words[k], words[k + 1]);
            }
            j--;
            (*wc)--;
        }
    }
}


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

int read_str(char *s)
{
    int ch;
    size_t len = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (len < MAX_STRING_LEN)
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
    char string[MAX_STRING_LEN];
    char words[MAX_WORDS][MAX_WORD_LEN];
    int wc = -1, *pwc = &wc, err;

    if (read_str(string) == EXIT_FAILURE)
        return EXIT_FAILURE;

    if (strlen(string) == 257 || check_word_len(string) == EXIT_FAILURE || strlen(string) == 0)
        return EXIT_FAILURE;
    
    err = get_words_array(words, string, pwc);

    if (err == EXIT_FAILURE)
        return EXIT_FAILURE;

    delete_similar(words, pwc);

    sort_words(words, wc);

    show_words(words, wc);

    return EXIT_SUCCESS;
}