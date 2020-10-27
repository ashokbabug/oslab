#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
void main(int argc,char*argv[])
{
struct stat buf;
stat(argv[1],&buf);
if(S_ISREG(buf.st_mode))
printf("\n REGULAR FILE");
else if(S_ISDIR(buf.st_mode))
printf("\n DIRECTORY FILE");
else if(S_ISBLK(buf.st_mode))
printf("\n BLOCK SPECIAL FILE");
else if(S_ISFIFO(buf.st_mode))
printf("\n PIPE & FIFO FILE");
else if(S_ISSOCK(buf.st_mode))
printf("\n SOCKET FILE");
}
