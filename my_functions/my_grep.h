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