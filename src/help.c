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
    printf("%sCommand:%s new\n",STRC_CYAN,STRC_DEFAULT);
    printf("\tThis command goes through the process of storing new password. User is prompted to type the name of the password.\n\t"
    "This is the name by which the password will be stored, later can be recovered with command \"get password_name\".\n\tNote that this name cannot "
    "contain spaces, use _ instead.\n"
    "\tUser is than prompted to enter the password to be stored. Password is then encrypted and stored.\n\tOptitional flags: \n\t");
    printf("%s-l --list :%s Shows list of names of all currently stored passwords\n\t",STRC_YELLOW,STRC_DEFAULT);
    printf("%s-p --protect :%s Protects your password by requiring the master password in order to access it\n\t",STRC_YELLOW,STRC_DEFAULT);
    printf("%s-h --help :%s Shows the help page for this command\n",STRC_YELLOW,STRC_DEFAULT);
}