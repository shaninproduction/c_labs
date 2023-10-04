#ifndef TEST_SORT_H
#define TEST_SORT_H

#include <check.h>

#include "libs.h"
#include "constants.h"
#include "sort.h"
#include "filter.h"

Suite *sort_suite(Suite *suite);
Suite *filter_suite(Suite *suite);

#define DIFF_ARRAYS 100

#endif
