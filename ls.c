#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
DIR* dp;
struct dirent *p;
if((dp=opendir(argv[1]))==NULL)
printf("error:cannot open directory");
else
{
while((p=readdir(dp))!=NULL)
{
printf("%ld",p->d_ino);
printf("%s",p->d_name);
}
}
}
