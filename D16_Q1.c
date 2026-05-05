#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int freq[1001] = {0};  
    
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    
    for(int i = 0; i < n; i++) {
        if(freq[arr[i]] > 0) {
            printf("%d:%d ", arr[i], freq[arr[i]]);
            freq[arr[i]] = 0;  
        }
    }
    
    free(arr);
    return 0;
}
