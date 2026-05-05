#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int seen[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';

        if (seen[idx] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }

        seen[idx] = 1;
    }

    printf("-1\n");
    return 0;
}