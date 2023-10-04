#include <stdio.h>

#include "find_num.h"

#define STILL_NO 5

int read_str(char string[STR_MAX + 1])
{
    int ch;
    size_t len = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (len < STR_MAX)
            string[len++] = ch;
        else
            return EXIT_FAILURE;
    if (len == 0)
        return EXIT_ZERO_LEN;
    string[len] = '\0';
    return EXIT_SUCCESS;
}

int add_letter(char word[STR_MAX + 1], size_t *num_of_letter, char string[STR_MAX + 1], size_t i)
{
    word[*num_of_letter] = string[i];
    word[*num_of_letter + 1] = '\0';
    *num_of_letter += 1;
    if (*num_of_letter > STR_MAX)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int compare(char str1[WORD_MAX + 1], int ch)
{
    int flag = 1;
    for (size_t i = 0; str1[i] != '\0'; i++)
        if (str1[i] == ch)
            flag = 0;
    return flag;
}
int count_numbers(char e[STR_MAX + 1], size_t *k)
{
    char numbers[WORD_MAX + 1] = "0123456789";
    int flag = 1;
    while (flag == 1 && e[*k] != '\0')
    {
        if (compare(numbers, e[*k]))
            flag = 0;
        *k += 1;
    }
    if (flag == 0)
        *k -= 1;
    if (e[*k] == '\0' && flag == 1)
        return YES;
    return STILL_NO;
}
int correct_exp(char e[STR_MAX + 1], size_t *i)
{
    if (e[*i + 1] != '\0' && (e[*i] == 'e' || e[*i] == 'E'))
    {
        if (e[*i + 1] == '-' || e[*i + 1] == '+')
        {
            if (e[*i + 2] == '\0')
                return NO;
            *i += 2;
            if (count_numbers(e, i) == YES)
                return YES;
            return NO;
        }
        else
        {
            if (e[*i + 1] == 'e' || e[*i + 1] == 'E')
                return NO;
            *i += 1;
            if (count_numbers(e, i) == YES)
                return YES;
            return NO;
        }
    }
    return NO;
}
int is_num(char e[STR_MAX + 1])
{
    char exp[WORD_MAX + 1] = ".eE+-";
    size_t k = 0;
    while (e[k] != '\0')
    {
        if (e[k] == 'e' || e[k] == 'E')
            return NO;
        if (e[k] == '.' && e[k + 1] == '\0')
            return NO;
        if (e[k] != '-' && e[k] != '+')
        {
            if (count_numbers(e, &k) == YES)
                return YES;
            if (e[k] == '.')
            {
                k++;
                if (compare(exp, e[k]) == 0)
                {
                    if (k == 1)
                        return NO;
                    if (e[k - 2] == '-' || e[k - 2] == '+')
                        return NO;
                    else if (correct_exp(e, &k) == YES)
                        return YES;
                }
                else if (count_numbers(e, &k) == YES)
                    return YES;
            }
            if (correct_exp(e, &k) == YES)
                return YES;
            return NO; 
        }
        if (e[k + 1] == '-' || e[k + 1] == '+')
            return NO;
        k++;
    }
    return NO;
}

int find_num(char string[STR_MAX + 1])
{
    char dictionary[WORD_MAX + 1] = "+-.0123456789eE";
    char expr[STR_MAX + 1];
    expr[0] = '\0';
    
    int flag = 0, flag_2 = 0;
    size_t num_of_letter = 0, i = 0;
    while (string[i] != '\0')
    {
        flag = 0;
        for (size_t j = 0; dictionary[j] != '\0'; j++)
            if (string[i] == dictionary[j])
                flag = 1;
        if (flag_2 && flag)
            return NO;
        if (flag == 1 && string[i] != '\0')
            add_letter(expr, &num_of_letter, string, i);
        if (flag == 0 || string[i + 1] == '\0')
        {
            if (string[i] != '\t' && string[i] != ' ' && string[i] != '\r' && string[i] != '\n' && string[i + 1] != '\0')
                return NO;
            if (expr[0] != '\0')
                flag_2 = 1;
        }
        i++;
    }
    if (expr[0] == '\0')
        return NO;
    if (is_num(expr) == YES)
        return YES;
    if (is_num(expr) == NO)
        return NO;
    return NO;
}