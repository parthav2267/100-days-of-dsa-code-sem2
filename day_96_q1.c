#include <stdio.h>
#include <stdlib.h>

// Merge and count inversions
int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);  // key step
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Merge sort + count
int mergeSort(int arr[], int temp[], int left, int right) {
    int inv_count = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid, right);
    }

    return inv_count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], temp[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = mergeSort(arr, temp, 0, n - 1);

    printf("%d\n", result);

    return 0;
}
