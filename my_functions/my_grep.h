/*
 * Function:  grep_ 
 * --------------------
 * This function mimcs the grep fucntion, it searches a string from the file
 *
 *  file: Path to the file
 *  pat: Pattern to be found.
 *
 *  Reads line from the file and prints the line to standard output if the line contains the patten.
 */

#include <stdio.h>

void grep_(char *file, char * pat){
    char temp[200];
    FILE *fp;
    fp=fopen(file,"r");
    while(!feof(fp))
    {
        fgets(temp,1000,fp);
        if(strstr(temp,pat)!=NULL)
            printf("%s",temp);
    }
    fclose(fp);
}