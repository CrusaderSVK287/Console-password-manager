#ifndef LIST_H
#define LIST_H

#include "defines.h"
#include "options.h"
#include <dirent.h> 
#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Function prints all files in a directory, excluding the master_password_hash_file
 * 
 */
void command_list(struct options* opt);

#endif
