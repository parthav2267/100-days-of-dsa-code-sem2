#include <stdio.h>
#include <stdlib.h>

// Compare function for sorting
int compare(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    return x[0] - y[0]; // sort by start time
}

int main() {
    int n;
    scanf("%d", &n);

    int intervals[n][2];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    // Step 1: Sort intervals
    qsort(intervals, n, sizeof(intervals[0]), compare);

    // Result array
    int result[n][2];
    int idx = 0;

    // Add first interval
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];

    // Step 2: Merge
    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= result[idx][1]) {
            // Overlapping → merge
            if (intervals[i][1] > result[idx][1])
                result[idx][1] = intervals[i][1];
        } else {
            // Non-overlapping → new interval
            idx++;
            result[idx][0] = intervals[i][0];
            result[idx][1] = intervals[i][1];
        }
    }

    // Step 3: Print result
    for (int i = 0; i <= idx; i++) {
        printf("%d %d\n", result[i][0], result[i][1]);
    }

    return 0;
}
