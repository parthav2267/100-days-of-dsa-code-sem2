#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr, k, i;
    int comparisons = 0;
    int found = 0;
        scanf("%d", &n);
        arr = (int*)malloc(n * sizeof(int));
        for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
        scanf("%d", &k);
        for(i = 0; i < n; i++) {
        comparisons++;  
        if(arr[i] == k) {
            found = 1;
            break;
        }
    }
        if(found) {
        printf("Found at index %d\n", i);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);
        free(arr);
    
    return 0;
}
