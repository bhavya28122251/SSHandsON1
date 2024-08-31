/*Name:23.c
Author: Bhavya Joshi
Description:23. Write a program to create a Zombie state of the running program.
Date: 31st Aug, 2024.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

pid_t child_pid=fork();

if(child_pid>0){
printf("Parent process with PID: %d is running\n",getpid());
sleep(5);
}

else if(child_pid==0){
printf("Child process with PID: %d is running\n",getpid());
printf("Child process will now exit\n");
exit(0);
}

else{
printf("Error in creating Child process\n");
return 1;
}

printf("Zombie state is created as Parent process is now sleeping and child process has terminated\n");
sleep(7);

return 0;

}

/*Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 23.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
Parent process with PID: 5257 is running
Child process with PID: 5258 is running
Child process will now exit
Zombie state is created as Parent process is now sleeping and child process has terminated

*/
