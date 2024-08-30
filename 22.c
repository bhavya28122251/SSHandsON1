/*Name: Bhavya Joshi
Roll no.: MT2024032
Date: 30-8-24
22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<string.h>

int main() {

	int file_desc=open("file_22.txt",O_CREAT|O_WRONLY|O_TRUNC,0600);

	if(file_desc<0){
		perror("Error in opening the file");
		return 1;
	}

	pid_t child_pid=fork();

	if(child_pid>0){
		const char msg_parent[]="This message is written by Parent Process in the file\n";
		write(file_desc,msg_parent,sizeof(msg_parent));
	}

	else if(child_pid==0){
		const char msg_child[]="This message is written by Child Process in the file\n";
		write(file_desc,msg_child,sizeof(msg_child));
	}	

	else{
		perror("Error in Fork");
		return 1;
	}

	close(file_desc);
	
	return 0;

}

/*Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 22.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
bhavya@Bhavya:~/SSHandsOn1$ cat file_22.txt
This message is written by Parent Process in the file
This message is written by Child Process in the file

*/
