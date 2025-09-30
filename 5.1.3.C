#include <stdio.h>
#include <stdlib.h>

// Structure to store job difficulty and profit
typedef struct {
    int difficulty;
    int profit;
} Job;

// Comparator to sort jobs by difficulty
int compareJobs(const void *a, const void *b) {
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    return job1->difficulty - job2->difficulty;
}

// Comparator to sort workers by ability
int compareWorkers(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Job jobs[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &jobs[i].difficulty);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &jobs[i].profit);
    }

    int workers[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &workers[i]);
    }

    // Sort jobs by difficulty
    qsort(jobs, n, sizeof(Job), compareJobs);
    // Sort workers by ability
    qsort(workers, m, sizeof(int), compareWorkers);

    int totalProfit = 0;
    int maxProfitSoFar = 0;
    int j = 0;

    for (int i = 0; i < m; i++) {
        // Move through jobs that worker can do
        while (j < n && jobs[j].difficulty <= workers[i]) {
            if (jobs[j].profit > maxProfitSoFar)
                maxProfitSoFar = jobs[j].profit;
            j++;
        }
        totalProfit += maxProfitSoFar;
    }

    printf("%d\n", totalProfit);
    return 0;
}
