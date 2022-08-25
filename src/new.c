#include "headers/new.h"

void command_new(struct options* opts) {
    if(!are_options_valid(true,false,true,true,opts)) {
        return;
    }
    printf("Name of password (Max 128 characters long): ");
    char* name = get_input(128);
    char* folder = calloc(128+24,sizeof(char));
    strncpy(folder,".password_manager_data/",24);
    strcat(folder, name);
    if (access(".", F_OK) == 0) {
        fprintf(stderr,"This name already exists!\n");
        return;
    }
    printf("go ahead\n");
}