#include<stdio.h>
int find(int arr[],int n,int x)
{
	if(n<0)
	return -1;
	if(arr[n]==x)
	return n;
	return find(arr,n-1,x);
}
int main()
{
	int n,page_fault=0,i,j,k,c=0;
	char s[100];
	printf("Enter No of pages:");
	scanf("%d",&n);
	printf("Enter Reference String:");
	scanf("%s",s);
	int arr[n];
	i=0;j=0;
	while(s[i]!='\0')
	{
		if(c<n)
		{
			arr[j]=s[i]-'0';
			j=(j+1)%n;
			page_fault++;
			c++;
		}
		else
		{
			if(find(arr,n-1,s[i]-'0')==-1)
			{
				arr[j]=s[i]-'0';
				j=(j+1)%n;
				page_fault++;	
			}
		}
		i++;
	}
	printf("Page Faults=%d",page_fault);
}
