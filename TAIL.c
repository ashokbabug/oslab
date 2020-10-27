#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
void main(int argc,char *argv[])
{
	int fd,n,l,c=0,nn,i,j;
	char buff[100],buff2[100];
	fd=open(argv[1],O_RDONLY);
	n=read(fd,buff,sizeof(buff));
	l=strlen(buff);
	printf("Enter No of Lines to be Viewed:");
	scanf("%d",&nn);
	j=0;
	i=l-1;
	while(c<nn+1)
	{
		buff2[j]=buff[i];
		if(buff[i]=='\n')
			c++;
		i--;
		j++;	
	}
	i=j-1;
	j=0;
	while(buff2[i]!='\0')
	{
		buff[j]=buff2[i];
		i--;j++;
	}
	write(1,buff,j);	
}
