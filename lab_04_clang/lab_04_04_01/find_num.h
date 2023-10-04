#ifndef STRING_H
#define STRING_H

#include <stdlib.h>

#define STR_MAX 256
#define WORD_MAX 16

#define EXIT_ZERO_LEN 3
#define YES 4
#define NO 6

int read_str(char string[STR_MAX + 1]);
int add_letter(char word[STR_MAX + 1], size_t *num_of_letter, char string[STR_MAX + 1], size_t i);
int find_num(char string[STR_MAX + 1]);
int is_num(char e[STR_MAX + 1]);
int count_numbers(char e[STR_MAX + 1], size_t *k);
int compare(char str1[17], int ch);
#endif
