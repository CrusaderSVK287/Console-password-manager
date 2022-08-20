#include <stdio.h>
#include "headers/parser.h"

int main(int argc, char** argv) {
    if(argc < 2) {
        fprintf(stderr,"Please specify an action. To see a full list and explanation of all actions, please run the program with \"password help\"\n");
        return 1;
    }

    struct options* options = parse_options(argc, argv);

    destroy_options(options);
    return 0;
}