#include <stdio.h>

int main() {
    int n;
    printf("Enter no. of processes:");
    scanf("%d", &n);
    int priority[n], process_id[n], arrival_time[n], burst_time[n], completion_time[n], turnaround_time[n], waiting_time[n], initial_burst_time[n];
    
    // Initializing all arrays
    for (int i = 0; i < n; i++) {
        priority[i] = process_id[i] = arrival_time[i] = burst_time[i] = completion_time[i] = turnaround_time[i] = waiting_time[i] = 0;
    }
    
    // Taking input values
    for (int i = 0; i < n; i++) {
        printf("Enter ID of process %d:", i + 1);
        scanf("%d", &process_id[i]);

        printf("Enter Priority of process %d:", i + 1);
        scanf("%d", &priority[i]);

        printf("Enter Arrival Time of process %d:", i + 1);
        scanf("%d", &arrival_time[i]);

        printf("Enter Burst Time of process %d:", i + 1);
        scanf("%d", &burst_time[i]);
        initial_burst_time[i] = burst_time[i];
    }
    
    int current_time = 0, selected_process_id = 0, max_priority = 0, selected_process_index = 0, completed_processes = 0;
    
    printf("\n\nGantt Chart:\n");
    
    while (completed_processes < n) {
        for (int i = 0; i < n; i++) {
            if (arrival_time[i] <= current_time && max_priority < priority[i] && burst_time[i] > 0) {
                selected_process_id = process_id[i];
                selected_process_index = i;
                max_priority = priority[i];
            }
        }
        
        max_priority = 0;
        burst_time[selected_process_index]--;
        current_time++;
        
        for (int i = 0; i < n; i++) {
            if (burst_time[i] == 0 && completion_time[i] == 0) {
                completion_time[i] = current_time;
                completed_processes++;
            }
        }
        
        printf("P%d|", selected_process_id);
    }
    
    printf("\n\n");
    
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - initial_burst_time[i];
    }
    
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    
    for (int i = 0; i < n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
    printf("| Process ID \t  Priority \t Arrival-Time \t  Burst-Time \t   Completion-Time \t  Turn-Around-Time \t  Waiting-Time|\n");
    
    for (int i = 0; i < n; i++) {
        printf("|%d \t\t %d \t\t %d \t\t %d\t\t\t %d \t\t\t %d \t\t\t %d|\n", process_id[i], priority[i], arrival_time[i], initial_burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }
    
    printf("Average Turn Around Time : %f\n", avg_turnaround_time);
    printf("Average Waiting Time : %f\n", avg_waiting_time);

    return 0;
}