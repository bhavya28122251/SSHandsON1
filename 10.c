/*Name:Bhavya Joshi
Reg no.:MT2024032
10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){

int file_desc=open("file_10",O_RDWR|O_CREAT,0644);

write(file_desc,"This is Question 10",19);

off_t offs=lseek(file_desc,19,SEEK_CUR);

if(offs==-1){
perror("Error in lseek");
}
else{
printf("THis is lseek and new offset is %ld\n",offs);
}

write(file_desc,"This is Bhavya",14);

close(file_desc);

return 0;

}

/*Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 10.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
THis is lseek and new offset is 38
bhavya@Bhavya:~/SSHandsOn1$ od -c file_10
0000000   T   h   i   s       i   s       Q   u   e   s   t   i   o   n
0000020       1   0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
0000040  \0  \0  \0  \0  \0  \0   T   h   i   s       i   s       B   h
0000060   a   v   y   a
0000064

*/

