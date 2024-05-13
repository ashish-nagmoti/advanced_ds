#include<stdio.h>

int main() {
    int n;
    printf("Enter no. of processes:");
    scanf("%d", &n);
    int pri[n], pro[n], at[n], bt[n], ct[n], tat[n], wt[n], bbt[n];
    // initializing all arrays
    for (int i = 0; i < n; i++) {
        pri[i] = pro[i] = at[i] = bt[i] = ct[i] = tat[i] = wt[i] = 0;
    }
    // taking input values
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
    int ite = 0, temp = 0, temp1 = 0, temp2 = 0, temp3 = 0;
    printf("\n\nGantt Chart:\n");
    while (temp3 < n) {
        for (int i = 0; i < n; i++) {
            if (at[i] <= ite && temp1 < pri[i] && bt[i] > 0) {
                temp = pro[i];
                temp2 = i;
            }
        }
        temp1 = 0;
        bt[temp2]--;
        ite++;

        for (int i = 0; i < n; i++) {
            if (bt[i] == 0 && ct[i] == 0) {
                ct[i] = ite;
                temp3++;
            }
        }
        printf("P%d|", temp);
    }
    printf("\n\n");
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bbt[i];
    }
    float avgwt = 0, avgtat = 0;
    for (int i = 0; i < n; i++) {
        avgwt += wt[i];
        avgtat += tat[i];
    }
    avgwt = avgwt / n;
    avgtat = avgtat / n;
    printf("| Process ID \t  Priority \t Arrival-Time \t  Burst-Time \t   Completion-Time \t  Turn-Around-Time \t  Waiting-Time|\n");
    for (int i = 0; i < n; i++) {
        printf("|%d \t\t %d \t\t %d \t\t %d\t\t\t %d \t\t\t %d \t\t\t %d|\n", pro[i], pri[i], at[i], bbt[i], ct[i], tat[i], wt[i]);
    }
    printf("Average Turn Around Time : %f\n", avgtat);
    printf("Average Waiting Time : %f\n", avgwt);

    return 0;
}
