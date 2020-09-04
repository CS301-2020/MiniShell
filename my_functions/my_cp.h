/*
 * Function:  cp_ 
 * --------------------
 * This function takes one src and one destination, and copies the contents of source to destination
 *
 *  src: Path to the source file
 *  dest: Path to the destination file 
 *
 *  creates a new file and writes the content of the source file into the destination file
 */

#include <stdio.h>

int cp_(char * src,char * dest){
    
    int flag=-1;
    char c[1];
    FILE *fd1 = fopen(src,"r");
    FILE *fd2 = fopen(dest,"w");   //create and write to file
    while ((c[0] = (char)fgetc(fd1)) != EOF)
        fprintf(fd2, c);
    //close streams
    fclose(fd1);
    fclose(fd2);
    printf("%s FileCopied\n",src);
    return flag;
}