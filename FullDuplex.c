#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
	char buff1[100],buff2[100];
	int n1,n2,n3,n4,pid;
	int pipefd1[2],pipefd2[2];
	if(pipe(pipefd1)<0 || pipe(pipefd2))
	{
		printf("Interface Creation Error\n");
	}	
	else if((pid=fork())<0)
	{
		printf("Process Creation Error\n");
	}
	else if(pid==0)
	{
		printf("Child Processs\n");
		close(pipefd1[0]);
		close(pipefd2[1]);
		n1=read(0,buff1,sizeof(buff1));
		write(pipefd1[1],buff1,n1);
		n2=read(pipefd2[0],buff1,sizeof(buff1));
		write(1,buff1,n2);		
		//exit(0);
		
	}
	else
	{
		printf("Parent Processs\n");
		close(pipefd1[1]);
		close(pipefd2[0]);
		n3=read(pipefd1[0],buff2,sizeof(buff2));
		write(1,buff2,n3);
		n4=read(0,buff2,sizeof(buff2));
		write(pipefd2[1],buff2,n4);

	}
	
}
