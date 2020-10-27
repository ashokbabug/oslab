#include<stdio.h>
struct processnode
{
	float processtime;
	float leavetime;	
	int completed;
	float completetime;
	float waitingtime;
};
typedef struct processnode process;
int main()
{
	int n,i,count=0;
	float tq,t=0,WT=0,TAT=0;
	printf("Enter No of Process and Time Quantum:");
	scanf("%d %f",&n,&tq);
	process P[n];
	for(i=0;i<n;i++)
	{	
		printf("Enter Burst time of Process P%d:",i);
		scanf("%f",&P[i].processtime);
		P[i].waitingtime=P[i].leavetime=P[i].completed=0;
	}
	i=0;
	while(count<n)
	{
		if(P[i].completed==0)
		{
			P[i].waitingtime+=(t-P[i].leavetime);
			if(P[i].processtime<=tq)
			{	
				t+=P[i].processtime;
				P[i].processtime=0;
				P[i].completed=1;
				P[i].completetime=t;
				WT+=P[i].waitingtime;
				TAT+=P[i].completetime;
				count++;
			}
			else
			{
				t+=tq;
				P[i].processtime-=tq;
			}
			P[i].leavetime=t;
		}
		i=(i+1)%n;
	}
	for(i=0;i<n;i++)
	{
		printf("P%d %f %f\n",i,P[i].waitingtime,P[i].completetime);
	}
	printf("\nAverage Waiting Time=%f",WT/n);
	printf("\nAverage Turn Around Time=%f",TAT/n);
}
