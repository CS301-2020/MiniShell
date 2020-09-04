/*
 * Function:  tokenizer 
 * --------------------
 * Takes the input and splits it into tokens to be understood by the token checker function
 *
 *  input: input entered by the user in the shell
 *  
 *  Parses the tokens to the function for further interpretation
 */

#define _GNU_SOURCE
#include <string.h>
#define NULL ((void *)0)
#include "../my_functions/my_fork.h"

void tokenizer(char input[]){
    int argc=0;
    char *argw[10];
    argw[0] = strtok(input," ");

    while(argw[argc]!=NULL){
        argw[++argc] = strtok(NULL," ");
    }
    
    fork_(argc,argw,input);
    printf("\n");
    
}