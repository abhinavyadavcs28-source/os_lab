#include <stdio.h>

int main() {
    int n, tq;
    scanf("%d", &n);

    int bt[n], rt[n], pr[n], ct[n], wt[n], tat[n], done[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &bt[i], &pr[i]);
        rt[i] = bt[i];
        done[i] = 0;
    }

    scanf("%d", &tq);

    int time = 0, completed = 0;

    while (completed < n) {
        int maxp = -1;

        for (int i = 0; i < n; i++) {
            if (!done[i] && pr[i] > maxp) {
                maxp = pr[i];
            }
        }

        int executed = 0;

        for (int i = 0; i < n; i++) {
            if (!done[i] && pr[i] == maxp) {
                executed = 1;
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    done[i] = 1;
                    ct[i] = time;
                    completed++;
                }
            }
        }

        if (!executed) break;
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - bt[i];
        wt[i] = tat[i] - bt[i];
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", ct[i], tat[i], wt[i]);
    }

    return 0;
}
