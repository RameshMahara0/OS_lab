#include <stdio.h>

int main() {
    int n, i, time = 0, min, idx;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt_bt[n], wt[n], tat[n], rt[n], ct[n], started[n];

    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        rt_bt[i] = bt[i];
        started[i] = 0;
    }

    int completed = 0;

    while(completed < n) {
        min = 9999;
        idx = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt_bt[i] > 0) {
                if(rt_bt[i] < min) {
                    min = rt_bt[i];
                    idx = i;
                }
            }
        }

        if(idx == -1) {
            time++;
        } else {

            if(started[idx] == 0) {
                rt[idx] = time - at[idx];
                started[idx] = 1;
            }

            rt_bt[idx]--;
            time++;

            if(rt_bt[idx] == 0) {
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                completed++;
            }
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\tRT\n");

    float total_wt = 0, total_tat = 0, total_rt = 0;

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], wt[i], tat[i], rt[i]);

        total_wt += wt[i];
        total_tat += tat[i];
        total_rt += rt[i];
    }

    printf("\nAverage WT = %.2f", total_wt/n);
    printf("\nAverage TAT = %.2f", total_tat/n);
    printf("\nAverage RT = %.2f\n", total_rt/n);

    return 0;
}
