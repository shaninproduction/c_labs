#include "libs.h"

#define OK 0
#define INVALID_ARGS -1
#define INVALID_FILE -2
#define INVALID_DATA -3
#define OVERFLOW_ERR -4
#define INVALID_STRING -5

#define MAX_TITLE 25
#define MAX_NAME 25
#define MAX_ARR 15
#define END_OF_FILE 100

#ifndef STRUCT
#define STRUCT
typedef struct
{
    char title[27];
    char name[27];
    int year;
} cinema_t;
#endif
