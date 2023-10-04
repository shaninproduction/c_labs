#include "libs.h"
#include "constants.h"
#include "io.h"
#include "filter.h"
#include "sort.h"

int check_args(const char **argv, int argc, int *mode)
{
    if (argc < 3 || argc > 4)
        return INVALID_ARGS;

    if (argc == 4 && strcmp(argv[3], "f"))
        return INVALID_ARGS;
    
    if (argc == 4 && !strcmp(argv[3], "f"))
        *mode = 1;

    return OK;
}

// void print_arr(int *arr, size_t len)
// {
//     printf("arr: ");
//     for (size_t i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// void print_arr_filt(const int *beg, const int *end)
// {
//     printf("filtered arr: ");
//     for (int *cur = (int *) beg; cur < end; cur++)
//     {
//         printf("%d ", *cur);
//     }
//     printf("\n");
// }

int main(int argc, char const *argv[])
{
    int err, to_filter = 0;
    int *filtered_beg = NULL, *filtered_end = NULL;
    bool filtered = false;
    char *file_in = (char *) argv[1];
    char *file_out = (char *) argv[2];
    size_t len = 0;

    err = check_args(argv, argc, &to_filter);

    if (err)
        return err;

    err = get_len(file_in, &len);

    if (err)
        return err;
    
    int *arr = malloc(sizeof(int) * len);

    err = get_arr(file_in, arr, arr + len);

    if (err)
    {
        free(arr);
        return err;
    }

    if (to_filter)
    {
        err = key(arr, arr + len, &filtered_beg, &filtered_end);
        free(arr);
        
        if (err)
            return err;
        
        filtered = true;
    }

    if (filtered)
    {
        mysort((void *)filtered_beg, filtered_end - filtered_beg, sizeof(int), comparator_int);
        err = print_in_file(file_out, filtered_beg, filtered_end);

        if (err)
        {
            free(filtered_beg);
            return err;
        }

        free(filtered_beg);
    }
    else
    {
        mysort((void *)arr, len, sizeof(int), comparator_int);
        err = print_in_file(file_out, arr, arr + len);
        free(arr);

        if (err)
            return err;            
    }
    
    return OK;
}
    