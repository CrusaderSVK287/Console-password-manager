#include "greatest.h"
#include "../src/new.c"
#include "../src/parser.c"
#include "../src/reset.c"
#include "../src/setup.c"


TEST parse_options_args_null_return_null() {
    ASSERT_EQ(NULL,parse_options(5,NULL));
    ASSERT_EQ(NULL,parse_options(1,NULL));
    PASS();
}

TEST parse_options_valid_args() {
    int argc = 4;
    char** argv = calloc(argc,sizeof(char*));
    argv[0] = "test";
    argv[1] = "another test";
    argv[2] = "-f";
    argv[3] = "--list";

    struct options* result = parse_options(argc,argv);

    ASSERT_FALSE(result->help);
    ASSERT_FALSE(result->protect);
    ASSERT(result->force);
    ASSERT(result->list);

    PASS();
}

TEST option_struct_destroyed() {
    struct options* tmp = calloc(1,sizeof(struct options));
    tmp = destroy_options(tmp);
    ASSERT_EQ(NULL,tmp);
    PASS();
}

SUITE(options) {
    RUN_TEST(parse_options_args_null_return_null);
    RUN_TEST(parse_options_valid_args);
    RUN_TEST(option_struct_destroyed);
}
