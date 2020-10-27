#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	int pid=vfork();	
	if(pid<0)
	{
		printf("Process Creation Error\n");
	}
	else if(pid>0)
	{
		printf("Parent Executing\n");
	}
	else
	{
		printf("Child Process\n");
		execv("/home/ubuntu/Executable",argv);
		exit(0);
	}
}
