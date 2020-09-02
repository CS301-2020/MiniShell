#include <stdio.h>
#include "tokenizer.h"
#define PATH_MAX 4096

int main()
{
    while(1){
        char input[100];
        char wd[PATH_MAX];
        if(getcwd(wd, sizeof(wd))!= NULL) {
            printf("%s $ ",wd);
            gets(input);
            

            if(!strcmp("exit",input))
                return 0;
            tokenizer(input);
        } 
        else{
           perror("getcwd() error");
           return 1;
        }
    } 

    return 0;
}