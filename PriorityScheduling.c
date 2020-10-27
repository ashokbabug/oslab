#include<stdio.h>
int main()
{
  int n,i,j,t;
  printf("Enter no. of process:");
  scanf("%d",&n);
  int bt[n],tat[n],wt[n],count=0,pt[n];
  printf("Enter Burst times and.priority of processes:");
  for(i=0;i<n;i++)
  {
    scanf("%d%d",&bt[i],&pt[i]);
    wt[i]=tat[i]=0;
  }
  float aw=0,at=0;
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-1-i;j++)
    {
      if(pt[j]<pt[j+1])
      {
        t=bt[j];bt[j]=bt[j+1];bt[j+1]=t;
        t=pt[j];pt[j]=pt[j+1];pt[j+1]=t;
      }
    }
  }
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
