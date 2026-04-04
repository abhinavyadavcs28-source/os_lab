#include <stdio.h>

int main() {
    int n, i, time = 0, remain, quantum;

    scanf("%d", &n);

    int bt[n], wt[n], tat[n], rt[n];
    int gantt_p[1000], gantt_t[1000], k = 0;

    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    scanf("%d", &quantum);

    remain = n;

    while(remain > 0) {
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                gantt_p[k] = i + 1;
                if(rt[i] <= quantum) {
                    time += rt[i];
                    gantt_t[k++] = time;
                    rt[i] = 0;
                    remain--;
                    tat[i] = time;
                } else {
                    time += quantum;
                    gantt_t[k++] = time;
                    rt[i] -= quantum;
                }
            }
        }
    }

    for(i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
    }
//gant chart code
    printf("\nGantt Chart:\n| ");
    for(i = 0; i < k; i++) {
        printf("P%d | ", gantt_p[i]);
    }

    printf("\n0 ");
    for(i = 0; i < k; i++) {
        printf("%d ", gantt_t[i]);
    }

    printf("\n\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    return 0;
}
