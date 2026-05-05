#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort
int compare(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    return x[0] - y[0]; // sort by start time
}

// Min Heap functions
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void push(int heap[], int *size, int val) {
    heap[*size] = val;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

int pop(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return root;
}

int peek(int heap[]) {
    return heap[0];
}

// Main function
int minMeetingRooms(int intervals[][2], int n) {
    // Sort by start time
    qsort(intervals, n, sizeof(intervals[0]), compare);

    int heap[n];  // min heap of end times
    int size = 0;

    // Add first meeting
    push(heap, &size, intervals[0][1]);

    for (int i = 1; i < n; i++) {
        // If earliest meeting ends before current starts
        if (intervals[i][0] >= peek(heap)) {
            pop(heap, &size); // reuse room
        }
        push(heap, &size, intervals[i][1]);
    }

    return size;
}

int main() {
    int n;
    scanf("%d", &n);

    int intervals[n][2];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    printf("%d\n", minMeetingRooms(intervals, n));

    return 0;
}
