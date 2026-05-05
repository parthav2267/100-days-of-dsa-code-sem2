#include <stdio.h>

int integerSqrt(int n) {
    int left = 0, right = n;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Avoid overflow: use mid <= n/mid
        if (mid <= n / mid) {
            ans = mid;       // valid answer
            left = mid + 1;  // try bigger
        } else {
            right = mid - 1; // go smaller
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", integerSqrt(n));

    return 0;
}
