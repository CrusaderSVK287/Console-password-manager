#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "string_colors.h"
#include "../../lib/sha-256.h"

#define PASSL_WEAK 1
#define PASSL_DECENT 2
#define PASSL_STRONG 3

/**
 * @brief Get the password from the user in plain text
 * 
 * @return pointer to the typed password
 */
char* get_password();

/**
 * @brief function checks whether the password is strong enough and gives feedback
 *        - strong
 *        - decent
 *        - weak
 * 
 * @return true if the password is eighter strong or decent
 * @return false if the password is weak
 */
bool is_password_valid(char* password);

/**
 * @brief function prints to the stdout information about current password security level.
 * 
 * @param level level of password security. 1 - weak, 2 - decent, 3 - strong
 * 
 * @return true if level is 3
 * @return false if level is 1 
 * @return eighter depending on user choice if level is 2
 */
bool print_password_security_level(int level);

/**
 * @brief Function hashes given password using SHA256 and returns character pointer to said hash
 * 
 * @param password password to be hashed
 * @return char pointer to hash of the given password
 */
char* hash256(char* password);

/**
 * @brief Function takes input from user, hashes it and compares the produced hash with the stored one
 * 
 * @param input is optiotional input string. can be Null.
 * @return true if hashes match
 * @return false if they do not
 */
bool check_password(char* input);