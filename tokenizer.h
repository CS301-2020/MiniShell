// #include <string.h>
#define NULL ((void *)0)

void tokenizer(char input[]){
    char *argw[10];
    int argc = 0;
    argw[0] = strtok(input," ");
    while(argw[argc]!=NULL){
        argw[++argc] = strtok(NULL," ");
    }
    printf("input=%s",input);
    // check_token(argc,argw,input);
}