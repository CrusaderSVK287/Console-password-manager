#include "headers/parser.h"

struct options* parse_options(int argc ,char** argv) {
    if(argc < 2 || argv == NULL) {
        fprintf(stderr,"Not enough arguments, please check your input format\n");
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

struct options* destroy_options(struct options* opt) {
    if(opt == NULL) {
        return NULL;
    }
    free(opt);
    return NULL;
}

void run_command(int argc, char** args, struct options* opt) {
    if( args == NULL || opt == NULL) {
        return;
    }
    if(strcmp(args[1], "new") == 0) command_new(opt);  // new
    if(strcmp(args[1], "help") == 0) command_help(opt);// help
    if(strcmp(args[1], "list") == 0) command_list(opt);// list
    if(strcmp(args[1], "delete") == 0) command_delete(args, argc, opt);// delete
    //if(strcmp(args[1], "new") == 0) new();// clear
    //if(strcmp(args[1], "new") == 0) new();// edit
    //if(strcmp(args[1], "new") == 0) new();// reset
    //if(strcmp(args[1], "new") == 0) new();// about
    //if(strcmp(args[1], "new") == 0) new();// get
}
