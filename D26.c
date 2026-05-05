#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
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
    newNode->prev = temp;
}
void displayForward(struct Node* head) {
    struct Node* temp = head;
    
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void displayBackward(struct Node* head) {
    if (head == NULL) {
        return;
    }
        struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
        while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
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
    int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insertEnd(&head, value);
    }
    displayForward(head);
        freeList(&head);
    
    return 0;
}
