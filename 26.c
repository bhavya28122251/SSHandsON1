/*
============================================================================
Name : 26.c
Author : Bhavya Joshi
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name) 
Date: 31th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(){

	char* exu_prog = "./file_26";  
    	char* arr[]={exu_prog,"Question_26",NULL}; 

	if(execvp(exu_prog,arr)==-1){
        	perror("There is an error in executing the program\n");
	}
	
	 return 0;

}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc -o file_26 file_26.c
bhavya@Bhavya:~/SSHandsOn1$ cc 26.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out 
This is Question_26

============================================================================
*/
