#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

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