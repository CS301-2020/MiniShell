
#include <stdio.h>

int cp_(char * path,char * dest){
    
    int flag=-1;
    char c[1];
    FILE *fd1 = fopen(path,"r");
    FILE *fd2 = fopen(dest,"w");   //create and write to file
    while ((c[0] = (char)fgetc(fd1)) != EOF)
        fprintf(fd2, c);
    //close streams
    fclose(fd1);
    fclose(fd2);
    printf("%s FileCopied\n",path);
    return flag;
}