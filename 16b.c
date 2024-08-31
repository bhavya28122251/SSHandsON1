/*
============================================================================
Name : 16b.c
Author : Bhavya Joshi
Description : Write a program to perform mandatory locking.
b. Implement read lock 
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void imp_lock(int file_desc){
    
        struct flock l;

        l.l_type=F_RDLCK;
        l.l_start=0;
        l.l_whence=SEEK_SET;
        l.l_len=0;

        if(fcntl(file_desc,F_SETLKW,&l)==-1){
                perror("There is an error in locking the file");
                exit(EXIT_FAILURE);
        }

        else{
                        printf("Process with PID %d has acquird read lock\n", getpid());

         }
    
}

void imp_unlock(int file_desc){
    
        struct flock l;

        l.l_type=F_UNLCK;
        l.l_start=0;
        l.l_whence=SEEK_SET;
        l.l_len=0;

        fcntl(file_desc,F_SETLK,&l);
        
	printf("Process with PID %d has releadsed the read lock\n", getpid());


}



int main(){

       const  char* file_name="file_16_b";

        int file_desc=open(file_name,O_RDONLY);

        if(file_desc==-1){
                perror("There is an error in opening the file\n");
                exit(EXIT_FAILURE);
        }

        imp_lock(file_desc);

        printf("Process with PID %d is reading the file.\n",getpid());

	sleep(5);
   
	imp_unlock(file_desc); 	
   
        close(file_desc);

        return 0;

}


/*
============================================================================
Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 16b.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
Process with PID 14175 has acquird read lock
Process with PID 14175 is reading the file.
Process with PID 14175 has releadsed the read lock

============================================================================
*/
