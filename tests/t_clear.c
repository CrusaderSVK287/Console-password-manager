#include "greatest.h"
#include "../src/clear.c"
#include "../src/options.c"

TEST return_true_if_file_can_be_deleted() {
    char** t = malloc(4*sizeof(char*));
    t[0] = "password_manager";
    t[1] = "clear";
    t[2] = "TESTS";
    t[3] = "TEST123";
    
    ASSERT(can_be_deleted(4,t,"test"));
    ASSERT(can_be_deleted(4,t,"test"));
    PASS();
}

TEST return_false_if_file_cannot_be_deleted() {
    char** t = malloc(4*sizeof(char*));
    t[0] = "password_manager";
    t[1] = "clear";
    t[2] = "TESTS";
    t[3] = "TEST123";

    ASSERT_FALSE(can_be_deleted(4,t,"TESTS"));
    ASSERT_FALSE(can_be_deleted(4,t,"TEST123"));
    PASS();
}

TEST protected_file_should_not_be_removed() {
    char** t = malloc(4*sizeof(char*));
    t[0] = "password_manager";
    t[1] = "clear";
    t[2] = "TESTS";
    t[3] = "TEST123";

    char* test_one = malloc(14); strcpy(test_one,"TESTS_PROTECT");
    char* test_two = malloc(16); strcpy(test_two,"TEST123_PROTECT");

    ASSERT_FALSE(can_be_deleted(4,t,test_one));
    ASSERT_FALSE(can_be_deleted(4,t,test_two));
    PASS();
}

TEST protected_file_should_be_removed() {
    char** t = malloc(4*sizeof(char*));
    t[0] = "password_manager";
    t[1] = "clear";
    t[2] = "TESTS";
    t[3] = "TEST123";

    char* test = malloc(13);
    strcpy(test,"nope_PROTECT");

    ASSERT(can_be_deleted(4,t,test));
    PASS();
}

SUITE(clear) {
    RUN_TEST(return_true_if_file_can_be_deleted);
    RUN_TEST(return_false_if_file_cannot_be_deleted);
    RUN_TEST(protected_file_should_not_be_removed);
    RUN_TEST(protected_file_should_be_removed);
}