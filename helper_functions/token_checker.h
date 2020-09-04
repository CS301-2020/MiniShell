/*
 * Function:  check_token 
 * --------------------
 * This function is the brain of the shell, This functions interprets the tokenized input and then calls 
 * the corresponding function as per the token that user passes in
 *
 *  argc: Number of inputs
 *  argw: Tokenised input arguments
 *  input: Input string
 *
 *  This function checks the first token and checks if there is a predifined user function available for that
 *  it calls the function if present else it passes the function to excvp
 */

#include "../my_functions/my_cd.h"
#include "../my_functions/my_pwd.h"
#include "../my_functions/my_cat.h"
#include "../my_functions/my_ls.h"
#include "../my_functions/my_mkdir.h"
#include "../my_functions/my_rm.h"
#include "../my_functions/my_mv.h"
#include "../my_functions/my_chmod.h"
#include "../my_functions/my_cp.h"
#include "../my_functions/my_grep.h"
#include "../my_functions/fork.h"
#define pass (void)0
void check_token(int argc, char * argw[],char * input){
    
    //Change Directory
    if(!strcmp("cd",argw[0]))
    {   
        if(argc == 2){
            char * path = argw[1];
            cd_(path);
        }
        else
            printf("Enter correct command\n");
    }

    //Current Directory
    else if(!strcmp("pwd",argw[0]))
    {
        if(argc == 1){
            pwd_();
        }
        else
            printf("Enter correct command\n");        
    }

    //Cat Function 
    else if(!strcmp("cat",argw[0]))
    {   
        for(int i = 1; i<argc; i++){
            printf("%s :-\n",argw[i]);
            cat_(argw[i]);
            printf("\n");
        }      
    }

    //ls Function
    else if(!strcmp("ls",argw[0]))
    {
        if(argc == 1){
            char wd[PATH_MAX];
            char * path;
            path = getcwd(wd,sizeof(wd));
            ls_(path);
        }
        else if(argc == 2){
            ls_(argw[1]);
        }
        else
            for(int i = 1; i<argc; i++){
                printf("%s :-\n",argw[i]);
                ls_(argw[i]);
                printf("\n");
            }      
    }

    //make directory
    else if(!strcmp("mkdir",argw[0]))
    {
        for(int i = 1; i<argc; i++){
            mk_dir(argw[i]);
        }          
    }

    //remove directory
    else if(!strcmp("rm",argw[0]))
    {   
        if(!strcmp("-r",argw[1]))
            for(int i = 2; i<argc; i++)
                remove_directory(argw[i]);
               
        else
        for(int i = 1; i<argc; i++)
                remove_(argw[i]);        
    }
  
    //move directory
    else if(!strcmp("mv",argw[0]))
    {   
        if(argc==3){
            int src =strstr(argw[argc-1],".")!=NULL;
            int dest =strstr(argw[argc-2],".")!=NULL;
            if(!src && dest){
                char folder[PATH_MAX];
                memcpy(folder,argw[argc-1],PATH_MAX);
                strcat(folder,"/");
                strcat(folder,argw[1]);
                mv_(argw[1],folder);
            }
            else    
                mv_(argw[argc-2],argw[argc-1]);
        }
        else if(argc>3){
            int file =strstr(argw[argc-1],".")!=NULL;      
            for(int i=1;i<argc-1;i++){
                if(!file){
                    char folder[PATH_MAX];
                    memcpy(folder,argw[argc-1],PATH_MAX);
                    strcat(folder,"/");
                    strcat(folder,argw[i]);
                    mv_(argw[i],folder);
                }
                else
                {
                    mv_(argw[i],argw[argc-1]);
                }  
            }
        }
        else
            printf("Enter Command Correctly");     
    }

    //Chmod Function
    else if(!strcmp("chmod",argw[0]))
    {
        if(argc == 3){
            ch_mod(argw[2],argw[1]);
        }     
        else
            printf("Supported Usage- \nchmod [mode] [path]");
    }

    //Copy function
    else if(!strcmp("cp",argw[0]))
    {
        if(argc>=3){
            int file =strstr(argw[argc-1],".")!=NULL;      
            for(int i=1;i<argc-1;i++){
                if(!file){
                    char folder[PATH_MAX];
                    memcpy(folder,argw[argc-1],PATH_MAX);
                    strcat(folder,"/");
                    strcat(folder,argw[i]);
                    cp_(argw[i],folder);
                }
                else
                {
                    cp_(argw[i],argw[argc-1]);
                }
            }
        }
        else
        {
            printf("Enter Command Correctly");  
        }
    }

    //grep function
    else if(!strcmp("grep",argw[0]))
    {
       if(argc >= 3){
           for(int i = 2;i<argc;i++){
               printf("%s:\n",argw[i]);
               grep_(argw[i],argw[1]);
           }
       }
    }
    
    //If no function matches excvp it
    else
    {
        ffork_(argc,argw,input);  
    }     
}
