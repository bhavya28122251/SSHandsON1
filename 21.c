/*
============================================================================
Name : 21.c
Author : Bhavya Joshi
Description : Write a program, call fork and print the parent and child process id.
Date: 31th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

	pid_t process_id=fork();

	if(process_id==0)
		printf("Process ID of Child process is %d\n",getpid());

	else if(process_id>0)
		printf("Process ID of Parent process is %d\n",getpid());

	else{
		perror("Error in Fork");
		return 1;
	}

return 0;

}
 
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 21.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
Process ID of Parent process is 8365
Process ID of Child process is 8366

============================================================================
*/
