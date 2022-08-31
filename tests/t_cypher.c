#include "greatest.h"
#include "../src/cypher.c"

#define PASSWORD_TEST_SHORT "TEST_TEST_test_123"
#define PASSWORD_TEST_MEDIUM "UIZGUTJZFHGJHgkufjghjhfJHFHc89465896@@@!!_-wdafesrafe.wfer.qwfQQF455845}{@&#][[["
#define PASSWORD_TEST_LONG "iuizgtfghgjhjfghjfhvmgjdskfvghqjwhfgddhgsdjhkfguzfgwefhguqfgwuezhwgez fzgezifqg izfgfig qigfiwgieuifgquf qzfgizqgiqefgizwegfiqef qe4q6 f5q6 4e9 f5q6  q6e5 gre 65es48 65ts5 h6e4h 68ae4 he86 4h3eh6ar 354er 6h4 r hae4rh 65er4h 6ae4rh6ae4rh4aer6h4erh4 ha65 4a6er4hare4h6ae4r6h 46ae4h6er4 6ea4h 6e4h6earh 6r4h6ear4h6ae54h6aer5h4re54h684h3aer86h5a5he5rh 66are4 hh5eh8ae68h 65r648h68e684 h64865 56 h846e6 8ar468h 648846 68a4er684486h846er468h6a4e8r hh "

TEST short_password() {
    char* password = malloc(1024);
    strcpy(password,PASSWORD_TEST_SHORT);
    unsigned char* en = encrypt(password);
    char* de = decrypt(en);
    ASSERT_STR_EQ(PASSWORD_TEST_SHORT,de);
    free(en);
    free(de);
    PASS();
}

TEST medium_password() {
    char* password = malloc(1024);
    strcpy(password,PASSWORD_TEST_MEDIUM);
    unsigned char* en = encrypt(password);
    char* de = decrypt(en);
    ASSERT_STR_EQ(PASSWORD_TEST_MEDIUM,de);
    free(en);
    free(de);
    PASS();
}

TEST long_password() {
    char* password = malloc(1024);
    strcpy(password,PASSWORD_TEST_LONG);
    unsigned char* en = encrypt(password);
    char* de = decrypt(en);
    ASSERT_STR_EQ(PASSWORD_TEST_LONG,de);
    free(en);
    free(de);
    PASS();
}

SUITE(cypher) {
    RUN_TEST(short_password);
    RUN_TEST(medium_password);
    RUN_TEST(long_password);
}