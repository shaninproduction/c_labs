#include "libs.h"
#include "constants.h"
#include "sort.h"

int check_str(char *str)
{
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(str[i]) && str[i] != ' ')
            return INVALID_STRING;
    }

    if (islower(str[0]))
        return INVALID_STRING;

    return OK;
}

int get_data(FILE *file, cinema_t *elem)
{
    // Чтение названия фильма
    int err;
    char *check;
    check = fgets(elem->title, sizeof(elem->title), file);
    if (check == NULL && feof(file))
    {
        return END_OF_FILE;
    }
    else if (check == NULL && !feof(file))
    {
        return INVALID_FILE;
    }

    if (elem->title[strlen(elem->title) - 1] != '\n')
    {
        return INVALID_DATA;
    }

    if (!strcmp(elem->title, "\n"))
    {
        return INVALID_DATA;
    }
    elem->title[strlen(elem->title) - 1] = '\0';        
    
    // Чтение фамилии автора
    if (fgets(elem->name, sizeof(elem->name), file) == NULL) 
    {
        return INVALID_FILE;
    }

    if (elem->name[strlen(elem->name) - 1] != '\n')
    {
        return INVALID_DATA;
    }

    if (!strcmp(elem->name, "\n"))
    {
        return INVALID_DATA;
    }

    elem->name[strlen(elem->name) - 1] = '\0';

    err = check_str(elem->name);
    if (err)
        return err;

    // Чтение года выхода фильма
    if (fscanf(file, "%d", &(elem->year)) != 1)
    {
        return INVALID_DATA;
    }

    if ((elem->year) < 1)
    {
        return INVALID_DATA;
    }

    fgetc(file);
    return OK;
}

int get_arr(const char *path, cinema_t arr[MAX_ARR], int *length, const char *field)
{
    int err;
    FILE* file = fopen(path, "r");

    if (file == NULL)
    {
        return INVALID_FILE;
    }

    for (int i = 0; true; i++)
    {   
        cinema_t temp;
        err = get_data(file, &temp);
        
        if (err == END_OF_FILE)
        {
            break;
        }

        if (i > MAX_ARR - 1)
        {
            return OVERFLOW_ERR;
        }
        else if (err)
        {
            fclose(file);
            return err;
        }

        strcpy(arr[i].title, temp.title);
        strcpy(arr[i].name, temp.name);
        arr[i].year = temp.year;

        (*length)++;
        sort(arr, *length, field);
    }
    
    fclose(file);
    return OK;
}

void print_elem(cinema_t elem)
{
    printf("%s\n%s\n%d\n", elem.title, elem.name, elem.year);
}

void print_arr(cinema_t arr[MAX_ARR], int length)
{
    for (int i = 0; i < length; i++)
    {
        print_elem(arr[i]);
    }
}