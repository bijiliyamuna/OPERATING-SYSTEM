#include<stdio.h>
void main()
{
	int p[10],bt[10],wt[10],prt[10],tat[10],twt,ttat,n,i,j,temp;
	float awt,atat;
	printf("\n Enter number of processes ready to execute:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter process number");
		scanf("%d",&p[i]);
		printf("\n Enter Burst time:");
		scanf("%d",&bt[i]);
		printf("\n Enter Priority number");
		scanf("%d",&prt[i]);
	
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(prt[i]<prt[j])
			{
				temp=prt[i];
				prt[i]=prt[j];
				prt[j]=temp;
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				
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
	printf("\n Process Number Burst time Waiting time Priority Number Turn Around Time");
	for(i=0;i<n;i++)
	{
		printf("\n %d\t%d\t%d\t%d\t%d\t",p[i],bt[i],wt[i],prt[i],tat[i]);
	}
	printf("\n Average Waiting Time = %f",awt);
	printf("\n Average Turn Around Time = %f",atat);

	
}
