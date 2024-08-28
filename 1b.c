/*Name:Bhavya Joshi
Roll no.: MT2024032
1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main(){
char *file_path="file_hL.txt";
char *hard_link="h_link";

if(link(file_path,hard_link)==-1){
printf("Hard Link is not created\n");
}

else{
printf("Hard Link is created\n");
}
return 0;
}

/*Output:
1.shell command:
bhavya@Bhavya:~/SSHandsOn1$ ln  file_hL_1.txt h_link_1
bhavya@Bhavya:~/SSHandsOn1$ ls -l
total 24
-rw-rw-r-- 1 bhavya bhavya  1983 Aug 28 22:56 1b.c
-rw-rw-r-- 1 bhavya bhavya  1272 Aug 28 22:51 1.c
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 21:59 abc.txt
-rwxrwxr-x 1 bhavya bhavya 15992 Aug 28 22:54 a.out
-rw-rw-r-- 2 bhavya bhavya     0 Aug 28 22:56 file_hL_1.txt
-rw-rw-r-- 2 bhavya bhavya     0 Aug 28 22:54 file_hL.txt
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 22:46 file_sL_1.txt
lrwxrwxrwx 1 bhavya bhavya     6 Aug 28 22:27 file_sL.txt -> s_link
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 22:27 file_s.txt
-rw-rw-r-- 2 bhavya bhavya     0 Aug 28 22:54 h_link
-rw-rw-r-- 2 bhavya bhavya     0 Aug 28 22:56 h_link_1
lrwxrwxrwx 1 bhavya bhavya    11 Aug 28 22:43 s_link -> file_sL.txt
lrwxrwxrwx 1 bhavya bhavya    13 Aug 28 22:47 s_link_1 -> file_sL_1.txt


2.System Call:
bhavya@Bhavya:~/SSHandsOn1$ gcc 1b.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
Hard Link is created
bhavya@Bhavya:~/SSHandsOn1$ ls -l
total 24
-rw-rw-r-- 1 bhavya bhavya  1270 Aug 28 22:54 1b.c
-rw-rw-r-- 1 bhavya bhavya  1272 Aug 28 22:51 1.c
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 21:59 abc.txt
-rwxrwxr-x 1 bhavya bhavya 15992 Aug 28 22:54 a.out
-rw-rw-r-- 2 bhavya bhavya     0 Aug 28 22:54 file_hL.txt
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 22:46 file_sL_1.txt
lrwxrwxrwx 1 bhavya bhavya     6 Aug 28 22:27 file_sL.txt -> s_link
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 22:27 file_s.txt
-rw-rw-r-- 2 bhavya bhavya     0 Aug 28 22:54 h_link
lrwxrwxrwx 1 bhavya bhavya    11 Aug 28 22:43 s_link -> file_sL.txt
lrwxrwxrwx 1 bhavya bhavya    13 Aug 28 22:47 s_link_1 -> file_sL_1.txt

*/

