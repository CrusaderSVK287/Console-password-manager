#include "headers/options.h"

bool are_options_valid(bool list, bool force, bool help, bool protect, struct options* opt) {
    if(opt == NULL) {
        return false;
    }
    bool valid = true;
    if(opt->list != list) {
        fprintf(stderr,"--list -l is not a valid option\n");
        valid = false;
    }
    if(opt->force != force) {
        fprintf(stderr,"--force -f is not a valid option\n");
        valid = false;
    }
    if(opt->help != help) {
        fprintf(stderr,"--help -h is not a valid option\n");
        valid = false;
    }
    if(opt->protect != protect) {
        fprintf(stderr,"--protect -p is not a valid option\n");
        valid = false;
    }
    return valid;
}