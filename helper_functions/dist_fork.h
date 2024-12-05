/*
 * Function:  fork_ 
 * --------------------
 * This functions forks the parent process into child and parent process. Using the child process,
 * all the various functions are implemented. So that the parent process remains the main shell.c
 * file.
 * Depending upon the & flag, the function decides if the parent process needs to wait for the 
 * completion of the child process or not.
 *
 *  argc: Number of inputs
 *  argw: Tokenised input arguments
 *  input: Input string
 *
 *  The distribution function based on the & flag decides if the output needs to be printed or not,
 *  and then calls the token checkker function.
 * 
 */


#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../helper_functions/token_checker.h"
#define pass (void)0

void fork_(int argc, char * argw[],char * input){
    //some code
    int id=fork();
    if(id==0)
    {           
        //child does work here
        if(!strcmp(argw[argc-1],"&")==0)pass;
        else{
            /* open /dev/null for writing */
            printf("%ld",getpid());
            int fd = open("/dev/null", O_WRONLY);
            
            dup2(fd, 1);    /* make stdout a copy of fd (> /dev/null) */
            dup2(fd, 2);    /* ...and same with stderr */
            close(fd);      /* close fd */
        }
        check_token(argc,argw,input);
        // exit(1);
    }
    else
    {
    //Parent does work here
    int status;
    if(!strcmp(argw[argc-1],"&")==0){waitpid(id,&status,0);}
    else printf("process id - [%d]",id);
    printf("%d",&status);
    }
}