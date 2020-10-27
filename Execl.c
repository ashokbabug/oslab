#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int pid=fork();
	if(pid<0)
	{
		printf("Process Creation Error\n");
		exit(0);
	}
	else if(pid>0)
	{
		printf("Parent Process\n");
	}
	else
	{
		printf("Child Process\n");
		execl("/home/ubuntu/Executable","A","B","C","D","E",(char*)0);
	}
	
	
}
