#include <stdio.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

int min(int a, int b) {
    return (a < b) ? a : b;
}

void round_robin(struct Process processes[], int n, int quantum) {
    int current_time = 0;
    int completed = 0;

    printf("\n\nGantt Chart:\n");
    
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            int execute_time = 0 ;
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= current_time) {
                if(processes[i].remaining_time == quantum) {
                    execute_time = quantum;
                    }
                    else{
                execute_time= min(processes[i].remaining_time, quantum);}
                processes[i].remaining_time -= execute_time;
                current_time += execute_time;

                printf(" | P%d ", processes[i].id);

                if (processes[i].remaining_time == 0) {
                    processes[i].completion_time = current_time;
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    completed++;
                }
            }
        }
    }
}

int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time of process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        
        printf("Enter Burst Time of process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);

        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("\n");

    round_robin(processes, n, quantum);

    printf(" |\n\n");

    // Printing process details
    printf("| Process ID | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |\n");
    printf("|------------|--------------|------------|-----------------|-----------------|--------------|\n");
    for (int i = 0; i < n; i++) {
        printf("|%12d |%13d |%11d |%16d |%16d |%13d |\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    return 0;
}

