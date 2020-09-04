/*
 * Function:  fork_ 
 * --------------------
 * Normal fork function creates a child process for execvp to run
 *
 *  argc: Number of inputs
 *  argw: Tokenised input arguments
 *  input: Input string
 *
 *  passes the input to excvp
 */


// #include <fcntl.h>
#include <unistd.h>

void ffork_(int argc, char * argw[],char * input){
    //some code
    int id=fork();
    if(id==0)
    {           
        //child does work here
        execvp(argw[0],argw);
    }
    else
    {
    //Parent does work here
    int status;
    if(!strcmp(argw[argc-1],"&")==0)waitpid(id,&status,0);
    }
}