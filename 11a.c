/*
============================================================================
Name : 11a.c
Author : Bhavya Joshi
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
Date: 31th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

	int file_desc1,file_desc2;
	char a[]="Question_11";
	char b[]="Subqueuestiona";

	file_desc1=open("file_11_a",O_CREAT|O_RDWR|O_APPEND, 0666);
	file_desc2=dup(file_desc1);

	write(file_desc1,a,sizeof(a));
	write(file_desc2,b,sizeof(b));

	close(file_desc1);
	close(file_desc2);

	return 0;

}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 11a.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
bhavya@Bhavya:~/SSHandsOn1$ cat file_11_a
Question_11Subqueuestiona
============================================================================
*/
