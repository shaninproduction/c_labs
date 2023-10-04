#ifndef FILTER_H
#define FILTER_H

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
void get_array_filtered(const int *beg_src, const int *end_src, int *beg_dst);
int get_len_filtered(const int *beg, const int *end, size_t *len);
double calc_avg(const int *beg, const int *end);

#endif