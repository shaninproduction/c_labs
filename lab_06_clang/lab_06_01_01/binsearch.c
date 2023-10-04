#include "libs.h"
#include "constants.h"

int binsearch(cinema_t data[], int length, char *target, const char *field)
{
    int left = 0;
    int right = length - 1;
    int mid = (right + left) / 2;

    if (!strcmp(field, "title"))
    {
        while (left <= right)
        {
            if (!strcmp(data[mid].title, target))
                return mid;
            
            if (strcmp(data[mid].title, target) < 0)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }

            mid = (left + right) / 2;
        }
    }
    
    if (!strcmp(field, "name"))
    {
        while (left <= right)
        {
            if (!strcmp(data[mid].name, target))
                return mid;
            
            if (strcmp(data[mid].name, target) < 0)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
            
            mid = (left + right) / 2;
        }
    }

    if (!strcmp(field, "year"))
    {
        int int_target = atoi(target);
        while (left <= right)
        {
            if (data[mid].year == int_target)
                return mid;
            
            if (data[mid].year < int_target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
            
            mid = (left + right) / 2;
        }
    }

    return -1;
}