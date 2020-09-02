/*
 * Function:  my_ls 
 * --------------------
 * Opens the paths specified and then print out all the file/directory names present inide the
 * given directory
 *
 *  path: The path to the directory that needs to be set as the working directory *  
 *
 *  Opens the give directory and reads all the file names present in the directory 
 *  
 */

#include <dirent.h>
#include <sys/stat.h>
#define NULL ((void *)0)

void ls_(char * path){
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;
    char buf[512];
    
    mydir = opendir(path);
    
    while((myfile = readdir(mydir)) != NULL)
    {
        char *filename = myfile->d_name;
        if(filename[0] != '.')
            printf("%s  ", filename);
        else
            continue;
    }
    printf("\n");
    closedir(mydir);
}