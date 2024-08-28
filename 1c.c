/*Name: Bhavya Joshi
Reg no.: MT2024032
1. Create the following types of a files using (i) shell command (ii) system call
c. FIFO (mkfifo Library Function or mknod system call)*/

#include<stdio.h>
#include<sys/stat.h>

int main(){

if(mkfifo("fifo_1",0666)==-1){
perror("Error has occured in creating FIFO");
return 1;
}

printf("FIFO is created\n");

return 0;

}

/*Output:
1.Shell Command:
bhavya@Bhavya:~$ mkfifo fifo_2
bhavya@Bhavya:~$ ls -l fifo_2
prw-rw-r-- 1 bhavya bhavya 0 Aug 29 03:00 fifo_2

2.System Call:
bhavya@Bhavya:~$ gcc 1c.c
bhavya@Bhavya:~$ ./a.out
FIFO is created
bhavya@Bhavya:~$ ls -l fifo_1
prw-rw-r-- 1 bhavya bhavya 0 Aug 29 02:59 fifo_1

*/
