#ifndef RESET_H
#define RESET_H

#include "defines.h"
#include "help.h"
#include "options.h"
#include "password.h"
#include "setup.h"
#include <stdio.h>
#include <dirent.h>

/**
 * @brief Fuction deletes all protected passwords along with master password hash code and than calls the setup function to set a new password.
 *        Function requires validation by entering the master key
 * 
 * @param opts options struct
 */
void command_reset(struct options* opts);

#endif
