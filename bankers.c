#include<stdio.h>
#include<stdlib.h>
int check(int **need,int *work,int n,int m,int pos)
{
	int i;
	for(i=0;i<m;i++)
		if(need[pos][i]>work[i])
		return 0;
	return 1;
}
int main()
{
	int count=0,i,n,m,cp=0,j;
	printf("Enter no of Process:");
	scanf("%d",&n);
	printf("Enter no of Resources:");
	scanf("%d",&m);
	int *available,*max[n],*allocation[n],*need[n],*finish,*work,*sequence;
	available=(int *)malloc(sizeof(m*sizeof(int)));
	finish=(int *)malloc(sizeof(n*sizeof(int)));
	sequence=(int *)malloc(sizeof(n*sizeof(int)));
	work=(int *)malloc(sizeof(m*sizeof(int)));
	for(i=0;i<n;i++)
	{
		max[i]=(int *)malloc(sizeof(m*sizeof(int)));
		allocation[i]=(int *)malloc(sizeof(m*sizeof(int)));
		need[i]=(int *)malloc(sizeof(m*sizeof(int)));
	}
	printf("Enter Allocations:");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&allocation[i][j]);
	printf("Enter Max instances:");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
			need[i][j]=max[i][j]-allocation[i][j];
		}
	printf("Enter Available instances:");
	for(i=0;i<m;i++)
	{
		scanf("%d",&available[i]);
		work[i]=available[i];
	}
	for(i=0;i<n;i++)
	finish[i]=0;
	i=0;
	/*Determining Wheather the allocations leads to safe or unsafe sequence. 
	It determines any sort of safe sequence*/
	while(count<n)
	{
		cp=0;
		for(i=0;i<n;i++)
		{
			if(finish[i]==0 && check(need,work,n,m,i))
			{
				cp=1;
				sequence[count]=i;
				count++;
				finish[i]=1;
				for(j=0;j<m;j++)
				work[j]=work[j]+allocation[i][j];
			}
		}
		if(cp==0)
		break;
	}
	if(count<n)
		printf("The Sequence is Unsafe\n");
	else
	{
	printf("The Sequence is Safe\n");
	for(i=0;i<n;i++)
		printf("P%d ",sequence[i]);
	}
}
