#include "../token_checker.h"

void fork_(int argc, char * argw[],char * input){
    //some code
    int id=fork();
    if(id==0)
    {
    //child does work here
    check_token(argc,argw,input);
    }
    else
    {
    //Parent does work here
    int status;
    if(!strcmp(argw[argc-1],"&")==0)waitpid(id,&status,0);
    }
}