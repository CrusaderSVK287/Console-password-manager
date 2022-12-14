#include "headers/help.h"

void command_help(struct options* opt) {
    if(!are_options_valid(false,false,false,false,opt)) {
        return;
    }
    help_command_help();
    help_command_new();
    help_command_get();
    help_command_list();
    help_command_delete();
    help_command_clear();
    help_command_reset();
    help_about();
}

void help_about() {
    printf("C Console Password manager. Original creator: Lukáš Belán.\n"
    "Version 1.0.0 - Initial release\n"
    "Feel free to make changes to this project. Repository for this project is located at "
    "%shttps://github.com/CrusaderSVK287/Console-password-manager%s\n", STRC_CYAN, STRC_DEFAULT);
    printf("Also feel free to submit any issue in case it arrises\n");
}

void help_command_help() {
    printf("%sCommand:%s help\n",STRC_CYAN,STRC_DEFAULT);
    printf("\tThis command prints help pages for all commands.\n\tThe 3 top most ones (including this one) are the most important.\n\t"
    "Optitional flags: NONE\n\n");
}

void help_command_new() {
    printf("%sCommand:%s new\n",STRC_CYAN,STRC_DEFAULT);
    printf("\tThis command goes through the process of storing new password. User is prompted to type the name of the password.\n\t"
    "This is the name by which the password will be stored, later can be recovered with command \"get password_name\".\n\t"
    "Note that all spaces will be replaced with '_'. Therefore, if you type \"test one\", it will become automatically test_one \n"
    "\tUser is than prompted to enter the password to be stored. Password is then encrypted and stored.\n\tOptitional flags: \n\t");
    printf("%s-l --list :%s Shows list of names of all currently stored passwords\n\t",STRC_YELLOW,STRC_DEFAULT);
    printf("%s-p --protect :%s Protects your password by requiring the master password in order to access it\n\t",STRC_YELLOW,STRC_DEFAULT);
    printf("%s-h --help :%s Shows the help page for this command\n\n",STRC_YELLOW,STRC_DEFAULT);
}

void help_command_get() {
    printf("%sCommand:%s get\n",STRC_CYAN,STRC_DEFAULT);
    printf("\tThis command gets your stored password, decrypts it and shows it in plain text. It is used when you want to access one of the\n\t"
    "stored passwords. Command will ask the user for the password name. If the password is protected, user needs to type in the master password.\n\t"
    "There is no going around this check.\n\tNote that you dont need to write spaces as underscores. You can type \"test one\" and it will be interpreted as test_one.\n\tOptitional flags:\n\t");
    printf("%s-l --list :%s Shows list of names of all currently stored passwords\n\t",STRC_YELLOW,STRC_DEFAULT);
    printf("%s-h --help :%s Shows the help page for this command\n\n",STRC_YELLOW,STRC_DEFAULT);
}

void help_command_list() {
    printf("%sCommand:%s list\n",STRC_CYAN,STRC_DEFAULT);
    printf("\tLists all stored passwords names.\n\tRegular passwords are shown in green.\n\tProtected passwords are shown in yellow\n");
    printf("\tOptitional flags:\n\t");
    printf("%s-h --help :%s Shows the help page for this command\n\n",STRC_YELLOW,STRC_DEFAULT);
}

void help_command_delete() {
    printf("%sCommand:%s delete\n",STRC_CYAN,STRC_DEFAULT);
    printf("\tDeletes a specified password from storage. Use like this: \"delete name_of_password\".\n\t"
    "If you are not sure how the password is called or you forgot, list all saved passwords with \"list\" command.\n\t"
    "The first argument given after the \"delete\" that does not start with a dash (-) will be used as a password name.\n\t"
    "To delete a password you will need to enter the master password. If the password is NOT protected you can force (see optitional flags) deletion without\n\t"
    "the need to type the master password.\n\tOptitional flags:\n\t");
    printf("%s-f --force :%s Forces deletion of the password without the need to type in the master password (ONLY UNPROTECTED PASSWORDS)\n\t",STRC_YELLOW,STRC_DEFAULT);
    printf("%s-h --help :%s Shows the help page for this command\n\n",STRC_YELLOW,STRC_DEFAULT);
}

void help_command_clear() {
    printf("%sCommand:%s clear\n",STRC_CYAN,STRC_DEFAULT);
    printf("\tDeletes ALL stored passwords, no mater whether protected or not. To prevent a deletion of a certain passoword, you need to\n\t"
    "specify the name of the password(s) in arguments. Use like this: \"clear password_to_keep keep_2 keep_3...\"\n\t"
    "Command asks you to for your master password so you can check for any errors.\n\tOptitional flags:\n\t");
    printf("%s-h --help :%s Shows the help page for this command\n\n",STRC_YELLOW,STRC_DEFAULT);
}

void help_command_reset() {
    printf("%sCommand:%s reset\n",STRC_CYAN,STRC_DEFAULT);
    printf("\tThis command is used to change the master password.\n\t"
    "When invoked, it requires the old master passoword. Next, all protected passwords will be deleted, without exception.\n\t"
    "User is than required to set a new master password.\n\tOptitional flags:\n\t");
    printf("%s-h --help :%s Shows the help page for this command\n\n",STRC_YELLOW,STRC_DEFAULT);
}
