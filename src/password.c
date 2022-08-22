#include "headers/password.h"
#include "headers/string_colors.h"

char* get_password() {
    char* out = calloc(128,sizeof(char));
    fgets(out,128,stdin);
    return out;
}

bool is_password_valid(char* password) {
    int len = strlen(password);

    if(len < 9) {
        
    }

    return true;
}

char* hash256(char* password) {
    return password;
}