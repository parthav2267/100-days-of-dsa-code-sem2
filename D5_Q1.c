#include <stdio.h>
#include <stdlib.h>

void mergeSortedArrays(int arr1[], int p, int arr2[], int q) {
    int i = 0, j = 0;
    
    while(i < p && j < q) {
        if(arr1[i] <= arr2[j]) {
            printf("%d ", arr1[i++]);
        } else {
            printf("%d ", arr2[j++]);
        }
    }
    
    while(i < p) printf("%d ", arr1[i++]);
    while(j < q) printf("%d ", arr2[j++]);
}

int main() {
    int p, q;
    
    scanf("%d", &p);
    int *log1 = (int*)malloc(p * sizeof(int));
    for(int i = 0; i < p; i++) scanf("%d", &log1[i]);
    
    scanf("%d", &q);
    int *log2 = (int*)malloc(q * sizeof(int));
    for(int i = 0; i < q; i++) scanf("%d", &log2[i]);
    
    mergeSortedArrays(log1, p, log2, q);
    
    free(log1);
    free(log2);
    
    return 0;
}
