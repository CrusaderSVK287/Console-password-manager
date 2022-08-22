#include "headers/password.h"
#include "headers/string_colors.h"

char* get_password() {
    char* out = calloc(128,sizeof(char));
    fgets(out,128,stdin);
    return out;
}

bool is_password_valid(char* password) {
    int len = strlen(password);
    bool has_uppercase = false;
    bool has_lowercase = false;
    bool has_number = false;
    bool has_special_char = false;

    //Password too short is considered weak by default
    if(len < 9) {
        return print_password_security_level(PASSL_WEAK);
    }

    for (size_t i=0; i<len; i++) {
        switch (password[i])
        {
        case 'a'...'z': has_lowercase = true;
            break;
        case 'A'...'Z': has_uppercase = true;
            break;
        case '0'...'9': has_number = true;
            break;
        case '!':   //fallthrough
        case '@':   //fallthrough
        case '^':   //fallthrough
        case '*':   //fallthrough
        case '#'...'&' : has_special_char = true;   // #...& contains # $ % &
            break;
        case '\n': break;   //to not evaluate as invalid char
        default:
            fprintf(stderr,"%sWarning: '%c' is not a valid character, please choose another password%s\n",STRC_YELLOW,password[i],STRC_DEFAULT);
            return false;
            break;
        }
    }

    int security_level = 0;
    if(has_lowercase && has_uppercase) security_level++;
    if(has_number) security_level++;
    if(has_special_char) security_level++;

    return print_password_security_level(security_level);
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
        return (choice == 'y' || choice == 'Y');
        printf("WHY THE FUCK???");
    case 0:
    case PASSL_WEAK:
        printf("%sThis password is weak. Password must be at least 8 characters long and contain at least two of these:\n\
        - One uppercase and one lowercase letter\n\
        - a number\n\
        - a special character (!, @, #, $, %%, ^, &, *)\n%s",STRC_RED,STRC_DEFAULT);
        return false;
    default:
        fprintf(stderr,"Invalid password security level\n");
        break;
    }
    return false;
}