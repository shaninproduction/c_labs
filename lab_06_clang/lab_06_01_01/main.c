#include "libs.h"
#include "constants.h"
#include "io.h"
#include "sort.h"
#include "binsearch.h"

void show_error(int code)
{
    switch (code)
    {
        case INVALID_ARGS:
            puts("Невалидные аргументы запуска!");
            break;
        case INVALID_FILE:
            puts("Невалидный файл");
            break;
        case INVALID_DATA:
            puts("Невалидные данные в файле");
            break;
        case OVERFLOW_ERR:
            puts("Ошибка переполнения");
            break;
        case INVALID_STRING:
            puts("Невалидное поле файле");
            break;
        case OK:
            puts("Программа завершилась успешно");
            break;
        default:
            puts("Неизвестное поведение");
            break;
    }
}

int check_key(char *key, char *field)
{
    if (!key)
        return INVALID_ARGS;

    int len = strlen(key);
    if (len > MAX_NAME)
        return INVALID_ARGS;

    if (!strcmp(field, "year"))
    {
        int tmp = atoi(key);
        if (tmp <= 0 || (log10(tmp) + 1) < strlen(key))
        {
            return INVALID_ARGS;
        }
    }

    return OK;
}

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 4)
    {
        //show_error(INVALID_ARGS);
        return INVALID_ARGS;
    }
    
    int err, length = 0;
    int *plen = &length;

    const char *path = argv[1];
    const char *field = argv[2];

    if (strcmp(field, "title") && strcmp(field, "name") && strcmp(field, "year"))
    {
        //show_error(INVALID_ARGS);
        return INVALID_ARGS;
    }

    cinema_t arr[MAX_ARR]; 
    err = get_arr(path, arr, plen, field);
    
    if (err)
    {
        //show_error(err);
        return err;
    }

    if (length == 0)
    {
        //show_error(INVALID_FILE);
        return INVALID_FILE;
    }

    if (argc == 4)
    {
        err = check_key(argv[3], argv[2]);
        if (err)
        {
            //show_error(err);
            return err;
        }        

        int index = binsearch(arr, length, argv[3], field);
        if (index == -1)
        {
            puts("Not found");
        }
        else
        {
            print_elem(arr[index]);
        }
    }
    else
    {
        print_arr(arr, length);
    }

    //show_error(OK);    
    return OK;
}
