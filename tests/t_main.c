#include "greatest.h"
#include "../src/headers/defines.h"

extern SUITE(options);
extern SUITE(password);

GREATEST_MAIN_DEFS();

int run_tests() {
    GREATEST_INIT();

    RUN_SUITE(options);
    RUN_SUITE(password);

    return greatest_all_passed();
}

int main(int argc, char** argv) {
    __gcov_flush();
    GREATEST_MAIN_BEGIN();
    run_tests();
    printf("%s----------------------\n", STRC_PURPLE);
    GREATEST_PRINT_REPORT();
    printf("\n----------------------\n%s", STRC_DEFAULT);
    GREATEST_MAIN_END();
}
