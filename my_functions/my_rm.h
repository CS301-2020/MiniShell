/*
 * Function: remove_ ,remove_directory
 * --------------------
 * Removes file/folder based on the function call.
 *
 *  path: The path to the directory that needs to be set as the working directory
 *  
 *  a file is removed using the remove_ function, while when the -r flag is activated 
 *  the remove_directory function is called, the function recursively deletes the various files
 *  and other directories present in the path give untill the path is empty and then removes
 *  the path as well.
 */


#include <unistd.h>
#include <dirent.h>
#include <string.h>

//remove file
void remove_(char * path){
    if (remove(path) == 0) 
        printf("%s Deleted successfully\n",path); 
    else
        printf("Unable to delete the file %s\n",path); 
}


//remove folder
int remove_directory(const char *path) {
    DIR *d = opendir(path);
    size_t path_len = strlen(path);
    int r = -1;

    if (d) {
        struct dirent *p;

        r = 0;
        while (!r && (p=readdir(d))) {
            int r2 = -1;
            char *buf;
            size_t len;

            //Skipping on .. and .
            if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, ".."))
                continue;

            len = path_len + strlen(p->d_name) + 2; 
            buf = (char*)malloc(len);

            if (buf) {
                struct stat statbuf;

                snprintf(buf, len, "%s/%s", path, p->d_name);
                if (!stat(buf, &statbuf)) {
                    if (S_ISDIR(statbuf.st_mode))
                    r2 = remove_directory(buf);     //Recursively deletes subdirectories
                    else
                    r2 = unlink(buf);       
                }
                free(buf);
            }
            r = r2;
        }
        closedir(d);
    }
    else if (remove(path) == 0) 
        printf("%s Deleted successfully\n",path); 
    else
        printf("Unable to delete the file %s\n",path);
    if (!r)
        r = rmdir(path);
        printf("%s Deleted successfully\n",path); 
    return r;
}