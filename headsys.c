#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
void main(int argc,char*argv[])
{
int fd,n=4,c=0,k,i=0;
char buff[100];
fd=open("abc1.txt",O_RDONLY);
k=read(fd,buff,sizeof(buff));
while(c<n&&i<k)
{
printf("%c",buff[i]);
if(buff[i]=='\n')
{
c++;
}
i++;
}
}
