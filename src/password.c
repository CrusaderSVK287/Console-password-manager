#include "headers/password.h"

char* get_password() {
    char* out = calloc(128,sizeof(char));
    fgets(out,128,stdin);
    return out;
}

bool is_password_valid(char* password) {
    int len = strlen(password);
    return true;
}

char* hash256(char* password) {
    return password;
}