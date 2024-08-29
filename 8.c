/*Name:Bhavya Joshi
Reg no.:MT2024032
8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>

int main(){

FILE *f=fopen("file","r");

if(f==NULL){
perror("File is  Empty");
exit(0);
}

int a=fgetc(f);
char buf[1024];
int t=0;

while(a!=EOF){
buf[t]=a;
t++;

if(a=='\n' || t>=sizeof(buf)-1){
write(1,buf,t);
t=0;
}
a=fgetc(f);
}
if(t>0){
write(1,buf,t);

}

fclose(f);

return 0;

}

/*Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 8.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
Hello
THis is Question 8.
Bye.


*/
