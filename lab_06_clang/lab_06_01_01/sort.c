#include "libs.h"
#include "constants.h"

void sort(cinema_t arr[MAX_ARR], int length, const char *field)
{
    if (!strcmp(field, "title"))
    {
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length - 1; j++)
            {
                if (strcmp(arr[j].title, arr[j + 1].title) > 0)
                {
                    cinema_t temp;
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }       
        }
    }

    if (!strcmp(field, "name"))
    {
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length - 1; j++)
            {
                if (strcmp(arr[j].name, arr[j + 1].name) > 0)
                {
                    cinema_t temp;
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }       
        }
    }

    if (!strcmp(field, "year"))
    {
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length - 1; j++)
            {
                if (arr[j].year > arr[j + 1].year)
                {
                    cinema_t temp;
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}