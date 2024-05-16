#include<stdio.h>
int main()
{
	int n;
	printf("Enter no. of process");
	scanf("%d",&n);
	int pri[n],pro[n],at[n],bt[n],ct[n],tat[n],wt[n],bbt[n];

	for(int i=0;i<n;i++)
	{
	pri[i] = pro[i] = at[i] = bt[i] = tat[i]= ct[i] =wt[i] = bbt[i] = 0;
    }
	for (int i = 0; i < n; i++) {
       	 printf("Enter ID of process %d:", i + 1);
        	scanf("%d", &pro[i]);

	printf("Enter Priority of process %d:", i + 1);
        	scanf("%d", &pri[i]);

        	printf("Enter Arrival Time of process %d:", i + 1);
        	scanf("%d", &at[i]);

       	 printf("Enter Burst Time of process %d:", i + 1);
        	scanf("%d", &bt[i]);
        	bbt[i] = bt[i];

    	}
	int current_time=0,selected_pid =0, max_pri=0, selected_pindex =0 , comp = 0;
	printf("gantt chart");
	while(comp<n)
	{
            max_pri = 0;
	for(int i=0;i<n;i++)
	{
		if(at[i] <= current_time && max_pri <pri[i] && bt[i] > 0)
		{
		selected_pid = pro[i];
		selected_pindex = i;
		max_pri = pri[i];
		}
	}
	
	bt[selected_pindex]--;
	current_time++;
for(int i =0;i<n;i++)
	{
	if(bt[i] ==0 && ct[i] == 0)
	{
	ct[i] = current_time;
	comp++;
	printf("P%d",selected_pid);
	}
	}
	}
	
	}
