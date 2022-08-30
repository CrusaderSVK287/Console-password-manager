#include <stdio.h>
#include "headers/parser.h"
#include "headers/setup.h"

int main(int argc, char** argv) {
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
