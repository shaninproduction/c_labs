#include "check_tests.h"

int main(void)
{
    int errors_count;

    Suite *suite = suite_create("unit tests");
    SRunner *runner;

    suite = sort_suite(suite);
    suite = filter_suite(suite);

    runner = srunner_create(suite);

    srunner_run_all(runner, CK_VERBOSE);

    errors_count = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (errors_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;;
}
