/*
Name: Bhavya Joshi
Roll no.: MT2024032
Date: 30-8-24
25. Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

pid_t process_id1,process_id2,process_id3,target_process_id;

process_id1=fork();
if(process_id1==0){
printf("Child process 1 which has PID: %d is running.\n",getpid());
exit(0);
}

process_id2=fork();
if(process_id2==0){
printf("Child process 2 which has PID: %d is running.\n",getpid());
exit(0);
}

process_id3=fork();
if(process_id3==0){
printf("Child process 3 which has PID: %d is running.\n",getpid());
exit(0);
}

target_process_id=process_id1;
waitpid(target_process_id,NULL,0);
printf("Parent process has waited for Child process 1 which has PID: %d.\n",target_process_id);

wait(NULL);
wait(NULL);

return 0;

}

/*Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 25.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
Child process 1 which has PID: 4718 is running.
Child process 2 which has PID: 4719 is running.
Child process 3 which has PID: 4720 is running.
Parent process has waited for Child process 1 which has PID: 4718.

*/

