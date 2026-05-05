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
void deleteFirstOccurrence(struct Node** head, int key) {
    if (*head == NULL) {
        return;
    }
        if ((*head)->data == key) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
        struct Node* current = *head;
    struct Node* prev = NULL;
    
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }
        if (current != NULL) {
        prev->next = current->next;
        free(current);
    }
}
void display(struct Node* head) {
    if (head == NULL) {
        return;
    }
    
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
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
    int n, key;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insertEnd(&head, value);
    }
        scanf("%d", &key);
        deleteFirstOccurrence(&head, key);
        display(head);
    freeList(&head);
    
    return 0;
}
