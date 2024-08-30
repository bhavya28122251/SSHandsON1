/*
============================================================================
Name : 20.c
Author : Bhavya Joshi
Description : Find out the priority of your running program. Modify the priority with nice command. 
Date: 31th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){
 
	pid_t process_id=getpid();
 	int curr_priority=getpriority(PRIO_PROCESS,process_id);

 	if(curr_priority==-1){
 		perror("Error in getting priority of the process\n");
		return 1;
	}

	printf("Current priority of the process is %d\n",curr_priority);
	
	int new_priority=nice(3);

	if(new_priority==-1){
                perror("Error in getting new priority of the process\n");
                return 1;
        }

	printf("New priority of the process is %d\n",new_priority);

	return 0;

}



/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 20.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
Current priority of the process is 0
New priority of the process is 3

============================================================================
*/
