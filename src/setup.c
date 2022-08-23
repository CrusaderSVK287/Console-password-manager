#include "headers/setup.h"
#include "headers/password.h"

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

    printf("Set you master password. This password will be used to access stored passwords that were flaged as protected during creation \
    .\nPassword must be between 8 to 127 characters long and it must contain two of these:\n-Uppercase and lowercase letter\n-Number\n-Special character (!, @, #, $, %%, ^, &, *, _)\n");
    char* password = NULL;
    do {
        if(password != NULL) {
            free(password);
        }
        printf("Set master password: ");
        password = get_password();
    } while (!is_password_valid(password));
    printf("%sMaster password has been set!\n%s"STRC_GREEN,STRC_DEFAULT);

    FILE* hash_file = fopen(MASTER_PASSWORD_HASH_FILE,"w");
    char* hash = hash256(password);
    fprintf(hash_file,"%s",hash);
    fclose(hash_file);

    free(hash);
}