#include "headers/new.h"

void command_new(struct options* opts) {
    if(!are_options_valid(true,false,true,true,opts)) {
        return;
    }
    printf("Name of password (Max 128 characters long): ");
    char* name = get_input(128);
    char* file_name = calloc(128+24,sizeof(char));
    strncpy(file_name,".password_manager_data/",24);
    strcat(file_name, name);

    string_replace(file_name,' ','_');

    if (access(file_name, F_OK) == 0) {
        fprintf(stderr,"Password with the same name already exists!\n");
        return;
    }

    printf("Enter your password (max 128 characters long): ");
    //char* plain_password = get_input(128);

    FILE* file = fopen(file_name,"w");
    //char* encrypted = encrypt(plain_password);
    //fprintf(file,encrypted);
    fclose(file);
}