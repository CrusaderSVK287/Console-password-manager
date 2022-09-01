# Console password manager (Linux)

Simple password manager program used for securely storing encrypted passwords.
Passwords can be protected. Protected passwords require master password to be typed in in order to access them.
This master password is also used as a failsafe in destructive operations like deleting to prevent accidents

## Commands

The base of the program lies on two commands:
* new
* get

Command new creates a new password, user sets it's name and the password itself. Program then encrypts the password using the unique key that the user sets themselves before compilation.
Command get decrypts a stored password and shows it in plain text.
See the Commands section lower for more detail about theese commands as well as rest of them.

## Usage
When you start the program for the first time, a (hidden) data directory is created, you'll then need to set up a master password, format of the password is told by the program.
The hash code of the master password is stored in the hidden data directory. This password is required to access the protected passwords and to prevent accidental deletion etc.
NOTE: sha-256 algorhitm was taken from [this repository](https://github.com/amosnier/sha-2). Original licence for the code is included in the lib folder of this repository

To use a command, run the program like this `./Password_manager command_name "command argument" --command-option`
Almost every command has it's own options, to see these options, eighter run `./Password_manager help` for an explanation of all commands or use the `-h` or `--help` option for the command you want a help with like this `./Password_manager command_name -h`

# How to compile
to install/compile this program, follow theese steps.
### pre-requisites
* gcc
* make
### instalation
1. Clone the repository
2. Open defines.h file. Location is src/headers/defines.h
3. Change the 
```c
#define KEY "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
```
macro to your custom key. This key can only contain capital letters from A-Z and be long 32 characters. If you want to change the lenght of the key, also change the KEY_LENGTH macro

4. Compile using `make` or `make release` if the former does not work for whatever reason.

### One small tip / improvement (optitional)
in the file for cypher (src/cypher.c), a offset table is located
```c
#include "headers/cypher.h"

const int OFFSET_TABLE[128] = 
{ 1,  16, 9,  4,  8,  4,  7,  18, 1,  13, 13, 3,  8,  6,  4,  16, 1,  10, 7,  16,
  11, 14, 10, 4,  19, 14, 7,  11, 15, 2,  4,  9,  20, 5,  4,  6,  8,  16, 12, 19,
  2,  10, 18, 11, 12, 18, 10, 14, 12, 15, 7,  19, 9,  9,  18, 15, 10, 9,  5,  11,
  14, 3,  16, 14, 10, 10, 18, 2,  10, 10, 7,  11, 13, 18, 15, 6,  4,  17, 8,  18,
  8,  12, 9,  4,  16, 11, 17, 7,  10, 10, 16, 16, 12, 4,  4,  1,  16, 15, 12, 11,
  19, 20, 17, 16, 10, 1,  14, 3,  4,  18, 1,  9,  10, 14, 18, 13, 4,  3,  16, 14,
  14, 4,  8,  11, 16, 15, 11, 2};
```

If you want to further randomize the cypher, adding an extra layer of security, you can change some of these values if you want. Try to keep them in range 1 - 20 since this is the default range, no bad behaviour should occur
You are ofcourse allowed to modify the cypher algorhitm to your liking, add or remove certain parts.

# Commands
This is a direct copy of a command 'help'.

Command: `help`

        This command prints help pages for all commands.
        The 3 top most ones (including this one) are the most important.
        Optitional flags: NONE


Command: `new`

        This command goes through the process of storing new password. User is prompted to type the name of the password.
        This is the name by which the password will be stored, later can be recovered with command "get password_name".
        Note that all spaces will be replaced with '_'. Therefore, if you type "test one", it will become automatically test_one
        User is than prompted to enter the password to be stored. Password is then encrypted and stored.
        Optitional flags:
        -l --list : Shows list of names of all currently stored passwords
        -p --protect : Protects your password by requiring the master password in order to access it
        -h --help : Shows the help page for this command


Command: `get`

        This command gets your stored password, decrypts it and shows it in plain text. It is used when you want to access one of the
        stored passwords. Command will ask the user for the password name. If the password is protected, user needs to type in the master password.
        There is no going around this check.
        Note that you dont need to write spaces as underscores. You can type "test one" and it will be interpreted as test_one.
        Optitional flags:
        -l --list : Shows list of names of all currently stored passwords
        -h --help : Shows the help page for this command


Command: `list`

        Lists all stored passwords names.
        Regular passwords are shown in green.
        Protected passwords are shown in yellow
        Optitional flags:
        -h --help : Shows the help page for this command


Command: `delete`

        Deletes a specified password from storage. Use like this: "delete name_of_password".
        If you are not sure how the password is called or you forgot, list all saved passwords with "list" command.
        The first argument given after the "delete" that does not start with a dash (-) will be used as a password name.
        To delete a password you will need to enter the master password. If the password is NOT protected you can force (see optitional flags) deletion without 
        the need to type the master password.
        Optitional flags:
        -f --force : Forces deletion of the password without the need to type in the master password (ONLY UNPROTECTED PASSWORDS)
        -h --help : Shows the help page for this command


Command: `clear`

        Deletes ALL stored passwords, no mater whether protected or not. To prevent a deletion of a certain passoword, you need to
        specify the name of the password(s) in arguments. Use like this: "clear password_to_keep keep_2 keep_3..."
        Command asks you to for your master password so you can check for any errors.
        Optitional flags:
        -h --help : Shows the help page for this command


Command: `reset`

        This command is used to change the master password.
        When invoked, it requires the old master passoword. Next, all protected passwords will be deleted, without exception.
        User is than required to set a new master password.
        Optitional flags:
        -h --help : Shows the help page for this command
        
