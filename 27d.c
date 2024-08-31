/*
Name:27d.c
Author: Bhavya Joshi
Description:27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
Date: 30th Aug, 2024.
*/

#include<stdio.h>
#include<unistd.h>

int main(){

char *arr[]={"ls","-Rl",NULL};

execv("/bin/ls",arr);

perror("There is an error in executing execv system call\n");

return 0;

}

/*Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 27d.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out
.:
total 144
-rw-rw-r-- 1 bhavya bhavya  1110 Aug 29 23:01 10.c
-rw-rw-r-- 1 bhavya bhavya   245 Aug 29 23:07 11.c
-rw-rw-r-- 1 bhavya bhavya   632 Aug 30 00:02 19.c
-rw-rw-r-- 1 bhavya bhavya  2209 Aug 28 22:59 1b.c
-rw-rw-r-- 1 bhavya bhavya  1272 Aug 28 22:51 1.c
-rw-rw-r-- 1 bhavya bhavya   670 Aug 29 03:01 1c.c
-rw-rw-r-- 1 bhavya bhavya   745 Aug 30 14:02 24.c
-rw-rw-r-- 1 bhavya bhavya   242 Aug 30 14:56 26.c
-rw-rw-r-- 1 bhavya bhavya  3036 Aug 30 15:08 27a.c
-rw-rw-r-- 1 bhavya bhavya  3034 Aug 30 15:12 27b.c
-rw-rw-r-- 1 bhavya bhavya  3062 Aug 30 15:14 27c.c
-rw-rw-r-- 1 bhavya bhavya   374 Aug 30 15:17 27d.c
-rw-rw-r-- 1 bhavya bhavya   354 Aug 30 15:07 27e.c
-rw-rw-r-- 1 bhavya bhavya   851 Aug 30 02:24 28.c
-rw-rw-r-- 1 bhavya bhavya  1392 Aug 30 02:03 29.c
-rw-rw-r-- 1 bhavya bhavya  2565 Aug 29 09:15 2.c
-rw-rw-r-- 1 bhavya bhavya   704 Aug 30 00:31 30.c
-rw-rw-r-- 1 bhavya bhavya   511 Aug 29 02:39 3.c
-rw-rw-r-- 1 bhavya bhavya   856 Aug 29 11:13 4.c
-rw-rw-r-- 1 bhavya bhavya 16060 Aug 29 20:26 5.c
-rw-rw-r-- 1 bhavya bhavya   460 Aug 28 23:13 6.c
-rw-rw-r-- 1 bhavya bhavya   805 Aug 29 22:24 7.c
-rw-rw-r-- 1 bhavya bhavya   694 Aug 29 22:22 8.c
-rw-rw-r-- 1 bhavya bhavya  1260 Aug 29 01:19 9.c
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 21:59 abc.txt
-rwxrwxr-x 1 bhavya bhavya 16048 Aug 30 15:17 a.out
-rw------- 1 bhavya bhavya     0 Aug 29 02:38 fd_1
prw-rw-r-- 1 bhavya bhavya     0 Aug 29 02:59 fifo_1
prw-rw-r-- 1 bhavya bhavya     0 Aug 29 03:00 fifo_2
-rw-rw-r-- 1 bhavya bhavya    32 Aug 29 00:24 file
-rw-rw-r-- 1 bhavya bhavya    38 Aug 28 23:30 file1
-rw-r--r-- 1 bhavya bhavya    52 Aug 29 22:54 file_10
-rw-r--r-- 1 bhavya bhavya     0 Aug 29 19:40 file_5_1.txt
-rw-r--r-- 1 bhavya bhavya     0 Aug 29 19:40 file_5_2.txt
-rw-r--r-- 1 bhavya bhavya     0 Aug 29 19:40 file_5_3.txt
-rw-r--r-- 1 bhavya bhavya     0 Aug 29 19:40 file_5_4.txt
-rw-r--r-- 1 bhavya bhavya     0 Aug 29 19:40 file_5_5.txt
-rw-rw-r-- 1 bhavya bhavya    37 Aug 29 18:08 file_7_1
-rw------- 1 bhavya bhavya    37 Aug 29 22:23 file_7_2
-rw-rw-r-- 2 bhavya bhavya     0 Aug 28 22:56 file_hL_1.txt
-rw-rw-r-- 2 bhavya bhavya     0 Aug 28 22:54 file_hL.txt
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 22:46 file_sL_1.txt
lrwxrwxrwx 1 bhavya bhavya     6 Aug 28 22:27 file_sL.txt -> s_link
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 22:27 file_s.txt
-rw-rw-r-- 2 bhavya bhavya     0 Aug 28 22:54 h_link
-rw-rw-r-- 2 bhavya bhavya     0 Aug 28 22:56 h_link_1
lrwxrwxrwx 1 bhavya bhavya    11 Aug 28 22:43 s_link -> file_sL.txt
lrwxrwxrwx 1 bhavya bhavya    13 Aug 28 22:47 s_link_1 -> file_sL_1.txt

*/

