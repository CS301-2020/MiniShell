/*
 * Function:  cat_ 
 * --------------------
 * Takes a file, and prints all the content present in on the shell
 *
 *  path: The path to the file that needs read  
 *
 *  Opens the file in the read only mode and then reads it line by line while printing eachline
 *  
 */


#include <unistd.h>
#define O_RDONLY 00
#define STDOUT_FILENO 1

int cat_(char path[]){
    int fd, i, ch; 
	
    fd = open(path,O_RDONLY);               /*open the file in READONLY mode*/
    
    if(fd < 0) { 
        perror("open"); 
        return 0;
    } 
    
    while(read(fd,&ch,1))                   /*Read one byte at a time*/
        write(STDOUT_FILENO,&ch,1);         /*Write the byte on Stdout*/
    
    close(fd);                              /*close the file discriptor*/
}