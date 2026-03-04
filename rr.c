#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int at[n], bt[n], rt[n], wt[n], tat[n];
    char pname[n][5];   // to store P1, P2 etc
    int q;

    for(int i = 0; i < n; i++) {
        scanf("%s %d %d", pname[i], &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    scanf("%d", &q);

    int time = 0, remain = n;

    while(remain > 0) {
        for(int i = 0; i < n; i++) {
            if(rt[i] > 0 && at[i] <= time) {
                if(rt[i] > q) {
                    time += q;
                    rt[i] -= q;
                } else {
                    time += rt[i];
                    wt[i] = time - at[i] - bt[i];
                    tat[i] = time - at[i];
                    rt[i] = 0;
                    remain--;
                }
            }
        }
    }

    float avg_wt = 0, avg_tat = 0;

    printf("Waiting Time:\n");
    for(int i = 0; i < n; i++) {
        printf("%s %d\n", pname[i], wt[i]);
        avg_wt += wt[i];
    }

    printf("Turnaround Time:\n");
    for(int i = 0; i < n; i++) {
        printf("%s %d\n", pname[i], tat[i]);
        avg_tat += tat[i];
    }

    printf("Average Waiting Time: %.2f\n", avg_wt/n);
    printf("Average Turnaround Time: %.2f\n", avg_tat/n);

    return 0;
}
