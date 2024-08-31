/*
============================================================================
Name : 14.c
Author : Bhavya Joshi
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file. 
Date: 31th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <libgen.h>

int main(int inp, char *arr[]) {
	if (inp!= 2){
        	printf("User has not entered the file\n");
		return 1;
    	}

	char *file_name = arr[1];
    	struct stat b;

    	if(stat(file_name, &b)==-1){
	        perror("Error in stat");
        	return 1;
    	}

    	if(S_ISREG(b.st_mode)){
        	printf("Regular file\n");
    	} 

	else if(S_ISDIR(b.st_mode)){
        	printf("Directory\n");
    	}
	
	else if(S_ISCHR(b.st_mode)){
        	printf("Character special file\n");
    	}
	
	else if(S_ISBLK(b.st_mode)){
        	printf("Block special file\n");
    	}
	
	else if(S_ISFIFO(b.st_mode)){
        	printf("FIFO (named pipe)\n");
    	}

	else if (S_ISLNK(b.st_mode)){
        	printf("Symbolic link\n");
   	}

	else if(S_ISSOCK(b.st_mode)){
        	printf("Socket\n");
    	}
	
	else{
        	printf("File type is not known\n");
    	}

    return 0;
}

/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandsOn1$ ./a.out file_14
Regular file

============================================================================
*/
