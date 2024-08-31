/*Name:30.c
Author: Bhavya Joshi
Description:30. Write a program to run a script at a specific time using a Daemon process.
Date: 29th Aug, 2024.
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(){

if(!fork()){

setsid();
chdir("/");
umask(0);

while(2){

sleep(7);

printf("Pid of the child process is: %d\n",getpid());
printf("This is a Deamon Process\n");

}
}

else{
exit(0);
}

}

/*Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 30.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
bhavya@Bhavya:~/SSHandsOn1$ ./a.outPid of the child process is: 14757
This is a Deamon Process
Pid of the child process is: 14757
This is a Deamon Process
Pid of the child process is: 14757
This is a Deamon Process

*/
