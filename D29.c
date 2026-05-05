#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
int getLength(struct Node* head) {
    int length = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void rotateRight(struct Node** head, int k) {
    if (*head == NULL || k == 0) {
        return;
    }
    
    int n = getLength(*head);
        k = k % n;
    if (k == 0) {
        return;
    }
        struct Node* current = *head;
    int count = 1;
        while (count < n - k && current != NULL) {
        current = current->next;
        count++;
    }
        struct Node* newHead = current->next;
    struct Node* newTail = current;
        struct Node* last = newHead;
    while (last->next != NULL) {
        last = last->next;
    }
        last->next = *head;
    newTail->next = NULL;
        *head = newHead;
}
void rotateRightCircular(struct Node** head, int k) {
    if (*head == NULL || k == 0) {
        return;
    }
    
    int n = getLength(*head);
    k = k % n;
    if (k == 0) {
        return;
    }
        struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
        last->next = *head;
        int stepsToNewTail = n - k - 1;
    struct Node* newTail = *head;
    for (int i = 0; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }
        struct Node* newHead = newTail->next;
        newTail->next = NULL;
        *head = newHead;
}
void freeList(struct Node** head) {
    struct Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int n, k;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insertEnd(&head, value);
    }
        scanf("%d", &k);
        rotateRight(&head, k);
        display(head);
        freeList(&head);
    
    return 0;
}
