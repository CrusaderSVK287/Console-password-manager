#include "headers/parser.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct options* parse_options(int argc ,char** argv) {
    if(argc < 2 || argv == NULL) {
        fprintf(stderr,"Error occured while parsing options, please check your input format");
        return NULL;
    }

    struct options* out = calloc(1,sizeof(struct options));

    out->force = false;
    out->help = false;
    out->list = false;
    out->protect = false;

    for (size_t i = 0; i < argc; i++){
        char* arg = argv[i];
        if( arg[0] != '-' ) {
            continue;
        }
        parse(&out->force,  arg,"-f","--force");
        parse(&out->help,   arg,"-h","--help");
        parse(&out->list,   arg,"-l","--list");
        parse(&out->protect,arg,"-p","--protect");
    }
    return out;
}

void parse(bool* opt, char* arg, char* cmp_short, char* cmp_long) {
    if(opt == NULL || arg == NULL || cmp_short == NULL || cmp_long == NULL) {
        return;
    }

    if( strcmp(arg,cmp_short) == 0 ||
        strcmp(arg,cmp_long) == 0) {
            *opt = true;
    }
}

void destroy_options(struct options* opt) {
    if(opt == NULL) {
        return;
    }
    free(opt);
}