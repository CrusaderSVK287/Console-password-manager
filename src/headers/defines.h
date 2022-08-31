#ifndef DEFINES_H
#define DEFINES_H

#define STRC_BLACK "\033[0;30m"
#define STRC_RED "\033[0;31m"
#define STRC_GREEN "\033[0;32m"
#define STRC_YELLOW "\033[0;33m"
#define STRC_BLUE "\033[0;34m"
#define STRC_PURPLE "\033[0;35m"
#define STRC_CYAN "\033[0;36m"
#define STRC_WHITE "\033[0;37m"

#define STRC_DEFAULT STRC_WHITE

#define DATA_DIR ".password_manager_data"
#define DATA_DIR_SLASH ".password_manager_data/"
#define MASTER_PASSWORD_HASH_FILE ".password_manager_data/master_password_hash_code"
#define MASTER_PASSWORD_FILE_NAME "master_password_hash_code"

#define PASSL_WEAK 1
#define PASSL_DECENT 2
#define PASSL_STRONG 3

//#define KEY "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
#define KEY "IZUTJRHDGFGHKHILUZUTZFJRHGFQFWQF"    //USED FOR DEBUGGING WITH "RANDOM" KEY!!!
#define KEY_LENGHT 32

#include <string.h>

/**
 * @brief Function replaces old chars with new in the given string
 * 
 * @param str input string
 * @param old char to be replaced
 * @param new char to be put in the place of old chars
 */
void string_replace(char* str, char old, char new);

/**
 * @brief reverses the given string
 * 
 * @param str input string
 */
void string_reverse(char* str);

#endif
