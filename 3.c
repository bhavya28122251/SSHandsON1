/*Name: 3.c
Author: Bhavya Joshi
Description:3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date:28th Aug,24
*/

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>

int main(){

int file_desc=creat("fd_1",S_IRUSR|S_IWUSR);

if(file_desc==-1){
perror("File is not created");
return 1;
}

printf("File Descriptor value: %d\n",file_desc);

close(file_desc);

return 0;

}

/*Output:
bhavya@Bhavya:~$ gcc 3.c
bhavya@Bhavya:~$ ./a.out 
File Descriptor value: 3

*/
