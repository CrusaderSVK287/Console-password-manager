#include "headers/list.h"

void command_list(struct options* opt) {
    if(!are_options_valid(false,false,true,false,opt)) {
        return;
    }
    if(opt->help) help_command_list();

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
            bool protected = !(strstr(dir->d_name,"_PROTECT") == NULL);
            int len = strlen(dir->d_name);
            char* tmp = calloc(len+1,sizeof(char)); 
            strcpy(tmp,dir->d_name);
            if(protected) {
                tmp[len-8] = 0x00;
            }

            printf("\t%s%s%s\n", protected? STRC_YELLOW:STRC_GREEN, tmp, STRC_DEFAULT);
        }
        closedir(d);
    }
}
