/*
============================================================================
Name : 18a.c
Author : Bhavya Joshi
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 31th Aug, 2024.
============================================================================
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

#define TRAIN 3
#define TRAIN_SIZE sizeof(int) * 2

struct {
    int t;
    int tr;
} db[TRAIN]={
    {0, 1},
    {0, 2},
    {0, 3}  
};

int train_lock(int file_desc, int tr) {
    	
	struct flock l;

   	l.l_type = F_WRLCK;   
    	l.l_whence = SEEK_SET;
    	l.l_start = TRAIN_SIZE*(tr-1);
    	l.l_len = TRAIN_SIZE; 
    	l.l_pid = getpid();   
	
	printf("Attempting to lock the train\n");
    
    	fcntl(file_desc,F_SETLKW,&l);
	
	printf("Accquired lock on the train no. %d\n",tr);

    return 0;
}

void train_unlock(int file_desc, int tr) {
    
	struct flock l;
    
	l.l_type = F_UNLCK;   
    	l.l_whence = SEEK_SET;
    	l.l_start = TRAIN_SIZE*(tr-1);
    	l.l_len = TRAIN_SIZE;
    	l.l_pid = getpid();
	
	printf("Press Enter to unlock the train\n");
	getchar();	
	getchar();

    	fcntl(file_desc,F_SETLK,&l);
   	printf("Released the lock on the train no. %d.\n",tr);

}

void db_initialize(int file_desc){
    
	lseek(file_desc,0,SEEK_SET);
    	write(file_desc,&db,sizeof(db));

}

int main() {
    
	int file_desc;
    	int tr;
    
   	file_desc=open("db",O_CREAT|O_RDWR,0744);
   
    	if(lseek(file_desc,0,SEEK_END)==0){
        	db_initialize(file_desc);
    	}

   	printf("Enter the train number (1-%d) to lock\n",TRAIN);
    	scanf("%d",&tr);

   	train_lock(file_desc,tr);
    	lseek(file_desc,TRAIN_SIZE*(tr-1),SEEK_SET);
    	read(file_desc,&db[tr-1],sizeof(db[0]));
    	
	db[tr-1].t++;
    	
	lseek(file_desc,TRAIN_SIZE*(tr-1),SEEK_SET);
    	write(file_desc,&db[tr-1],sizeof(db[0]));
	
    	train_unlock(file_desc,tr);

	lseek(file_desc,TRAIN_SIZE*(tr-1),SEEK_SET);
    	read(file_desc,&db[tr-1],sizeof(db[0]));
    	
	printf("Train no: %d\n",db[tr-1].tr);
    	printf("Ticket no: %d\n", db[tr-1].t);

    	close(file_desc);

    	return 0;
}

/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandsOn1$ cc 18a.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
Enter the train number (1-3) to lock
2
Attempting to lock the train
Accquired lock on the train no. 2
Press Enter to unlock the train

Released the lock on the train no. 2.
Train no: 2
Ticket no: 1

============================================================================
*/

