#include <stdio.h>
#include <string.h>

char *my_strpbrk(const char *s1, const char *s2)
{
    size_t len1 = strlen(s1), len2 = strlen(s2);

    for (size_t i = 0; i < len1; i++)
    {
        for (size_t j = 0; j < len2; j++)
        {
            if (s1[i] == s2[j])
            {
                return (char *) &s1[i];
            }
        }   
    }
    return NULL;
}


size_t my_strspn(const char *s1, const char *s2)
{
    const char *p;
    const char *a;
    size_t count = 0;

    for (p = s1; *p != '\0'; p++)
    {
        for (a = s2; *a != '\0'; a++)
        {
            if (*p == *a)
            {
                count++;
                break;
            }
        }
        if (*a == '\0')
            return count;
    }
    return count;
}


size_t my_strcspn(const char *str_1, const char *str_2)
{
    size_t counter = 0;
    size_t i;
    int flag;
    for (i = 0; str_1[i] != '\0'; i++)
    {
        flag = 1;
        for (size_t j = 0; str_2[j] != '\0' && flag == 1; j++)
            if (str_1[i] == str_2[j])
                flag = 0;
        if (flag == 1)
            counter += 1;
        else
            return counter;
    }
    return counter;
}


const char *my_strrchr(const char *string, int symbol)
{
    size_t len = strlen(string);

    for (size_t i = len; i != 0; i -= 1)
        if (string[i] == symbol)
            return &string[i];

    if (string[0] == symbol)
        return &string[0];

    return NULL;
}

const char *my_strchr(const char *string, int symbol)
{
    size_t i;
    for (i = 0; string[i]; i++)
        if (string[i] == symbol)
            return &string[i];

    if (!string[i] && !symbol)
        return &string[i];

    return NULL;
}