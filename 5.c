/*Name: Bhavya Joshi
Reg no.:MT2024032
5. Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

int file_desc[5],t;
const char *file_name[5]={"file_5_1.txt","file_5_2.txt","file_5_3.txt","file_5_4.txt","file_5_5.txt"};

while(1){

for(t=0;t<5;t++){

file_desc[t]=open(file_name[t],O_CREAT|O_WRONLY,0644);

if(file_desc[t]==-1){
perror("There is an error in opening the file");
exit(1);

}

printf("%s is open.\n",file_name[t]);

}
sleep(1);
}

for(t=0;t<5;t++){
close(file_desc[t]);
}

return 0;

}


/*Output:
bhavya@Bhavya:~/SSHandsOn1$ ls -l /proc/10382/fd
total 0
lrwx------ 1 bhavya bhavya 64 Aug 29 20:03 0 -> /dev/pts/1
lrwx------ 1 bhavya bhavya 64 Aug 29 20:03 1 -> /dev/pts/1
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 10 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 100 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 101 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 102 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 103 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 104 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 105 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 106 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 107 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 108 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 109 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 11 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 110 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 111 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 112 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 113 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 114 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 115 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 116 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 117 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 118 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 119 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 12 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 120 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 121 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 122 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 123 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 124 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 125 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 126 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 127 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 128 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 129 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 13 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 130 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 131 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 132 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 133 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 134 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 135 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 136 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 137 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 138 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 139 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 14 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 140 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 141 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 142 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 143 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 144 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 145 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 146 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 147 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 148 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 149 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 15 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 150 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 151 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 152 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 153 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 154 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 155 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 156 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 157 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 158 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 159 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 16 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 160 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 161 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 162 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 163 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 164 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 165 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 166 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 167 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 168 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 169 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 17 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 170 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 171 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 172 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 173 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 174 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 175 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 176 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 177 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 18 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 19 -> /home/bhavya/SSHandsOn1/file_5_2.txt
lrwx------ 1 bhavya bhavya 64 Aug 29 20:03 2 -> /dev/pts/1
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 20 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 21 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 22 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 23 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 24 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 25 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 26 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 27 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 28 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 29 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 3 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 30 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 31 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 32 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 33 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 34 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 35 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 36 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 37 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 38 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 39 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 4 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 40 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 41 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 42 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 43 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 44 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 45 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 46 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 47 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 48 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 49 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 5 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 50 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 51 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 52 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 53 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 54 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 55 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 56 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 57 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 58 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 59 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 6 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 60 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 61 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 62 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 63 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 64 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 65 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 66 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 67 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 68 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 69 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 7 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 70 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 71 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 72 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 73 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 74 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 75 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 76 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 77 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 78 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 79 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 8 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 80 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 81 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 82 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 83 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 84 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 85 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 86 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 87 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 88 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 89 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 9 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 90 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 91 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 92 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 93 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 94 -> /home/bhavya/SSHandsOn1/file_5_2.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 95 -> /home/bhavya/SSHandsOn1/file_5_3.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 96 -> /home/bhavya/SSHandsOn1/file_5_4.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 97 -> /home/bhavya/SSHandsOn1/file_5_5.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 98 -> /home/bhavya/SSHandsOn1/file_5_1.txt
l-wx------ 1 bhavya bhavya 64 Aug 29 20:03 99 -> /home/bhavya/SSHandsOn1/file_5_2.txt

*/

