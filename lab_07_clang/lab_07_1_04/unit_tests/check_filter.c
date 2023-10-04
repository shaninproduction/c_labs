#include "check_tests.h"

static int compare_arr(int *a, int *b, size_t len_a, size_t len_b)
{
    if (len_a != len_b)
        return DIFF_ARRAYS;

    for (size_t i = 0; i < len_a; i++)
    {
        if (a[i] != b[i])
            return DIFF_ARRAYS;
    }
    
    return OK;
}

// ПОЗИТИВНЫЕ ТЕСТЫ

// Отфильтровать все кроме одного
START_TEST(filter_all_except_one)
{
    int err;

    size_t len_src = 6;
    const int pb_src[] = {100, 1, 1, 1, 1, 1};
    const int *pe_src = pb_src + len_src;
    
    int *pb_dst = NULL, *pe_dst = NULL;

    int valid[] = {100};
    size_t len_valid = 1;

    err = key(pb_src, pe_src, &pb_dst, &pe_dst);

    ck_assert_int_eq(err, OK);

    err = compare_arr(pb_dst, valid, pe_dst - pb_dst, len_valid);

    ck_assert_int_eq(err, OK);

    free(pb_dst);
}
END_TEST

// Отфильтровать половину
START_TEST(filter_half)
{
    int err;

    size_t len_src = 6;
    const int pb_src[] = {1, 2, 3, 4, 5, 6};
    const int *pe_src = pb_src + len_src;
    
    int *pb_dst = NULL, *pe_dst = NULL;

    int valid[] = {4, 5, 6};
    size_t len_valid = 3;

    err = key(pb_src, pe_src, &pb_dst, &pe_dst);

    ck_assert_int_eq(err, OK);

    err = compare_arr(pb_dst, valid, pe_dst - pb_dst, len_valid);

    ck_assert_int_eq(err, OK);

    free(pb_dst);
}
END_TEST

// НЕГАТИВНЫЕ ТЕСТЫ

// Отфильтровать все
START_TEST(filter_all)
{
    int err;

    size_t len_src = 5;
    const int pb_src[] = {1, 1, 1, 1, 1};
    const int *pe_src = pb_src + len_src;
    
    int *pb_dst = NULL, *pe_dst = NULL;

    err = key(pb_src, pe_src, &pb_dst, &pe_dst);

    ck_assert_int_eq(err, ZERO_LEN_AFTER_FILT);
}
END_TEST

// NULL указатель на начало массива
START_TEST(null_pointer_arr)
{
    int err;

    const int *pb_src = NULL;
    const int *pe_src = NULL;
    
    int *pb_dst, *pe_dst;

    err = key(pb_src, pe_src, &pb_dst, &pe_dst);

    ck_assert_int_eq(err, INVALID_POINTERS);
}
END_TEST

// Не NULL указатель на начало отфльтрованного массива
START_TEST(not_null_pointer_filtered_arr)
{
    int err;

    const int *pb_src = NULL;
    const int *pe_src = NULL;
    
    int *pb_dst = malloc(sizeof(int)), *pe_dst;

    err = key(pb_src, pe_src, &pb_dst, &pe_dst);

    ck_assert_int_eq(err, INVALID_POINTERS);
    free(pb_dst);
}
END_TEST

Suite *filter_suite(Suite *suite)
{
    TCase *pos, *neg;
    pos = tcase_create("pos tests");

    tcase_add_test(pos, filter_all_except_one);
    tcase_add_test(pos, filter_half);

    neg = tcase_create("neg tests");

    tcase_add_test(neg, filter_all);
    tcase_add_test(neg, null_pointer_arr);
    tcase_add_test(neg, not_null_pointer_filtered_arr);

    suite_add_tcase(suite, pos);
    suite_add_tcase(suite, neg);

    return suite;
}