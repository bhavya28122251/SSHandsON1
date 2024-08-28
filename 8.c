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
perror("File Empty");
exit(0);
}

int a=fgetc(f);
char buf[1024];
int t=0;
while(a!='\n'){
while(a!='\n'){
buf[t]=a;
t++;
a=fgetc(f);
}
buf[t++]='\n';
write(1,buf,t);
buf[0]='\0';
}



return 0;

}

/*Output:*/
