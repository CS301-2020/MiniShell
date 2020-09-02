/*
 * Function:  ch_mod 
 * --------------------
 * Changes the permission of the given path to the mode specified
 *
 *  path: The path to the directory whos permission needs to be changed
 *  mode: Mode that needs to be applied on the file.
 * 
 *  checks if permission can be changed, returns error if cannot be changed
 * 
 *      N   Description                     
 *      0   No permissions at all           
 *      1   Only execute                  
 *      2   Only write                       
 *      3   Write and execute                
 *      4   Only read                        
 *      5   Read and execute                
 *      6   Read and write                   
 *      7   Read, write, and execute      
 *      
 *      [MODE] = [User][Group][Other] for eg. 777 - gives all access to all   
 * 
 */


#include <unistd.h>
#include <string.h>

int ch_mod(char * path,char * mode){

    int i;
    i = strtol(mode, 0, 8);
    if (chmod (path,i) < 0)
    {
        printf("Error\n");
    }
    return 0;
}