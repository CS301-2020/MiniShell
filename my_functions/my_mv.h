/*
 * Function:  mv_ 
 * --------------------
 * Moves the path to destination path as specified by the user
 *
 *  src: The path to the source directory that needs to be moved
 *  dest: The path to which the directory needs to be moved
 *  
 *  Checks if the given path exists, changes the current path to it
 */

#include <unistd.h>

int mv_(char * src,char * dest){
    
    int ret = rename(src, dest);
    if(ret == 0) {
        printf("File renamed successfully\n");
    } else {
        printf("Error: unable to rename the file\n");
    }
    return 0;
}