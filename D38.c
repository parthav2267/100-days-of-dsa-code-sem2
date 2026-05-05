#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Deque {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
};

void initDeque(struct Deque* dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

int isEmpty(struct Deque* dq) {
    return dq->size == 0;
}

int isFull(struct Deque* dq) {
    return dq->size == MAX_SIZE;
}

int size(struct Deque* dq) {
    return dq->size;
}

void push_front(struct Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque Overflow! Cannot push %d at front\n", value);
        return;
    }
    
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    
    dq->arr[dq->front] = value;
    dq->size++;
    printf("Pushed %d at front\n", value);
}

void push_back(struct Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque Overflow! Cannot push %d at back\n", value);
        return;
    }
    
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX_SIZE;
    }
    
    dq->arr[dq->rear] = value;
    dq->size++;
    printf("Pushed %d at back\n", value);
}

int pop_front(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque Underflow! Cannot pop from front\n");
        return -1;
    }
    
    int value = dq->arr[dq->front];
    
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX_SIZE;
    }
    
    dq->size--;
    printf("Popped %d from front\n", value);
    return value;
}

int pop_back(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque Underflow! Cannot pop from back\n");
        return -1;
    }
    
    int value = dq->arr[dq->rear];
    
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    
    dq->size--;
    printf("Popped %d from back\n", value);
    return value;
}

int front(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->arr[dq->front];
}

int back(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->arr[dq->rear];
}

void clear(struct Deque* dq) {
    initDeque(dq);
    printf("Deque cleared\n");
}

void display(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    
    printf("Deque (front to rear): ");
    for (int i = 0; i < dq->size; i++) {
        int index = (dq->front + i) % MAX_SIZE;
        printf("%d ", dq->arr[index]);
    }
    printf("\n");
}

void reverse(struct Deque* dq) {
    if (isEmpty(dq) || dq->size == 1) {
        return;
    }
    
    int temp[MAX_SIZE];
    for (int i = 0; i < dq->size; i++) {
        temp[i] = dq->arr[(dq->front + i) % MAX_SIZE];
    }
    
    for (int i = 0; i < dq->size / 2; i++) {
        int t = temp[i];
        temp[i] = temp[dq->size - 1 - i];
        temp[dq->size - 1 - i] = t;
    }
    
    for (int i = 0; i < dq->size; i++) {
        dq->arr[(dq->front + i) % MAX_SIZE] = temp[i];
    }
    
    printf("Deque reversed\n");
}

void sort(struct Deque* dq) {
    if (isEmpty(dq) || dq->size == 1) {
        return;
    }
    
    int temp[MAX_SIZE];
    for (int i = 0; i < dq->size; i++) {
        temp[i] = dq->arr[(dq->front + i) % MAX_SIZE];
    }
    
    for (int i = 0; i < dq->size - 1; i++) {
        for (int j = 0; j < dq->size - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }
    
    for (int i = 0; i < dq->size; i++) {
        dq->arr[(dq->front + i) % MAX_SIZE] = temp[i];
    }
    
    printf("Deque sorted\n");
}

void resize(struct Deque* dq, int newSize) {
    if (newSize < 0 || newSize > MAX_SIZE) {
        printf("Invalid size\n");
        return;
    }
    
    if (newSize == dq->size) {
        return;
    }
    
    if (newSize < dq->size) {
        dq->size = newSize;
        if (dq->size == 0) {
            dq->front = -1;
            dq->rear = -1;
        } else {
            dq->rear = (dq->front + dq->size - 1) % MAX_SIZE;
        }
    } else {
        for (int i = dq->size; i < newSize; i++) {
            push_back(dq, 0);
        }
    }
    
    printf("Deque resized to %d\n", newSize);
}

int main() {
    struct Deque dq;
    initDeque(&dq);
    
    int choice, value, newSize;
    
    printf("=== DEQUE (Double-Ended Queue) IMPLEMENTATION ===\n");
    printf("Smaller value = Higher Priority\n\n");
    
    while (1) {
        printf("\n--- DEQUE OPERATIONS ---\n");
        printf("1. Push Front\n");
        printf("2. Push Back\n");
        printf("3. Pop Front\n");
        printf("4. Pop Back\n");
        printf("5. Front\n");
        printf("6. Back\n");
        printf("7. Size\n");
        printf("8. Empty\n");
        printf("9. Clear\n");
        printf("10. Display\n");
        printf("11. Reverse\n");
        printf("12. Sort\n");
        printf("13. Resize\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to push at front: ");
                scanf("%d", &value);
                push_front(&dq, value);
                break;
                
            case 2:
                printf("Enter value to push at back: ");
                scanf("%d", &value);
                push_back(&dq, value);
                break;
                
            case 3:
                value = pop_front(&dq);
                if (value != -1) {
                    printf("Removed: %d\n", value);
                }
                break;
                
            case 4:
                value = pop_back(&dq);
                if (value != -1) {
                    printf("Removed: %d\n", value);
                }
                break;
                
            case 5:
                value = front(&dq);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
                
            case 6:
                value = back(&dq);
                if (value != -1) {
                    printf("Back element: %d\n", value);
                }
                break;
                
            case 7:
                printf("Size: %d\n", size(&dq));
                break;
                
            case 8:
                if (isEmpty(&dq)) {
                    printf("Deque is empty\n");
                } else {
                    printf("Deque is not empty\n");
                }
                break;
                
            case 9:
                clear(&dq);
                break;
                
            case 10:
                display(&dq);
                break;
                
            case 11:
                reverse(&dq);
                break;
                
            case 12:
                sort(&dq);
                break;
                
            case 13:
                printf("Enter new size: ");
                scanf("%d", &newSize);
                resize(&dq, newSize);
                break;
                
            case 14:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
        
        if (choice >= 1 && choice <= 13 && choice != 10) {
            display(&dq);
        }
    }
    
    return 0;
}
