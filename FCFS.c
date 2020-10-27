#include<stdio.h>
int main()
{
  int n,i,j,t;
  printf("Enter no. of process:");
  scanf("%d",&n);
  int bt[n],tat[n],wt[n],count=0;
  printf("Enter Burst times of processes:");
  for(i=0;i<n;i++)
  {
    scanf("%d",&bt[i]);
    wt[i]=tat[i]=0;
  }
  float aw=0,at=0;
  t=0;
  
  for(i=0;i<n;i++)
  {
   wt[i]=t;
   t+=bt[i];
   tat[i]=t;
  }
  for(i=0;i<n;i++)
  {
    aw+=wt[i];
    at+=tat[i];
  }
  aw=(aw/n);
  at=(at/n);
  printf("Average Waiting time=%f\n",(aw));
  printf("Average Turn Around time=%f\n",(at));
  
}
