#include "headers/list.h"

void command_list(struct options* opt) {
    if(!are_options_valid(false,false,true,false,opt)) {
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
            printf("\t%s%s%s\n", (strstr(dir->d_name,"PROTECT") == NULL)? STRC_GREEN:STRC_YELLOW, dir->d_name, STRC_DEFAULT);
        }
        closedir(d);
    }
}
