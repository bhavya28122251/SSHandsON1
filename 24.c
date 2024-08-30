/*
Name: Bhavya Joshi
Roll no.: MT2024032
Date: 30-8-24
24. Write a program to create an orphan process.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

pid_t process_id=fork();

if(process_id<0){
perror("Error in creating a new process");
exit(1);
}

else if(process_id>0){
printf("PID of the parent process is %d\n", getpid());
printf("Parent process is exiting\n");
exit(0);
}

else{
sleep(3); 
printf("Orphan process with PID id %d\n",getpid());
printf("The new Parent PID is %d\n", getppid());
}

return 0;

}

/*Output:
bhavya@Bhavya:~$ gcc 24.c
bhavya@Bhavya:~$ ./a.out
PID of the parent process is 4359
Parent process is exiting
bhavya@Bhavya:~$ Orphan process with PID id 4360
The new Parent PID is 1596
*/
