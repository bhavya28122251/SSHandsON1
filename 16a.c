/*
============================================================================
Name : 16a.c
Author : Bhavya Joshi
Description : Write a program to perform mandatory locking.
a. Implement write lock 
Date: 31th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void imp_lock(int file_desc,int t){
    
	struct flock l;

    	l.l_type=t;
    	l.l_start=0;
    	l.l_whence=SEEK_SET;
    	l.l_len=0;

    	if(fcntl(file_desc,F_SETLKW,&l)==-1){
        	perror("There is an error in locking the file");
        	exit(EXIT_FAILURE);
    	}

	else{
        	if(t==F_WRLCK){
            		printf("The File is locked by process %d.\n", getpid());
        	}

		else if(t==F_UNLCK){
            		printf("The File is unlocked by process %d.\n", getpid());
        	}
    
	}

}


int main(){

	char* file_name="file_16_a";
    	
	int file_desc=open(file_name,O_RDWR|O_CREAT,0600);
    	
	if(file_desc==-1){
        	perror("There is an error in opening the file\n");
        	exit(EXIT_FAILURE);
    	}

    	imp_lock(file_desc,F_WRLCK);

    	printf("Process with PID %d in inside the Critical Section\n",getpid());
    
	char *in = "This is Question 16\n";
    	
	if(write(file_desc,in,strlen(in))==-1){
        	perror("There is an error in writing in the file\n");
        	exit(EXIT_FAILURE);
    	}
    
	printf("The process with PID %d has written in the file\n",getpid());

    	printf("Process with PID %d is leaving the Critical Section.\n",getpid());
	
    	imp_lock(file_desc,F_UNLCK);
    
	close(file_desc);

    	return 0;

}


/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandsOn1$ cc 16a.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out 
The File is locked by process 12764.
Process with PID 12764 in inside the Critical Section
The process with PID 12764 has written in the file
Process with PID 12764 is leaving the Critical Section.
The File is unlocked by process 12764.

============================================================================
*/
