#include<stdio.h>
#include<limits.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

// Function to find the process with the shortest remaining burst time
int find_shortest_job(struct Process *processes, int n, int current_time) {
    int shortest_job = -1;
    int shortest_burst = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (processes[i].arrival_time <= current_time && processes[i].remaining_time < shortest_burst && processes[i].remaining_time > 0) {
            shortest_burst = processes[i].remaining_time;
            shortest_job = i;
        }
    }
    return shortest_job;
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

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

    int current_time = 0;
    int completed = 0;

    printf("\n\nGantt Chart:\n");

    // Main SJF preemptive loop
    while (completed < n) {
        int shortest_job = find_shortest_job(processes, n, current_time);
        if (shortest_job == -1) {
            // If no process is available, move to the next arrival time
            current_time++;
            continue;
        }
        
        printf("| P%d ", processes[shortest_job].id);
        processes[shortest_job].remaining_time--;

        if (processes[shortest_job].remaining_time == 0) {
            // If the process has completed its execution
            completed++;
            processes[shortest_job].completion_time = current_time + 1;
            processes[shortest_job].turnaround_time = processes[shortest_job].completion_time - processes[shortest_job].arrival_time;
            processes[shortest_job].waiting_time = processes[shortest_job].turnaround_time - processes[shortest_job].burst_time;
        }

        current_time++;
    }

    printf("|\n\n");
    float avgwt = 0, avgtat = 0;
    // Calculating average waiting time and average turnaround time
    for (int i = 0; i < n; i++) {
        avgwt += processes[i].waiting_time;
        avgtat += processes[i].turnaround_time;
    }
    avgwt /= n;
    avgtat /= n;

    // Printing process details
    printf("| Process ID | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |\n");
    printf("|------------|--------------|------------|-----------------|-----------------|--------------|\n");
    for (int i = 0; i < n; i++) {
        printf("|%12d |%13d |%11d |%16d |%16d |%13d |\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average Turnaround Time : %f\n", avgtat);
    printf("Average Waiting Time : %f\n", avgwt);

    return 0;
}
