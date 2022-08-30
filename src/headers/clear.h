#ifndef CLEAR_H
#define CLEAR_H

#include "defines.h"
#include "help.h"
#include "options.h"
#include "password.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Function asks for a master password and if entered correctly, deletes all stored passwords, excluding those specified in the arguments
 * 
 * @param args arguments given in the command line
 * @param argc number of arguments given in the command line pattern
 * @param opts options struct containing selected options 
 */
void command_clear(struct options* opts, int argc, char** args);

/**
 * @brief Function evaluates whether the file with the given name should be deleted
 * 
 * @param argc number of arguments given from the command line
 * @param args arguments given from the command line
 * @param file name of curretly proccessed file
 * @return true if file should be deleted
 * @return false otherwise
 */
bool can_be_deleted(int argc, char** args, char* file);

#endif
