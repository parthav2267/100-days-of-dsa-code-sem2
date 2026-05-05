#include <stdio.h>

#define MAX 1000

int maxLenZeroSum(int arr[], int n) {
    int prefixSum = 0;
    int maxLen = 0;

    // Hash map using arrays (since constraints are small)
    int map[20001]; // to handle negative sums
    for (int i = 0; i < 20001; i++)
        map[i] = -2;  // -2 means not visited

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum is 0 from start
        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        int index = prefixSum + 10000; // shift for negative

        // Case 2: seen before
        if (map[index] != -2) {
            int len = i - map[index];
            if (len > maxLen)
                maxLen = len;
        } else {
            map[index] = i; // store first occurrence
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLenZeroSum(arr, n));

    return 0;
}