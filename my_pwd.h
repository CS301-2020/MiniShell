/*
 * Function:  pwd_ 
 * --------------------
 * Prints the name of the current directory
 *
 *  path: The path to the directory that needs to be set as the working directory
 *  
 */

#include <unistd.h>
#define PATH_MAX 4096

void pwd_(){
    char wd[PATH_MAX];
    printf("Working Directory - %s\n",getcwd(wd,sizeof(wd)));
}