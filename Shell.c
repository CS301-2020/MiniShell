#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#define EOF (-1)
#define NULL ((void *)0)
#define O_RDONLY 00
#define STDOUT_FILENO 1
#define PATH_MAX 4096
#pragma GCC diagnostic warning "-Wall -Wformat=0"



void ls_(char * path){
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;
    char buf[512];
    
    mydir = opendir(path);
    
    while((myfile = readdir(mydir)) != NULL)
    {
        char *filename = myfile->d_name;
        if(filename[0] != '.')
            printf("%s  ", filename);
        else
            continue;
    }
    printf("\n");
    closedir(mydir);
}

void grep_(char *file, char * pat){
    char temp[200];
    FILE *fp;
    fp=fopen(file,"r");
    while(!feof(fp))
    {
        fgets(temp,1000,fp);
        if(strstr(temp,pat)!=NULL)
            printf("%s",temp);
    }
    fclose(fp);
}

int cat_(char path[]){
    int fd, i, ch; 
	
    fd = open(path,O_RDONLY);            /*open the file in READONLY mode*/
    
    if(fd < 0) { 
        perror("open"); 
        return 0;
    } 
    
    while(read(fd,&ch,1))                   /*Read one byte at a time*/
        write(STDOUT_FILENO,&ch,1);     /*Write the byte on Stdout*/
    
    close(fd);                              /*close the file discriptor*/
}

int mv_(char * path,char * dest){
    
    int ret = rename(path, dest);
    if(ret == 0) {
        printf("File renamed successfully\n");
    } else {
        printf("Error: unable to rename the file\n");
    }
    return 0;
}

int cp_(char * path,char * dest){
    
    int flag=-1;
    char c[1];
    FILE *fd1 = fopen(path,"r");
    FILE *fd2 = fopen(dest,"w");   //create and write to file
    while ((c[0] = (char)fgetc(fd1)) != EOF)
        fprintf(fd2, c);
    //close streams
    fclose(fd1);
    fclose(fd2);
    printf("%s FileCopied\n",path);
    return flag;
}

int cd_(char * path){
    int check = chdir(path); 
    if(check)
        printf("Path not found\n");
    else
        return 0;
}

void pwd_(){
    char wd[PATH_MAX];
    printf("Working Directory - %s\n",getcwd(wd,sizeof(wd)));
}

void mk_dir(char * path){
    int check = mkdir(path,0777); 
    // check if directory is created or not 
    if (!check) 
        printf("Directory created %s\n",path); 
    else { 
        printf("Unable to create directory %s\n",path);  
    } 
}

int ch_mod(char * path,char * mode){

    int i;
    i = strtol(mode, 0, 8);
    if (chmod (path,i) < 0)
    {
        printf("Error");
    }
    return 0;
}

//remove file
void remove_(char * path){
    if (remove(path) == 0) 
        printf("%s Deleted successfully\n",path); 
    else
        printf("Unable to delete the file %s\n",path); 
}


//remove folder
int remove_directory(const char *path) {
    DIR *d = opendir(path);
    size_t path_len = strlen(path);
    int r = -1;

    if (d) {
        struct dirent *p;

        r = 0;
        while (!r && (p=readdir(d))) {
            int r2 = -1;
            char *buf;
            size_t len;

            //Skipping on .. and .
            if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, ".."))
                continue;

            len = path_len + strlen(p->d_name) + 2; 
            buf = (char*)malloc(len);

            if (buf) {
                struct stat statbuf;

                snprintf(buf, len, "%s/%s", path, p->d_name);
                if (!stat(buf, &statbuf)) {
                    if (S_ISDIR(statbuf.st_mode))
                    r2 = remove_directory(buf);
                    else
                    r2 = unlink(buf);
                }
                free(buf);
            }
            r = r2;
        }
        closedir(d);
    }
    else if (remove(path) == 0) 
        printf("%s Deleted successfully\n",path); 
    else
        printf("Unable to delete the file %s\n",path);
    if (!r)
        r = rmdir(path);
        printf("%s Deleted successfully\n",path); 
    return r;
}

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
    
    

            
}

void token_maker(char input[]){
    // printf("Hello");
    
    char *argw[10];
    int argc = 0;
    argw[0] = strtok(input," ");
    while(argw[argc]!=NULL){
        argw[++argc] = strtok(NULL," ");
    }
    check_token(argc,argw,input);
}


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
            token_maker(input);
            // char * token = strtok(input," ");

            // check_token(token);
            
                
            // ls(path);
            // grep(path,"foo");
            // cat(path);
            // mv(path,"renamed.c");
            // cp(path,"renamed.txt");
            // cd(path);
            // pd();
            // mk_dir(path);
            // ch_mod(path,"400");
            // remove_(path);
        } 
        else{
           perror("getcwd() error");
           return 1;
        }
    } 

    return 0;
}