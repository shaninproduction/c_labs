#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_STR_LEN 257
#define MAX_WORDS 129
#define MAX_WORD_LEN 18


void get_correct_string(char *string)
{
    int len = strlen(string);

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (string[i] != string[j])
                continue;
            
            int k;

            for (k = j; k < len - 1; k++)
            {
                string[k] = string[k + 1];
            }
            
            string[k] = '\0';
            j--;
            len--;
        }
    }
}



int get_string(char *new_string, char words[MAX_WORDS][MAX_WORD_LEN], int len)
{
    char last_word[MAX_WORD_LEN];
    bool flag = true;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (strcmp(words[i], words[j]) != 0)
                flag = false;
        }   
    }

    if (flag)
        return EXIT_FAILURE;
    // Получаем последнее слово
    strcpy(last_word, words[len - 1]);

    int index = 0;

    for (int i = len - 2; i > -1; i--)
    {
        if (strcmp(last_word, words[i]) != 0)
        {
            int j;
            get_correct_string(words[i]);

            for (j = index; j - index < (int) strlen(words[i]); j++)
            {
                new_string[j] = words[i][j - index];
            }

            if (i != 0)
                new_string[j] = ' ';         
            else
            {
                new_string[j] = '\0';
                break;
            }
                
            index += strlen(words[i]) + 1;
        }
    }

    return EXIT_SUCCESS;
}