#include "headers/reset.h"

void command_reset(struct options* opts) {
    if(!are_options_valid(false,false,true,false,opts)) {
        return;
    }
    if(opts->help) help_command_reset();

    printf("This action will delete all stored protected passwords and will require a new master password to be set\n");
    if(!check_password()) {
        return;
    }
    remove(".password_manager_data/master_password_hash_code");
    setup();
}