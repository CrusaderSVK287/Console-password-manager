#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "headers/options.h"
#include "headers/new.h"

/**
 * @brief function creates a options struct, goes through all arguments and sets the appropriate
 *        members to true. Only parses arguments starting with a dash -
 * 
 * @param argc number of arguments.
 * @param argv arguments passed from command line.
 * @return pointer to the created optrions struct
 */
struct options* parse_options(int argc ,char** argv);

/**
 * @brief function compares passed argument arg to both cmp short and cmp long,
 *        and if one of them is the same, sets the option opt to true
 * 
 * @param opt option from options struct to be set to true if evaluated to true 
 * @param arg argument passed from CL
 * @param cmp_short string that the argument is being compared to, short e.g. -f
 * @param cmp_long string that the argument is being compared to, long e.g. --force
 */
void parse(bool* opt, char* arg, char* cmp_short, char* cmp_long);

/**
 * @brief Frees the allocated struct from memory
 * 
 * @param opt options struct to be freed
 * @return NULL
 */
struct options* destroy_options(struct options* opt);

/**
 * @brief Function parses and runs a command based on given argument. In case a wrong command has been given, displays an error message
 * 
 * @param arg argument given by the command line, typicaly the seconds one 
 * @param opt options struct to get all the options
 */
void run_command(char** args, struct options* opt);
