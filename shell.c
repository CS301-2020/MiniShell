/*
 * Function:  main() 
 * --------------------
 * This is the main function that takes in the accepts the input and passes to the tokenizer.
 * This function tells the user the working directory and waits for the user to give an input.
 *  
 *  Takes the input from user and passes it to the tokenizer function.
 */

#include <stdio.h>
#include <fcntl.h>
#include "helper_functions/tokenizer.h"
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