#include "constants.h"

int get_data(FILE *file, cinema_t *elem);
int get_arr(const char *path, cinema_t arr[15], int *length, const char *field);
void print_elem(cinema_t elem);
void print_arr(cinema_t arr[15], int length);
int check_str(char *str);