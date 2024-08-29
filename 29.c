/*Name: Bhavya Joshi
Roll no.: MT2024032
29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sched.h>

int main(){

int  sch_policy;
struct sched_param parameter;

sch_policy-sched_getscheduler(0);
if(sch_policy==-1){
perror("Error in fetching the scheduling policy");
exit(EXIT_FAILURE);
}

switch (sch_policy){

case SCHED_RR:
printf("The current policy is: SCHED_RR\n");
break;

case SCHED_FIFO:
printf("The current policy is: SCHED_FIFO\n");
break;

case SCHED_OTHER:
printf("The current policy is: SCHED_OTHER\n");
break;

default:
printf("The current policy is is not known\n");
break;

}

parameter.sched_priority=1;
if(sched_setscheduler(0,SCHED_RR, &parameter)==-1){
perror("Error in changing policy to SCHED_RR\n");
exit(EXIT_FAILURE);
}

printf("Scheduling policy is now modified to SCHED_RR\n");

parameter.sched_priority=1;
if(sched_setscheduler(0,SCHED_FIFO, &parameter)==-1){
perror("Error in changing policy to SCHED_FIFO\n");
exit(EXIT_FAILURE);
}

printf("Scheduling policy is now modified to SCHED_FIFO\n");

exit(EXIT_SUCCESS);

}

/*Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 29.c
bhavya@Bhavya:~/SSHandsOn1$ sudo ./a.out
The current policy is: SCHED_OTHER
Scheduling policy is now modified to SCHED_RR
Scheduling policy is now modified to SCHED_FIFO

*/
