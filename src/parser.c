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
        if(parse(&out->force,  arg,"-f","--force")) continue;
        if(parse(&out->help,   arg,"-h","--help")) continue;
        if(parse(&out->list,   arg,"-l","--list")) continue;
        if(parse(&out->protect,arg,"-p","--protect")) continue;
        free(out);
        fprintf(stderr, "%sERROR: %s'%s' is not a valid option\n", STRC_RED, STRC_DEFAULT, argv[i]);
        return NULL;
    }
    return out;
}

bool parse(bool* opt, char* arg, char* cmp_short, char* cmp_long) {
    if(opt == NULL || arg == NULL || cmp_short == NULL || cmp_long == NULL) {
        return false;
    }

    if( strcmp(arg,cmp_short) == 0 ||
        strcmp(arg,cmp_long) == 0) {
            *opt = true;
        return true;
    }
    return false;
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
    if(strcmp(args[1], "new") == 0) return command_new(opt);                    // new
    if(strcmp(args[1], "help") == 0) return command_help(opt);                  // help
    if(strcmp(args[1], "list") == 0) return command_list(opt);                  // list
    if(strcmp(args[1], "delete") == 0) return command_delete(args, argc, opt);  // delete
    if(strcmp(args[1], "clear") == 0) return command_clear(args, argc, opt);    // clear
    if(strcmp(args[1], "reset") == 0) return command_reset(opt);                // reset
    //if(strcmp(args[1], "new") == 0) new();// get
    fprintf(stderr, "Command %s%s%s is not recognised, use command \"help\" to see all available commands\n",STRC_CYAN,args[1],STRC_DEFAULT);
}
