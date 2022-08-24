#include "greatest.h"
#include "../src/password.c"
#include "../lib/sha-256.c"

TEST password_not_valid_return_false() {
    ASSERT_FALSE(is_password_valid("abc"));             //short
    ASSERT_FALSE(is_password_valid("abc[]efghijkl"));   //invalid character
    ASSERT_FALSE(is_password_valid("ABCDEFGHIJKlmno")); //not enough security features
    PASS();
}

TEST password_is_valid_return_true() {
    ASSERT(is_password_valid("ABcd1234@!"));
    PASS();
}

SUITE(password) {
    RUN_TEST(password_is_valid_return_true);
    RUN_TEST(password_not_valid_return_false);
}