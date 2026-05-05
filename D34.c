#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char **tokens, int tokensSize) {
    int stack[10000];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char *t = tokens[i];

        if (strcmp(t, "+") == 0 || strcmp(t, "-") == 0 ||
            strcmp(t, "*") == 0 || strcmp(t, "/") == 0) {
            
            int b = stack[top--];  
            int a = stack[top--];  
            if (strcmp(t, "+") == 0) 
                stack[++top] = a + b;
            else if (strcmp(t, "-") == 0) 
                stack[++top] = a - b;
            else if (strcmp(t, "*") == 0) 
                stack[++top] = a * b;
            else 
                stack[++top] = a / b;  
        }
        else {
            stack[++top] = atoi(t);
        }
    }

    return stack[top];
}

int main() {
    char *tokens1[] = {"2", "1", "+", "3", "*"};
    int size1 = 5;
    printf("Test 1: ");
    for (int i = 0; i < size1; i++) printf("%s ", tokens1[i]);
    printf("= %d\n", evalRPN(tokens1, size1));

    char *tokens2[] = {"4", "13", "5", "/", "+"};
    int size2 = 5;
    printf("Test 2: ");
    for (int i = 0; i < size2; i++) printf("%s ", tokens2[i]);
    printf("= %d\n", evalRPN(tokens2, size2));

    char *tokens3[] = {"10", "6", "2", "/", "3", "*", "-", "1", "+"};
    int size3 = 9;
    printf("Test 3: ");
    for (int i = 0; i < size3; i++) printf("%s ", tokens3[i]);
    printf("= %d\n", evalRPN(tokens3, size3));

    return 0;
}
