#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
        scanf("%s", s);
    
    int len = strlen(s);
    int left = 0;
    int right = len - 1;
    int isPalindrome = 1; 
    
    while(left < right) {
        if(s[left] != s[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }
    
    if(isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
