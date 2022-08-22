#include <stdbool.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define DATA_DIR ".password_manager_data"
#define MASTER_PASSWORD_HASH_FILE ".password_manager_data/master_password_hash_code"

/**
 * @brief Function checks for the presence of the required files, namely the data folder and
 *        master password hash
 * 
 * @return true if all required files exist
 * @return false otherwise
 */
bool check_required_files();

/**
 * @brief Function goes through setup procedure.
 *        Creates data folder if doesn't exist and
 *        then prompts the user to create a master password
 * 
 */
void setup();
