/*
 * Function:  mk_dir 
 * --------------------
 * Creates a new directory at the path specified
 *
 *  path: The path to the directory that needs to be set as the working directory
 *  
 */



#include <unistd.h>

void mk_dir(char * path){
    int check = mkdir(path,0777); 
    // check if directory is created or not 
    if (!check) 
        printf("Directory created %s\n",path); 
    else { 
        printf("Unable to create directory %s\n",path);  
    } 
}