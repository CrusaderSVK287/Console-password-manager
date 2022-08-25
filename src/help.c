#include "headers/help.h"

void command_help(struct options* opt) {
    if(!are_options_valid(false,false,false,false,opt)) {
        return;
    }
    help_command_help();
    help_command_new();
}

void help_command_help() {
    printf("%sCommand:%s help\n",STRC_CYAN,STRC_DEFAULT);
    printf("\tThis command prints help pages for all commands.\n\tOptitional flags: NONE\n");
}

void help_command_new() {

}