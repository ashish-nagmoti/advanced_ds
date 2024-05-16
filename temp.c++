#include<stdio.h>
int main()
{
	printf("Enter a number of process");
	int np = 0;
	scanf("%d",&np);
	int pid[np],at[np],bt[np],ct[np],wt[np],tat[np];
	int avgwt=0, avgtat=0;
	for(int i=0;i<np;i++)
	{
	printf("Enter id for process %d: ", i+1);
	scanf("%d",&pid[i]);

	printf("Enter arrival time for process %d: ", i+1);
	scanf("%d",&at[i]);

	printf("Enter burst time for process %d: ", i+1);
	scanf("%d",&bt[i]);

	printf("---------------------------------------------------------");

	if(i==0)
	{
		ct[i] = bt[i];
	}
	else
	{ct[i]=ct[i-1] +bt[i];}
	tat[i] = ct[i] - at[i];
	wt[i] = tat[i] - bt[i];

	avgwt += wt[i];
	avgtat += tat[i];
	}
	avgwt = avgwt /np;
	avgtat = avgtat /np;

	printf("\n----------------------------------------------------");
	printf("|PID \t Arrival time \t Burst time \t ct \t tat \t wt| \n");
	for(int i=0;i<np;i++)
	{
	printf("|%3d \tt %3d \t\t %3d \t %3d \t %3d \t %3d|\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}

	printf("\n----------------------------------------------------");
	printf("| Avg Waiting Time: %d|\n", avgwt);
    printf("| Avg Turnaround Time: %d|\n", avgtat);
    printf("-------------------------------------------------------------------------------------------------------\n");
	printf("grantt chart:\n");
	
	for(int i=0;i<np;i++)
	{
	printf("|%d",pid[i]);
	}
	printf("|\n");
    for(int i = 0; i <= np; i++)
{
    if(i == 0)
    {
        printf("0  ");
    }
    else
    {
        printf("%d  ", ct[i - 1]);
    }
}


    return 0;
}