#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
	int fd,n;
	fd=open(argv[1],O_RDONLY);
	char buff[1000];
	if(errno==ENOENT)
	{
		perror(argv[1]);
	}
	else
	{
		printf("Contents of File are\n");
		n=read(fd,buff,sizeof(buff));
		write(1,buff,n);
	}
	close(fd);
}
