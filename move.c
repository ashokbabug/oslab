#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
link("abc.txt","oslab2.txt");
unlink("abc.txt");
}
