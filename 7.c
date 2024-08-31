/*Name:7.c
Author:Bhavya Joshi
Description:7. Write a program to copy file1 into file2 ($cp file1 file2).
Date:29th Aug,24
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>

int main(int in, char* arr[]){

int file_7_1=open(arr[1],O_RDONLY);

if(file_7_1<0){
perror("Error opening file1");
exit(0);
}

int file_7_2=open(arr[2],O_WRONLY|O_CREAT|O_EXCL,0600);

if(file_7_2<0){
perror("Error opening file2");
exit(0);
}

char a[1024];
int read_input;

while((read_input=read(file_7_1,a,sizeof(a)))>0){
write(file_7_2,a,read_input);
}

close(file_7_1);
close(file_7_2);

return 0;

}

/*Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 7.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out file_7_1 file_7_2
bhavya@Bhavya:~/SSHandsOn1$ cat file_7_2
Helllo World
This is Question 7.
Bye

*/






