#include <stdio.h>
#include <stdlib.h>

// Structure to store an activity
typedef struct {
    int start;
    int end;
} Activity;

// Comparator to sort activities by end time
int compare(const void *a, const void *b) {
    Activity *act1 = (Activity *)a;
    Activity *act2 = (Activity *)b;
    return act1->end - act2->end;
}

int main() {
    int n;
    scanf("%d", &n);

    Activity activities[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &activities[i].start);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &activities[i].end);
    }

    // Sort activities by end time
    qsort(activities, n, sizeof(Activity), compare);

    int count = 0;
    int lastEnd = 0;

    for (int i = 0; i < n; i++) {
        if (activities[i].start > lastEnd) {
            count++;
            lastEnd = activities[i].end;
        }
    }

    printf("%d\n", count);
    return 0;
}
