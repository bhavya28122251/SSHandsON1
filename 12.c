/*
============================================================================
Name : 12.c
Author : Bhavya Joshi
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 31th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

	char* file_name="file_12";
	int file_desc;
 	
	file_desc=open(file_name,O_CREAT|O_RDWR,0600);

	if(file_desc==-1){
		perror("Fail to open the file");
		return 1;
	}

	int t=fcntl(file_desc,F_GETFL);
	
	if(t==32770)
		printf("The file is opened in Read Write mode\n");

	else if(t==32769)
                printf("The file is opened in Write only mode\n");

	else if(t==32768)
                printf("The file is opened in Read only  mode\n");

	return 0;

}


/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 12.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
The file is opened in Read Write mode

============================================================================
*/
