#include "headers/clear.h"

void command_clear(char** args, int argc, struct options* opts) {
    if(!are_options_valid(false,false,true,false,opts)) {
        return;
    }
    if(opts->help) help_command_clear();

    printf("Warning, this action will delete all stored passwords NOT specified as arguments, to proceed please enter the master password\n");
    if(!check_password()) {
        return;
    }

    DIR *d;
    struct dirent *dir;
    d = opendir(DATA_DIR);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if( strcmp(dir->d_name, ".") == 0 ||
                strcmp(dir->d_name, "..") == 0 ||
                strcmp(dir->d_name, MASTER_PASSWORD_FILE_NAME) == 0) {
                    continue;
                }
 
            char* file_to_remove = calloc(strlen(dir->d_name) + strlen(DATA_DIR_SLASH), sizeof(char));
            strcpy(file_to_remove,DATA_DIR_SLASH);
            strcat(file_to_remove,dir->d_name);

            if(can_be_deleted(argc, args, dir->d_name)) {
                remove(file_to_remove);
            }
            free(file_to_remove);
        }
        closedir(d);
    }
}

bool can_be_deleted(int argc, char** args, char* file) {
    bool protected = !(strstr(file,"_PROTECT") == NULL);
    if(protected) {
        file[strlen(file)-8] = 0x00;
    }
    for(int i = 2; i < argc; i++) {
        if(strcmp(file,args[i]) == 0) {
            return false;
        }
    }
    return true;
}