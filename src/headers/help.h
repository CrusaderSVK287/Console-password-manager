
#ifndef HELP_H
#define HELP_H

#include "defines.h"
#include "options.h"
#include <stdio.h>

/**
 * @brief Function prints all the help pages
 * 
 */
void command_help(struct options* opt);

/**
 * @brief Each of theese functions prints a help page for a coresponding command
 * 
 */
void help_command_help();

/**
 * @brief help page for new command
 * 
 */
void help_command_new();

#endif
