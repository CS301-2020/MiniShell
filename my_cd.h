/*
 * Function:  cd_ 
 * --------------------
 * Changes the working directory to the input specified by the user
 *
 *  path: The path to the directory that needs to be set as the working directory
 *  
 *  Checks if the given path exists, changes the current path to it
 */


#include <unistd.h>

int cd_(char * path){
    int check = chdir(path); 
    if(check)
        printf("Path not found\n");
    else
        return 0;
}