#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    if(n > 0) {
        printf("%d ", arr[0]);
                for(int i = 1; i < n; i++) {
            if(arr[i] != arr[i-1]) {
                printf("%d ", arr[i]);
            }
        }
    }
    
    free(arr);
    return 0;
}
