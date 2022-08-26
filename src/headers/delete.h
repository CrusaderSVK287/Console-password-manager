#ifndef DELETE_H
#define DELETE_H

#include "options.h"
#include "defines.h"
#include "help.h"
#include "password.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifdef _WIN32
#include <io.h>
#define F_OK 0
#define access _access
#endif

/**
 * @brief Function deletes specified stored password based on the first non-option argument.
 *        To delete a password, the user has to type in the master password, unless the --force option is used
 *        Protected passwords however ALWAYS require master password to delete
 * 
 * @param args arguments put in from the command line
 * @param argc number of args typed to the command line
 * @param opts options struct containing flags
 */
void command_delete(char** args, int argc ,struct options* opts);

#endif
