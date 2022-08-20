#include "greatest.h"

extern SUITE(options);

GREATEST_MAIN_DEFS();

int run_tests() {
    GREATEST_INIT();

    RUN_SUITE(options);

    return greatest_all_passed();
}

int main(int argc, char** argv) {
    __gcov_flush();
    GREATEST_MAIN_BEGIN();
    run_tests();
    GREATEST_MAIN_END();
}
