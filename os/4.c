#include <stdio.h>

int main() {
    char* process_names[] = {"P1", "P2", "P3", "P4", "P5"};

    int num_processes = 5;
    int num_resource_types = 3;

    int allocation[5][3] = { { 0, 1, 0 }, { 2, 0, 0 }, { 3, 0, 2 }, { 2, 1, 1 }, { 0, 0, 2 } }; 
    int max_demand[5][3] = { { 7, 5, 3 }, { 3, 2, 2 }, { 9, 0, 2 }, { 4, 2, 2 }, { 5, 3, 3 } };
    int available_resources[3] = { 3, 3, 2 }; 

    int finish_status[num_processes], safe_sequence[num_processes], sequence_index = 0;
    for (int i = 0; i < num_processes; i++) {
        finish_status[i] = 0;
    }
    int remaining_need[num_processes][num_resource_types];
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resource_types; j++) {
            remaining_need[i][j] = max_demand[i][j] - allocation[i][j];
        }
    }
    
    printf("Processes\tAllocation\tMax Demand\tRemaining Need\n");
    printf("_____________________\n");

    for (int i = 0; i < num_processes; i++) {
        printf("%s\t\t", process_names[i]);
        for (int j = 0; j < num_resource_types; j++) {
            printf(" %d ", allocation[i][j]);
        }
        printf("\t");
        for (int j = 0; j < num_resource_types; j++) {
            printf(" %d ", max_demand[i][j]);
        }
        
        printf("\t");
     
            for (int j = 0; j < num_resource_types; j++) {
                printf(" %d ", remaining_need[i][j]);
        
        }
        printf("\n");
    }
    
    int resource_index = 0;
    printf("Available\n______\n");
    for (int i = 0; i < num_processes; i++) {
      
        for (int j = 0; j < num_processes; j++) {
            if (finish_status[j] == 0) {
                int can_allocate = 0;
                for (int k = 0; k < num_resource_types; k++) {
                    if (remaining_need[j][k] > available_resources[k]){
                        can_allocate = 1;
                        break;
                    }
                }
                if (can_allocate == 0) {
                    safe_sequence[sequence_index++] = j;
                    
                    for (resource_index = 0; resource_index < num_resource_types; resource_index++) {
                        printf(" %d ",available_resources[resource_index]);
                        available_resources[resource_index] += allocation[j][resource_index];
                        
                    }
                    finish_status[j] = 1;
                    printf("\n");
                }
            }
        }
    }
        int system_is_safe = 1;
    for(int i=0;i<num_processes;i++) {
        if(finish_status[i]==0) {
            system_is_safe=0;
            printf("The system is not safe");
            break;
        }
    }

    if(system_is_safe==1) {
        printf("The system is safe. Following is the safe sequence:\n");
        for (int i = 0; i < num_processes - 1; i++) {
            printf(" P%d ->", safe_sequence[i]+1);
        }
        printf(" P%d", safe_sequence[num_processes - 1]+1);
    }

    return 0;
}