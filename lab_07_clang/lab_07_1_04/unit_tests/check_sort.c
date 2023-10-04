#include "check_tests.h"

#define EPS 1e-9

int compare_arr(int *a, int *b, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (a[i] != b[i])
            return DIFF_ARRAYS;
    }
    
    return OK;
}

int comp_double_arr(double *a, double *b, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (fabs(a[i] - b[i]) >= EPS)
            return DIFF_ARRAYS;
    }
    
    return OK;
}

int comp_char_arr(char *a, char *b, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (a[i] != b[i])
            return DIFF_ARRAYS;
    }
    
    return OK;
}

int comparator_double(const void *elem1, const void *elem2)
{
    double num1 = *((double *) elem1);
    double num2 = *((double *) elem2);

    if (num1 > num2)
        return 1;

    else
        return -1;
}

int comparator_char(const void *elem1, const void *elem2)
{
    char ch1 = *((char *) elem1);
    char ch2 = *((char *) elem2);

    if (ch1 > ch2)
        return 1;
    else 
        return -1;
}


// Отсортированный массив
START_TEST(sorted_arr)
{
    int err;

    int arr_a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr_b[] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t len = 8;

    mysort(arr_a, len, sizeof(int), comparator_int);

    err = compare_arr(arr_a, arr_b, len);

    ck_assert_int_eq(err, OK);   
}
END_TEST

// Отсортированный в обратном порядке
START_TEST(reverse_sorted_arr)
{
    int err;

    int arr_a[] = {7, 6, 5, 4, 3, 2, 1};
    int arr_b[] = {1, 2, 3, 4, 5, 6, 7};
    size_t len = 7;

    mysort(arr_a, len, sizeof(int), comparator_int);

    err = compare_arr(arr_a, arr_b, len);

    ck_assert_int_eq(err, OK);   
}
END_TEST

// Один элемент
START_TEST(one_elem_arr)
{
    int err;

    int arr_a[] = {1};
    int arr_b[] = {1};
    size_t len = 1;

    mysort(arr_a, len, sizeof(int), comparator_int);

    err = compare_arr(arr_a, arr_b, len);

    ck_assert_int_eq(err, OK);   
}
END_TEST

// Массив с отрицательными числами
START_TEST(negative_elems_arr)
{
    int err;

    int arr_a[] = {0, -1, 2, -3, 4, 5, 6, 7, 8};
    int arr_b[] = {-3, -1, 0, 2, 4, 5, 6, 7, 8};
    size_t len = 9;

    mysort(arr_a, len, sizeof(int), comparator_int);

    err = compare_arr(arr_a, arr_b, len);

    ck_assert_int_eq(err, OK);   
}
END_TEST


// Сортировка типа double
START_TEST(sort_double)
{
    int err;

    double arr_a[] = {1.2, -1.2, 0.0, 0.5};
    double arr_b[] = {-1.2, 0.0, 0.5, 1.2};
    size_t len = 4;

    mysort(arr_a, len, sizeof(double), comparator_double);

    err = comp_double_arr(arr_a, arr_b, len);

    ck_assert_int_eq(err, OK);   
}
END_TEST

// Сортировка типа сhar
START_TEST(sort_char)
{
    int err;

    char arr_a[] = {'z', 'c', 'b', 'a'};
    char arr_b[] = {'a', 'b', 'c', 'z'};
    size_t len = 4;

    mysort(arr_a, len, sizeof(char), comparator_char);

    err = comp_char_arr(arr_a, arr_b, len);

    ck_assert_int_eq(err, OK);   
}
END_TEST

Suite *sort_suite(Suite *suite)
{
    TCase *pos;
    pos = tcase_create("pos tests");

    tcase_add_test(pos, sorted_arr);
    tcase_add_test(pos, reverse_sorted_arr);
    tcase_add_test(pos, one_elem_arr);
    tcase_add_test(pos, negative_elems_arr);
    tcase_add_test(pos, sort_double);
    tcase_add_test(pos, sort_char);

    suite_add_tcase(suite, pos);

    return suite;
}