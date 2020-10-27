#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
FILE*fp1=fopen("file1.txt","r");
FILE*fp2=fopen("file2.txt","r");
char c;
FILE*fp3=fopen("file3.txt","w");
if(fp1==NULL||fp2==NULL||fp3==NULL)
{
puts("could not open");
exit(0);
}
while((c=fgetc(fp1))!=EOF)
fputc(c,fp3);
while((c=fgetc(fp2))!=EOF)
fputc(c,fp3);
printf("merged file 1&2 into file 3");
fclose(fp1);
fclose(fp2);
fclose(fp3);
return 0;
exit(0);
}

