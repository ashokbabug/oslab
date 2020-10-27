#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
int main()
{
int pid;
pid=fork();
if(pid==0)
{
printf("child process is created\n");
}
else if(pid>0)
printf("parent process is created");
else 
{
printf("ERROR");
}
}

