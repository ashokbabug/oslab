#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
char ch;
FILE*fp1,*fp2;
fp1=fopen("file1.txt","r");
fp2=fopen("file5.txt","w");
while((ch=fgetc(fp1))!=EOF)
{
putc(ch,fp2);
}
fclose(fp1);
fclose(fp2);
}
