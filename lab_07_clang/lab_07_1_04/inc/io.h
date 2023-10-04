#ifndef IO_H
#define IO_H

#include "libs.h"

int get_len(char *filename, size_t *len);
int get_arr(char *filename, int *beg, int *end);
int print_in_file(char *filename, int *beg, int *end);

#endif
