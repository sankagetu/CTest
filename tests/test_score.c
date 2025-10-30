#include <criterion/criterion.h>
#include "score.h"

Test(score, average_basic) {
    int a[] = {100, 80, 60};
    cr_assert_eq(calc_average_score(3, a), 80);
}

Test(score, average_zero_size) {
    cr_assert_eq(calc_average_score(0, 0), 0);
}

Test(score, average_robust) {
    int a[] = {1, 2, 3, 4};
    cr_assert(calc_average_score(4, a) >= 0);
}
