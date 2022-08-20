#include <stdio.h>

int main(int argc, char** argv) {
    if(argc < 2) {
        fprintf(stderr,"Please specify an action. To see a full list and explanation of all actions, please run the program with \"password help\"\n");
        return 1;
    }


    
    return 0;
}