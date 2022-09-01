#include <stdio.h>
#include "headers/parser.h"
#include "headers/setup.h"

int is_key_valid();

int main(int argc, char** argv) {
    if(is_key_valid() == 1) {
        return 0;
    }
    if(!check_required_files()) {
        setup();
        return 0;
    }

    if(argc < 2) {
        fprintf(stderr,"Please specify an action. To see a full list and explanation of all actions, please run the command \"help\"\n");
        return 0;
    }

    struct options* options = parse_options(argc, argv);
    run_command(argc, argv, options);
    destroy_options(options);

    return 0;
}

int is_key_valid() {
    if(strcmp("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",KEY) == 0) {
        fprintf(stderr, "%sERROR: %sThis key is default. Please recompile the program with different key, see the readme.md file\n", STRC_RED, STRC_DEFAULT);
        return 1;
    }
    if(strlen(KEY) != KEY_LENGHT) {
        fprintf(stderr, "%sERROR: %sThis key does not match key lenght. Key must be exactly %d letters long\n", STRC_RED, STRC_DEFAULT, KEY_LENGHT);
        return 1;
    }
    for (size_t i = 0; i < KEY_LENGHT; i++) {
        if(KEY[i] < 'A' || KEY[i] > 'Z') {
            fprintf(stderr, "%sERROR: %sThis key is invalid. Key must only contain capital letters from A to Z\n", STRC_RED, STRC_DEFAULT);
            return 1;
        }
    }
    return 0;
}
