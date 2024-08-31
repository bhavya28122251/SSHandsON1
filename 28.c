/*Name: 28.c
Author:Bhavya Joshi
Description:28. Write a program to get maximum and minimum real time priority.
Date: 29th Aug, 2024.
*/

#include<stdio.h>
#include<sched.h>

int main(){

int rr_max,rr_min,fifo_max,fifo_min;

rr_max=sched_get_priority_max(SCHED_RR);
printf("Maximum priority of SCHED_RR is: %d\n",rr_max);

rr_min=sched_get_priority_min(SCHED_RR);
printf("Minimum priority of SCHED_RR is: %d\n",rr_min);

fifo_max=sched_get_priority_max(SCHED_FIFO);
printf("Maximum priority of SCHED_FIFO is: %d\n",fifo_max);

rr_min=sched_get_priority_min(SCHED_FIFO);
printf("Minimum priority of SCHED_FIFO is: %d\n",rr_min);

return 0;

}

/*Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 28.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
Maximum priority of SCHED_RR is: 99
Minimum priority of SCHED_RR is: 1
Maximum priority of SCHED_FIFO is: 99
Minimum priority of SCHED_FIFO is: 1

*/

