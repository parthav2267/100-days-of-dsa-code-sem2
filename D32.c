#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack->top++;
    stack->arr[stack->top] = value;
    printf("Pushed: %d\n", value);
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    int value = stack->arr[stack->top];
    stack->top--;
    printf("Popped: %d\n", value);
    return value;
}

void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack elements (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->arr[stack->top];
}

int main() {
    struct Stack stack;
    initStack(&stack);
    
    int n, m, value;
    
    printf("Enter number of elements to push: ");
    scanf("%d", &n);
    
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(&stack, value);
    }
    
    display(&stack);
    
    printf("\nEnter number of elements to pop: ");
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        pop(&stack);
    }
    
    printf("\nAfter popping %d elements:\n", m);
    display(&stack);
    
    return 0;
}
