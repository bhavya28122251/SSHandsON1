/*Name: Bhavya Joshi
Roll no.: MT2024032
19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.*/

#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>

unsigned long long rdtsc(){
unsigned long long dst;
__asm__ volatile("rdtsc":"=A"(dst));
}

int main(){

int k,freq;
unsigned long long int lower,upper;

lower=rdtsc();

for(k=0;k<=1000;k++){
getpid();
}

upper=rdtsc();

freq=(upper-lower)/2.095;

printf("Total time taken: %d nano sec\n",freq);

return 0;

}

/*Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 19.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
Total time taken: 71865 nano sec

*/
