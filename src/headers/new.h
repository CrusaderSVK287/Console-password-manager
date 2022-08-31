#ifndef NEW_H
#define NEW_H

#include "defines.h"
#include "options.h"
#include "password.h"
#include "help.h"
#include "cypher.h"
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
 * @brief Goes through the process of adding a new password to manage
 * 
 * Options: --list -l -help -h --protect -p
 */
void command_new(struct options* opts);

#endif
