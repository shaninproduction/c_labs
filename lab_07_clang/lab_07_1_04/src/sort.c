#include "libs.h"
#include "constants.h"

int comparator_int(const void *elem1, const void *elem2)
{
    int num1 = *((int *) elem1);
    int num2 = *((int *) elem2);

    return num1 - num2;
}

void swap(void *left, void *right, size_t size, char *buffer)
{
    memcpy(&buffer, left, size);
    memcpy(left, right, size);
    memcpy(right, &buffer, size);
}

void mysort(void *first, size_t len, size_t size, int (*comparator)(const void *, const void *))
{
    int flag = 1;

    char *left = (char *)first;
    char *right = (char *)first;
    right += size * len - size;
    char buffer[100];

    while ((left < right) && flag)
    {
        flag = 0;

        for (char *i = left; i < right; i += size)
        {
            char *j = i + size;
            if (comparator((const void *)i, (const void *)j) > 0)
            {
                swap(i, j, size, buffer);
                flag = 1;
            }
        }

        right -= size;
        for (char *i = right; i > left; i -= size)
        {
            char *j = i - size;
            if (comparator((const void *)j, (const void *)i) > 0)
            {
                swap(j, i, size, buffer);
                flag = 1;
            }
        }

        left += size;
    }
}