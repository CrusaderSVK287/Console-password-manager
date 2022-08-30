#include "headers/clear.h"

void command_clear(struct options* opts, int argc, char** args) {
    if(!are_options_valid(false,false,true,false,opts)) {
        return;
    }

    printf("Warning, this action will delete all stored passwords NOT specified as arguments, to proced please enter the master password\n");
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
                strcmp(dir->d_name, "master_password_hash_code") == 0) {
                    continue;
                } 
            if(can_be_deleted(argc, args, dir->d_name)) {
                remove(dir->d_name);
            }
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