#include <stdio.h>

int main() {
    int n, pos, x;
    scanf("%d", &n);
    int arr[n+1];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &pos);
    scanf("%d", &x);
    pos = pos - 1;
    for(int i = n; i > pos; i--) {
        arr[i] = arr[i-1];
    }

    arr[pos] = x;
    
    for(int i = 0; i < n+1; i++) {
        printf("%d", arr[i]);
        if(i < n) {
            printf(" ");
        }
    }
    
    return 0;
}
