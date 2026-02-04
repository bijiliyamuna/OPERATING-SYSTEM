#include<stdio.h>
void main()
{
	int p[10],bt[10],wt[10],tat[10],twt,ttat,n,i,j,temp1,temp2;
	float awt,atat;
	printf("\n Enter no. of process ready to execute:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter Process number");
		scanf("%d",&p[i]);
		printf("\n Enter Burst time");
		scanf("%d",&bt[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(bt[i]<bt[j])
			{
				temp1=bt[i];
				bt[i]=bt[j];
				bt[j]=temp1;
				temp2=p[i];
				p[i]=p[j];
				p[j]=temp2;
			}
		}
	}
	wt[0]=0;
	twt=0;
	tat[0]=bt[0];
	ttat=bt[0];
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=wt[i]+bt[i];
		twt=twt+wt[i];
		ttat=ttat+tat[i];
	}
	awt=(float)twt/n;
	atat=(float)ttat/n;
	printf("\n Process Number Burst Time Waiting Time Turn Around Time");
	for(i=0;i<n;i++)
	{
		printf("\n %d\t%d\t%d\t%d\t",p[i],bt[i],wt[i],tat[i]);
	}
	printf("\n Average Waiting Time = %f",awt);
	printf("\n Average Turn Around Time = %f",atat);
}
