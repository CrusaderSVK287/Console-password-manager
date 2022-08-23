#include "headers/password.h"

char* get_password() {
    char* out = calloc(128,sizeof(char));
    out[127] = 0x00;
    fgets(out,127,stdin);
    fflush(stdin);
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
        case '_':   //fallthrough
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
    case 0:
    case PASSL_WEAK:
        printf("%sThis password is weak. Password must be at least 8 characters long and contain at least two of these:\n\
        - One uppercase and one lowercase letter\n\
        - a number\n\
        - a special character (!, @, #, $, %%, ^, &, *, _)\n%s",STRC_RED,STRC_DEFAULT);
        return false;
    default:
        fprintf(stderr,"Invalid password security level\n");
        break;
    }
    return false;
}

char* hash256(char* password) {
    if(password == NULL) {
        return NULL;
    }
    char* out = calloc(65,sizeof(char));
    out[64] = 0x00;
    uint8_t hash[32];
    calc_sha_256(hash,password,strlen(password));
    for (int i = 0; i < 32; i++){
        int a = i*2;
        int b = (i*2)+1;

        out[a] = ((hash[i] >> 4) & 0x0f) + '0';
        out[b] = (hash[i] & 0x0f) + '0';

        if(out[a] > '9') out[a] += 39;
        if(out[b] > '9') out[b] += 39;
    }
    return out;
}
