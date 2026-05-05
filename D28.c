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
        newNode->next = *head;  
        return;
    }
        struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
        temp->next = newNode;
    newNode->next = *head;  
}
void display(struct Node* head) {
    if (head == NULL) {
        return;
    }
    
    struct Node* temp = head;
        do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("\n");
}
void displayLimit(struct Node* head, int n) {
    if (head == NULL) {
        return;
    }
    
    struct Node* temp = head;
    for (int i = 0; i < n && temp != NULL; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
        if (temp == head) break; 
    }
    printf("\n");
}
void freeList(struct Node** head) {
    if (*head == NULL) return;
    
    struct Node* current = *head;
    struct Node* temp;
        while (current->next != *head) {
        temp = current;
        current = current->next;
        free(temp);
    }
        free(current);
    *head = NULL;
}
int getLength(struct Node* head) {
    if (head == NULL) return 0;
    
    int length = 0;
    struct Node* temp = head;
    
    do {
        length++;
        temp = temp->next;
    } while (temp != head);
    
    return length;
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
        display(head);
        freeList(&head);
    
    return 0;
}
