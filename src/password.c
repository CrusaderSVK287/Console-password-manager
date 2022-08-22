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
        return print_password_security_level(PASSL_WEAK);
    }


    return true;
}

char* hash256(char* password) {
    return password;
}

bool print_password_security_level(int level) {
    switch (level)
    {
    case PASSL_STRONG:
        printf("%sThis password is considered strong\n%s",STRC_GREEN,STRC_DEFAULT);
        return true;
    case PASSL_DECENT:
        printf("%sThis password is decent, are you sure you want to set it? (y/n)\n%s",STRC_YELLOW,STRC_DEFAULT);
        char choice;
        scanf("%c",&choice);
        fflush(stdin);
        return choice == 'y' || choice == 'Y';
    case PASSL_WEAK:
        printf("%sThis password is weak. Password must be at least 8 characters long and contain at least two of these:\n\
        - One uppercase and one lowercase letter\n\
        - a number\n\
        - a special character\n%s",STRC_RED,STRC_DEFAULT);
        return false;
    default:
        fprintf(stderr,"Invalid password security level\n");
        break;
    }
    return true;
}