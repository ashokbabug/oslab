#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
FILE *fp;
fp=fopen("content.txt","r");
int c;
printf("enter no.of lines to be viewed");
scanf("%d",&c);
int i=0;
char ch;
while(i<c)
{
ch=fgetc(fp);
putchar(ch);
if(ch=='\n')
i++;
}
fclose(fp);
}
