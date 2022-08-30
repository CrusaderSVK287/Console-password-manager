#include "headers/setup.h"

bool check_required_files() {
    DIR* data_dir = opendir(DATA_DIR);
    if (!data_dir) {
        return false;
    }
    closedir(data_dir);

    FILE* pass_hash_file = fopen(MASTER_PASSWORD_HASH_FILE,"r");
    if( !pass_hash_file ) {
        return false;
    }

    fclose(pass_hash_file);
    return true;
}

void setup() {
    #ifdef _WIN32
    mkdir(DATA_DIR);
    #else
    mkdir(DATA_DIR,0777);
    #endif

    DIR *d;
    struct dirent *dir;
    d = opendir(DATA_DIR);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if( strcmp(dir->d_name, ".") == 0 ||
                strcmp(dir->d_name, "..") == 0 ||
                strstr(dir->d_name, "_PROTECT") == NULL) {
                    continue;
                }
 
            char* file_to_remove = calloc(strlen(dir->d_name) + strlen(DATA_DIR_SLASH), sizeof(char));
            strcpy(file_to_remove,DATA_DIR_SLASH);
            strcat(file_to_remove,dir->d_name);
            remove(file_to_remove);
            free(file_to_remove);
        }
        closedir(d);
    }

    printf("Set you master password. This password will be used to access stored passwords that were flaged as protected during creation \
    .\nPassword must be between 8 to 127 characters long and it must contain two of these:\n-Uppercase and lowercase letter\n-Number\n-Special character (!, @, #, $, %%, ^, &, *, _)\n");
    char* password = NULL;
    do {
        if(password != NULL) {
            free(password);
        }
        printf("Set master password: ");
        password = get_input(128);
    } while (!is_password_valid(password));

    FILE* hash_file = fopen(MASTER_PASSWORD_HASH_FILE,"w");
    if(!hash_file) {
        return;
    }
    char* hash = hash256(password);
    fprintf(hash_file,"%s",hash);
    fclose(hash_file);
    printf("%sMaster password has been set!\n%s",STRC_GREEN,STRC_DEFAULT);
    free(hash);
}