#include "my_cd.h"
#include "my_pwd.h"

void check_token(int argc, char * argw[],char * input){
    //Change Directory
    
    if(!strcmp("cd",argw[0]))
    {   
        printf("%d",argc);
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
/*
    //Cat Function (Multiple arg left)
    else if(!strcmp("cat",argw[0]))
    {   
        for(int i = 1; i<argc; i++){
            printf("%s :-\n",argw[i]);
            cat_(argw[i]);
            printf("\n");
        }      
    }

    //ls is incomplete
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
    
    //move directory (multiple input handling left and directory handling)
    else if(!strcmp("mv",argw[0]))
    {   
        // printf("ITS left");
        if(argc>=3){
            int file =strstr(argw[argc-1],".")!=NULL;      
            for(int i=1;i<argc-1;i++){
                if(!file){
                    char folder[PATH_MAX];
                    memcpy(folder,argw[argc-1],PATH_MAX);
                    strcat(folder,"/");
                    strcat(folder,argw[i]);
                    printf("%s",folder);
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


    else if(!strcmp("chmod",argw[0]))
    {
        if(argc == 3){
            ch_mod(argw[2],argw[1]);
        }     
        else
            printf("Supported Usage- \nchmod [mode] [path]");
        
        
    }
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
    else if(!strcmp("grep",argw[0]))
    {
       if(argc >= 3){
           for(int i = 2;i<argc;i++){
               printf("%s:\n",argw[i]);
               grep_(argw[i],argw[1]);
           }
       }
    }
    
    else
    {
        fork_(argc,argw,input);
        printf("\n");
    }     
*/  
}
