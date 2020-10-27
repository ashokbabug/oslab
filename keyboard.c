#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE*fp;
char ch;
fp=fopen("read.txt","w");
while((ch=getchar()!=\n)
{
putc(ch,fp);
}
fclose(fp);
}
