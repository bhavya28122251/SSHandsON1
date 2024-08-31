/*
============================================================================
Name : file_17_db.c (Database for q 17)
Author : Bhavya Joshi
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 31th Aug, 2024.
============================================================================
*/

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

int main(){

	int file_desc;
	
	struct{
	int ti;
	}db;

	db.ti = 510;
	
	file_desc = open("db",O_CREAT|O_RDWR,0744);
	
	write(file_desc,&db,sizeof(db));
	
	close(file_desc);
	
	file_desc=open("db",O_RDONLY);
	
	read(file_desc,&db,sizeof(db));
	
	printf("Ticket number is %d\n",db.ti);
	
	close(file_desc);

return 0;
}

