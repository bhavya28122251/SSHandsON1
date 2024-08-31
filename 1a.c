/*Name: 1a.c
Author:Bhavya Joshi
Description: 1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date:28th Aug, 2024
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main(){
char *file_path="file_sL.txt";
char *soft_link="s_link";

if(symlink(file_path,soft_link)==-1){
printf("Soft Link is not created\n");
}

else{
printf("Soft Link is created\n");
}
return 0;
}

/*Output:
1.shell command:
havya@Bhavya:~/SSHandsOn1$ ln -s file_sL_1.txt s_link_1
bhavya@Bhavya:~/SSHandsOn1$ ls -l
total 20
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 22:39 1b.c
-rw-rw-r-- 1 bhavya bhavya   392 Aug 28 22:45 1.c
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 21:59 abc.txt
-rwxrwxr-x 1 bhavya bhavya 15992 Aug 28 22:43 a.out
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 22:46 file_sL_1.txt
lrwxrwxrwx 1 bhavya bhavya     6 Aug 28 22:27 file_sL.txt -> s_link
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 22:27 file_s.txt
lrwxrwxrwx 1 bhavya bhavya    11 Aug 28 22:43 s_link -> file_sL.txt
lrwxrwxrwx 1 bhavya bhavya    13 Aug 28 22:47 s_link_1 -> file_sL_1.txt

2.System Call:
lrwxrwxrwx 1 bhavya bhavya    11 Aug 28 22:43 s_link -> file_sL.txt
*/
