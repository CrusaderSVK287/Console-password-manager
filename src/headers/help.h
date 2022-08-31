
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
void help_command_new();
void help_command_get();
void help_command_list();
void help_command_delete();
void help_command_clear();
void help_command_reset();

#endif
