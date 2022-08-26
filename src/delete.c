#include "headers/delete.h"

void command_delete(char** args, int argc ,struct options* opts) {
    if(!are_options_valid(false,true,true,false,opts)) {
        return;
    }

    char* file_to_delete_from_args = NULL;
    for (int i = 2; i < argc; i++) {
        if(args[i][0] == '-') {
            continue;
        } else {
            file_to_delete_from_args = args[i];
            break;
        }
    }

    if(file_to_delete_from_args == NULL) {
        fprintf(stderr, "%sPlease specify the name of the password you wish to delete. Use \"delete name_of_password\"%s\n", STRC_RED,STRC_DEFAULT);
        return;
    }

    char* file_to_delete = calloc(strlen(file_to_delete_from_args)+strlen(DATA_DIR_SLASH)+strlen("_PROTECT")+1, sizeof(char));
    strcpy(file_to_delete, DATA_DIR_SLASH);
    strcat(file_to_delete, file_to_delete_from_args);

    if(access(file_to_delete,F_OK) != 0) {
        strcat(file_to_delete, "_PROTECT");
        if(access(file_to_delete,F_OK) != 0) {
            printf("%s\n",file_to_delete);
            fprintf(stderr,"%sPassword with the name \"%s\" does not exist, please check your spelling.%s\n", STRC_RED, file_to_delete_from_args, STRC_DEFAULT);
            free(file_to_delete);
            return;
        }
        printf("%sProtected! %s", STRC_YELLOW, STRC_DEFAULT);
        if(!check_password()) {
            free(file_to_delete);
            return;
        }
        goto bypas_password_check;  //skips what would otherwise be the second password check
    }

    if(opts->force == false && !check_password()) {
        free(file_to_delete);
        return;
    }
    bypas_password_check:   // label after the password check
    if(remove(file_to_delete) == 0) {
        printf("Password deleted successfully\n");
    } else {
        fprintf(stderr, "*** ERROR DELETING PASSWORD ***\n");
    }
    free(file_to_delete);
}