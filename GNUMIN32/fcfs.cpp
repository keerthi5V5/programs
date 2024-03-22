#include <stdio.h>
int main() {
    int n, bt[10], wt[10], tat[10], i ,totalwt=0 ,totaltat=0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        totalwt+=wt[i];
    }
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        totaltat+=tat[i];
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    float avg_waiting_time = (float)totalwt / n;
    float avg_turnaround_time = (float)totaltat / n;
    printf("\nAverage Waiting Time= %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time= %.2f\n", avg_turnaround_time);
    return 0;
}
