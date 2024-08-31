/*
============================================================================
Name : 17.c
Author : Bhavya Joshi
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file. 
Date: 31st Aug, 2024.
============================================================================
*/

#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(){
	
	struct{
		int ti;
	}db;

	struct flock l;
	
	int file_desc;
	
	file_desc = open("db",O_RDWR);
	
	read(file_desc,&db,sizeof(db));
	
	l.l_type=F_WRLCK;
	l.l_whence=SEEK_SET;
	l.l_start=0;
	l.l_len=0;
	l.l_pid=getpid();

	printf("Section before enterning the Critical Sesction\n");
	fcntl(file_desc,F_SETLKW,&l);
	printf("Current Ticket number is  %d\n",db.ti);
	db.ti++;
	lseek(file_desc,0L,SEEK_SET);
	
	printf("Inside CS\n");
	
	write(file_desc,&db,sizeof(db));
	printf("The new Ticket number is %d\n",db.ti);
	
	printf("Press Enter to leave the Critical Section");
	getchar();
	l.l_type=F_UNLCK;
	
	printf("Unlocked and leaving the Critical Section\n");
	fcntl(file_desc,F_SETLK,&l);

	printf("Task Completed");
	
	return 0;

}
/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandsOn1$ cc file_17_db.c 
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
Ticket number is 510
bhavya@Bhavya:~/SSHandsOn1$ cc 17.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
Section before enterning the Critical Sesction
Current Ticket number is  510
Inside CS
The new Ticket number is 511
Press Enter to leave the Critical Section
Unlocked and leaving the Critical Section
Task Completed
============================================================================
*/

