/*
============================================================================
Name : 13.c
Author : Bhavya Joshi
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 31th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<errno.h>
#include<sys/time.h>
#include<string.h>
#include<unistd.h>

int main(void){
	
    	struct timeval time_out;
    	fd_set fds;
   
	FD_ZERO(&fds);
    	FD_SET(STDIN_FILENO, &fds);
    	time_out.tv_sec = 10;
    	printf("Waiting for the input for 10 seconds using select\n");
    	
	int a=select(STDIN_FILENO+1, &fds, NULL, NULL, &time_out);
    
	if(a==-1)
        	printf("There is an error in select\n");
    
	else if(a==0)
        	printf("User has not enetered an input\n");  
    	
	else{
		if(FD_ISSET(STDIN_FILENO, &fds)){
        		printf("User has enetered an input\n");}
	}

	 return (0);

}	



/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
Waiting for the input for 10 seconds using select
Question 13
User has enetered an input

============================================================================
*/

