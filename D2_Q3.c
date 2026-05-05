#include <stdio.h>

int main() {
    int n, pos;
        printf("Enter number of elements: ");
    scanf("%d", &n);
        int arr[n];
        printf("Enter %d integers: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
        printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &pos);
        if(pos < 1 || pos > n) {
        printf("Invalid position! Position should be between 1 and %d\n", n);
        return 1;
    }
        int deleteIndex = pos - 1;
        for(int i = deleteIndex; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
        printf("Updated array: ");
    for(int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
