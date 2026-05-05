#include <stdio.h>

char firstNonRepeating(char *s) {
    int freq[26] = {0};

    // Count frequency
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Find first non-repeating character
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';
}

int main() {
    char s[] = "geeksforgeeks";

    char result = firstNonRepeating(s);
    printf("%c\n", result);

    return 0;
}