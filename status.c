#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
void main(int argc,char *argv[])
{
struct stat buf;
if(stat(argv[1],&buf)<0)
printf("ERROR");
else
{
printf("\ngld:%d",buf.st_gid);
printf("\nnuid:%d",buf.st_uid);
printf("\nsize:%ld",buf.st_size);
printf("\natime:%ld",buf.st_atime);
printf("\nmtime:%ld",buf.st_mtime);
printf("\nctime:%ld",buf.st_ctime);
}
}
