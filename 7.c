/*Name:Bhavya Joshi
Reg no.:MT2024032
7. Write a program to copy file1 into file2 ($cp file1 file2).*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

int file1=open(argv[1],O_RDONLY);
if(file1<0){
perror("Error opening file1");
exit(0);
}

int file2=open(argv[2],O_WRONLY|O_EXCL|O_CREAT,0600);
if(file2<0){
perror("Error opening file2");
exit(0);
}

char arr[1024];
int read_input;
while((read_input=read(file1,arr,sizeof(arr)))>0){
write(file1,arr,read_input);
}

close(file1);
close(file2);

return 0;

}

/*Output:*/






