#include<stdio.h>

int main()
{
    printf("Enter number of processes: ");
    int np = 0;
    scanf("%d",&np);
    int pid[np], at[np], bt[np], ct[np], wt[np], tat[np] ;
    int avgwt = 0, avgtat = 0;

    for(int i = 0; i < np; i++)
    {
        printf("Enter ID for process %d: ", i + 1);
        scanf("%d",&pid[i]);

        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d",&at[i]);

        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d",&bt[i]);

        printf("--------------------------------------------\n");

        if(i == 0)
        {
            ct[i] = bt[i];
        }
        else
        {
            ct[i] = ct[i - 1] + bt[i];
        }

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgwt += wt[i];
        avgtat += tat[i];
    }

    avgwt = avgwt / np;
    avgtat = avgtat / np;

    printf("\n-------------------------------------------------------------------------------------------------------\n");
    printf("| PID \t Arrival-Time \t Burst-Time \t Completion-Time \t Turnaround-Time \t Waiting-Time |\n");

    for(int i = 0; i < np; i++)
    {
        printf("|%3d \t\t %3d \t\t %3d \t\t %3d \t\t\t %3d \t\t\t %3d|\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("-------------------------------------------------------------------------------------------------------\n");
    printf("| Avg Waiting Time: %d|\n", avgwt);
    printf("| Avg Turnaround Time: %d|\n", avgtat);
    printf("-------------------------------------------------------------------------------------------------------\n");

    printf("Gantt Chart: \n");

    for(int i = 0; i < np; i++)
    {
        printf("+---");
    }

    printf("+\n");

    for(int i = 0; i < np; i++)
    {
        printf("| P%d", pid[i]);
    }

    printf("|\n");

    for(int i = 0; i < np; i++)
    {
        printf("+---");
    }

    printf("+\n");

    for(int i = 0; i <= np; i++)
    {
        if(i == 0)
        {
            printf("%d  ", wt[i]);
        }
else
        {
            printf("%d  ", ct[i - 1]);
        }
    }

    printf("\n");

    return 0;
}
