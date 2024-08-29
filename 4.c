/*Name: Bhavya Joshi
Reg no.:MT2024032
4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

const char *file_name="file1";

int file_desc=open(file_name,O_RDWR);
if(file_desc==-1){
perror("There is an error in opening the file in read write mode\n");
return 1;
}

printf("File opened in read write mode\n");

close(file_desc);

file_desc=open(file_name,O_RDWR|O_CREAT|O_EXCL,0644);
if(file_desc==-1){
perror("There is an error in opening the file with O_EXCL flag\n");
return 1;
}

printf("File is opened with O_EXCL flag\n");

close(file_desc);

return 0;

} 


/*Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 4.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
File opened in read write mode
There is an error in opening the file with O_EXCL flag
: File exists
*/

