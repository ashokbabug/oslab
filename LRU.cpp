#include<stdio.h>
int find(int arr[],int n,int x)
{
	if(n<0)
	return -1;
	if(arr[n]==x)
	return n;
	return find(arr,n-1,x);
}
int findvictim(char s[],int pos,int arr[],int n)
{
	int nearpos[n],i,j,t;
	for(j=0;j<n;j++)
	{
		i=pos-1;
		while(i>=0)
		{
			if(arr[j]==s[i]-'0')
			{
				nearpos[j]=i;
				break;
			}
			i--;
		}
		if(i==-1)
		return find(arr,n-1,arr[j]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(nearpos[j]>nearpos[j+1])
			{
				t=arr[j];arr[j]=arr[j+1];arr[j+1]=t;
				t=nearpos[j];nearpos[j]=nearpos[j+1];nearpos[j+1]=t;
			}
		}
	}
	return find(arr,n-1,arr[0]);
}
int main()
{
	int n,page_fault=0,i,j,k,c=0,x;
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
			arr[j++]=s[i]-'0';//j=(j+1)%n;
			page_fault++;
			c++;
		}
		else
		{
			if(find(arr,n-1,s[i]-'0')==-1)
			{
				x=findvictim(s,i,arr,n);
				arr[x]=s[i]-'0';
				page_fault++;	
			}
		}
		i++;
	}
	printf("Page Faults=%d",page_fault);
}
