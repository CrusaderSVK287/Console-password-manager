#include "headers/options.h"

bool are_options_valid(bool list, bool force, bool help, bool protect, struct options* opt) {
    if(opt == NULL) {
        return false;
    }
    bool valid = true;
    if(opt->list == true && list == false) {
        fprintf(stderr,"--list is not a valid option\n");
        valid = false;
    }
    if(opt->force == true && force == false) {
        fprintf(stderr,"--force is not a valid option\n");
        valid = false;
    }
    if(opt->help == true && help == false) {
        fprintf(stderr,"--help is not a valid option\n");
        valid = false;
    }
    if(opt->protect == true && protect == false) {
        fprintf(stderr,"--protect is not a valid option\n");
        valid = false;
    }
    return valid;
}