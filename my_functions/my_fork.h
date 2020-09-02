
void fork_(int argc, char * argw[],char * input){
    //some code
    int id=fork();
    if(id==0)
    {
    //child does work here
    execvpe(input);
    }
    else
    {
    //Parent does work here
    int status;
    if(!strcmp(argw[argc-1],"&")==0)waitpid(id,&status,0);
    }
}