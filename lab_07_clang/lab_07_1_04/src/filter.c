#include "libs.h"
#include "constants.h"

double calc_avg(const int *beg, const int *end)
{
    int sum = 0;
    int count = 0;

    if (beg >= end)
        return INVALID_POINTERS;    

    for (int *cur = (int *) beg; cur < end; cur++)
    {
        sum += *cur;
        count++;
    }

    return (double) sum / count;
}

int get_len_filtered(const int *beg, const int *end, size_t *len)
{
    double avg;    

    avg = calc_avg(beg, end);

    for (int *cur = (int *) beg; cur < end; cur++)
    {
        if (*cur > avg)
            *len += 1;
    }

    if (*len == 0)
        return ZERO_LEN_AFTER_FILT;

    return OK;
}

void get_array_filtered(const int *beg_src, const int *end_src, int *beg_dst)
{
    double avg;
    int *cur_dst = beg_dst;
    avg = calc_avg(beg_src, end_src);

    for (int *cur = (int *) beg_src; cur < end_src; cur++)
    {
        if (*cur > avg)
        {
            *cur_dst = *cur;
            cur_dst++;
        }
    }
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int err;
    size_t len = 0;

    if (pb_src == NULL || pe_src == NULL)
        return INVALID_POINTERS;
    
    if (*pb_dst != NULL || *pe_dst != NULL)
        return INVALID_POINTERS;

    if (pb_src >= pe_src)
        return INVALID_POINTERS;

    err = get_len_filtered(pb_src, pe_src, &len);

    if (err)
        return err;

    *pb_dst = malloc(sizeof(int) * len);

    if (pb_dst == NULL)
        return INVALID_POINTERS;

    *pe_dst = *pb_dst + len;

    get_array_filtered(pb_src, pe_src, *pb_dst);

    return OK;
}