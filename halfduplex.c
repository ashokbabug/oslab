#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
	int pipefd[2],pid,n1,n2;
	char buff[100];
	if(pipe(pipefd)<0)
	printf("Interface Creation Error\n");
	else if((pid=vfork())<0)
	{
	printf("Process Creation Error\n");
	}
	else if(pid==0)
	{
		printf("Child is Executing\n");
		close(pipefd[0]);
		n1=read(0,buff,sizeof(buff));
		write(pipefd[1],buff,n1);
		exit(0);
	}
	else
	{
		printf("\nParent is Executing\n");
		close(pipefd[1]);
		n2=read(pipefd[0],buff,sizeof(buff));
		write(1,buff,n2);
	}

}
