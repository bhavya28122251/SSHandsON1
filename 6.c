/*Name: 6.c
Author:Bhavya Joshi
Description:6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date:28th Aug,24

*/

#include<stdio.h>
#include<unistd.h>

int main(int in, char* b[]){
char arr[50];
int read_arr=read(0,arr,20);
printf("%d\n",read_arr);
fflush(stdout);
write(1,arr,read_arr);
return 0;
}

/*Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 6.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
Hi! This is Bhavya
19
Hi! This is Bhavya
*/
