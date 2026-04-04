#include <stdio.h>

int main()
{
    int bt[20], wt[20], tat[20];
    int i, n;
    float wtavg = 0, tatavg = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst times
    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // First process
    wt[0] = 0;
    tat[0] = bt[0];

    // Calculate waiting time and turnaround time
    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
    }

    // Calculate averages
    for(i = 0; i < n; i++)
    {
        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Display results
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", wtavg / n);
    printf("\nAverage Turnaround Time = %.2f\n", tatavg / n);

    return 0;
}