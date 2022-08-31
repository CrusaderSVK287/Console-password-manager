#include "headers/defines.h"

void string_replace(char* str, char old, char new) {
    int i = -1;
    while (str[++i] != '\0') {
        if(str[i] == old) {
            str[i] = new;
        }
    }
}

void string_reverse(char* str) {
    int len = strlen(str);
    for (int i = 0, j = len-1; i < j; i++, j--) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}