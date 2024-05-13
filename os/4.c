#include <stdio.h>

int main()
{
    char* process_names[] = {"P1", "P2", "P3", "P4", "P5"};

    int n = 5;
    int m = 3;

    int alloc[5][3] = { { 0, 1, 0 }, { 2, 0, 0 }, { 3, 0, 2 }, { 2, 1, 1 }, { 0, 0, 2 } }; 
    int max[5][3] = { { 7, 5, 3 }, { 3, 2, 2 }, { 9, 0, 2 }, { 4, 2, 2 }, { 5, 3, 3 } };
    int avail[3] = { 3, 3, 2 }; 

    int f[n], ans[n], ind = 0;
    for (int k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    
    printf("Processes\tAllocation\tMax need\tRemaining need\n");
    printf("_____________________\n");

    for (int i = 0; i < n; i++) {
        printf("%s\t\t", process_names[i]);
        for (int j = 0; j < m; j++) {
            printf(" %d ", alloc[i][j]);
        }
        printf("\t");
        for (int j = 0; j < m; j++) {
            printf(" %d ", max[i][j]);
        }
        
        printf("\t");
     
            for (int j = 0; j < m; j++) {
                printf(" %d ", need[i][j]);
        
        }
        printf("\n");
    }
    
    int y = 0;
    printf("Available\n______\n");
    for (int k = 0; k < 5; k++) {
      
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    
                    for (y = 0; y < m; y++) {
                        printf(" %d ",avail[y]);
                        avail[y] += alloc[i][y];
                        
                    }
                    f[i] = 1;
                    printf("\n");
                }
            }
        }
    }
        int flag = 1;
    for(int i=0;i<n;i++) {
        if(f[i]==0) {
            flag=0;
            printf("The following system is not safe");
            break;
        }
    }

    if(flag==1) {
        printf("Following is the SAFE Sequence\n");
        for (int i = 0; i < n - 1; i++) {
            printf(" P%d ->", ans[i]+1);
        }
        printf(" P%d", ans[n - 1]+1);
    }

    return 0;
}

