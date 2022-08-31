#ifndef CYPHER_H
#define CYPHER_H

#include "defines.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Function encrypts the given password and returns a pointer to the encrypted string
 * 
 * @param password_to_encrypt reference to the password
 * @return char* encrypted string
 */
char* encrypt(char* password_to_encrypt);

/**
 * @brief Function decrypts the given string and returns a pointer to the decrypted string
 * 
 * @param password_to_decrypt encrypted string
 * @return char* decrypted password
 */
char* decrypt(char* password_to_decrypt);

#endif
