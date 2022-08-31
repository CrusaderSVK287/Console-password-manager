#ifndef GET_H
#define GET_H

#include "defines.h"
#include "options.h"
#include "password.h"
#include "help.h"
#include "cypher.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef _WIN32
#include <io.h>
#define F_OK 0
#define access _access
#endif

/**
 * @brief Command decyphers a password and prints it to the terminal in plain text
 * 
 * @param opts options struct
 */
void command_get(struct options* opts);

#endif
