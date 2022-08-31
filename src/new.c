#include "headers/new.h"

void command_new(struct options* opts) {
    if(!are_options_valid(true,false,true,true,opts)) {
        return;
    }

    if(opts->help) help_command_new();

    printf("Name of password (Max 128 characters long): ");
    char* name = get_input(128);
    if(name[0] == '-') {
        fprintf(stderr, "Name cannot start with '-'\n");
        free(name);
        return;
    }
    if(strstr(name,"_PROTECT") != NULL) {
        fprintf(stderr, "Name cannot contain \"_PROTECT\"\n");
        free(name);
        return;
    }

    char* file_name = calloc(128+24+8,sizeof(char));
    strncpy(file_name,".password_manager_data/",24);
    strcat(file_name, name);
    string_replace(file_name,' ','_');

    char* tmp = calloc(128+24+8,sizeof(char));  //used to check whether the file of a same name but protected exists
    strcpy(tmp,file_name);
    strcat(tmp,"_PROTECT");

    if (access(file_name, F_OK) == 0 || access(tmp,F_OK) == 0) {
        fprintf(stderr,"Password with the same name already exists!\n");
        return;
    }

    if(opts->protect) {
        strcat(file_name,"_PROTECT");
    }

    printf("Enter your password (max 128 characters long): ");
    char* plain_password = get_input(128);
    FILE* file = fopen(file_name,"wb");
    unsigned char* encrypted = encrypt(plain_password);
    fwrite(encrypted, sizeof(char), strlen(encrypted), file);
    fclose(file);

    free(tmp);
    free(file_name);
    free(name);
    free(encrypted);
}