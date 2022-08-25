#include "headers/defines.h"

void string_replace(char* str, char old, char new) {
    int i = -1;
    while (str[++i] != '\0') {
        if(str[i] == old) {
            str[i] = new;
        }
    }
}