/*Name: 9.c
Author:Bhavya Joshi
Description:9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date:28th Aug,24

*/

#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<sys/stat.h>

int main(int in, char* arr[]){

struct stat s;
stat (arr[1],&s);
printf("inode number: %ju\n ",s.st_ino);
printf("Number of Hard Links: %ju\n",s.st_nlink);
printf("UID: %u\n ",s.st_uid);
printf("GID: %u\n",s.st_gid);
printf("Size: %jd bytes\n",s.st_size);
printf("Block size: %jd bytes ",s.st_blksize);
printf("Number of Blocks: %jd\n",s.st_blocks);
printf("Time of Last Access: %s\n",ctime(&s.st_atime));
printf("Time of Lat Modification: %s\n ",ctime(&s.st_mtime));
printf("Time of Last Change: %s\n",ctime(&s.st_ctime));

return 0;

}

/*Output:
bhavya@Bhavya:~/SSHandsOn1$ gcc 9.c
bhavya@Bhavya:~/SSHandsOn1$ ./a.out file1
inode number: 2630028
 Number of Hard Links: 1
UID: 1000
 GID: 1000
Size: 38 bytes
Block size: 4096 bytes Number of Blocks: 8
Time of Last Access: Wed Aug 28 23:32:01 2024

Time of Lat Modification: Wed Aug 28 23:30:43 2024

 Time of Last Change: Wed Aug 28 23:30:43 2024
*/
