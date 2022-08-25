#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdbool.h>
#include "defines.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief struct contains flags that were set while executing program.
 * 
 *      list - shows list of saved passwords
 *      force - forces action without asking for confirmations
 *      help - shows help page for action
 *      protect - sets passwords to be password protected by the master password
 */
struct options {
    bool list;
    bool force;
    bool help;
    bool protect;
};

/**
 * @brief function evaluates whether all selected options are valid
 * 
 * @param list tells whether the -l is valid
 * @param force tells whether the -f is valid
 * @param help tells whether the -h is valid
 * @param protect tells whether the -p is valid
 * @param opt options struct containing the selected options
 * @return true if everything is validated
 * @return false otherwise;
 */
bool are_options_valid(bool list, bool force, bool help, bool protect, struct options* opt);

#endif
