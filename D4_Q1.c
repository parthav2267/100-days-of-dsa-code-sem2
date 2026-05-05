#include <stdio.h>
#include <stdlib.h>

void reverseArray(int arr[], int n) {
    int left = 0;
    int right = n - 1;
    int temp;
    
    while(left < right) {
      temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
                left++;
        right--;
    }
}

int main() {
    int n;
        scanf("%d", &n);
        int *arr = (int*)malloc(n * sizeof(int));
        for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
        reverseArray(arr, n);
        for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
        free(arr);
    
    return 0;
}
