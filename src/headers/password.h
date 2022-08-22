#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

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
 * @brief Function hashes given password using SHA256 and returns character pointer to said hash
 * 
 * @param password password to be hashed
 * @return char pointer to hash of the given password
 */
char* hash256(char* password);

/**
 * @brief function prints to the stdout information about current password security level.
 * 
 * @param level level of password security. 1 - weak, 2 - decent, 3 - strong
 * 
 * @return true if level is 3
 * @return false if level is less than 3 
 */
bool print_password_security_level(int level);
