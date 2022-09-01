#include "headers/get.h"

void command_get(struct options* opts) {
    if(!are_options_valid(true,false,true,false, opts)) {
        return;
    }
    if(opts->help) help_command_get();
    if(opts->list) {
        struct options tmp = {
            .force = false,
            .list = false,
            .help = false,
            .protect = false,
        };
        command_list(&tmp);
    }

    bool protected = false;
    printf("Name of password: ");
    char* name = get_input(128);

    char* file_name = calloc(128+24+8,sizeof(char));
    strncpy(file_name, DATA_DIR_SLASH, 24);
    strcat(file_name, name);
    string_replace(file_name,' ','_');

    char* file_name_protected = calloc(128+24+8,sizeof(char));  //used to check whether the file of a same name but protected exists
    strcpy(file_name_protected,file_name);
    strcat(file_name_protected,"_PROTECT");

    if (access(file_name, F_OK) != 0) {
        if( access(file_name_protected,F_OK) != 0) {
            fprintf(stderr,"Password with this name does not exist!\n");
            return;
        }
        printf("%sThis password is protected%s\n", STRC_YELLOW, STRC_DEFAULT);
        protected = true;
    }

    if(protected && !check_password()) {
        return;
    }

    FILE* file;
    if(protected) {
        file = fopen(file_name_protected,"r");
    } else {
        file = fopen(file_name,"r");
    }

    fseek(file, 0L, SEEK_END);
    int size = ftell(file);
    rewind(file);

    unsigned char* encrypted = calloc(size+1,sizeof(char));
    fread(encrypted,sizeof(char),size,file);
    encrypted[size] = 0x00;
    char* decrypted = decrypt(encrypted);
    printf("Your password is: %s-->%s%s%s<--%s\n", STRC_CYAN, STRC_DEFAULT, decrypted, STRC_CYAN, STRC_DEFAULT);
}