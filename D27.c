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
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;
        int diff = abs(len1 - len2);
        if (len1 > len2) {
        for (int i = 0; i < diff; i++) {
            ptr1 = ptr1->next;
        }
    } else {
        for (int i = 0; i < diff; i++) {
            ptr2 = ptr2->next;
        }
    }
        while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1;  
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return NULL;  
}
void createIntersection(struct Node** head1, struct Node** head2, int position) {
    if (*head1 == NULL) return;
        struct Node* intersectNode = *head1;
    for (int i = 0; i < position && intersectNode != NULL; i++) {
        intersectNode = intersectNode->next;
    }
    
    if (intersectNode == NULL) return;
        if (*head2 == NULL) {
        *head2 = intersectNode;
        return;
    }
    
    struct Node* last = *head2;
    while (last->next != NULL) {
        last = last->next;
    }
        last->next = intersectNode;
}
void display(struct Node* head) {
    struct Node* temp = head;
    int count = 0;
    while (temp != NULL && count < 15) {  
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
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
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n, m;
        scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        insertEnd(&list1, val);
    }
        scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        insertEnd(&list2, val);
    }
    createIntersection(&list1, &list2, 2);
        struct Node* intersection = findIntersection(list1, list2);
        printf("List 1: ");
    display(list1);
    printf("List 2: ");
    display(list2);
    
    if (intersection != NULL) {
        printf("Intersection found at node with value: %d\n", intersection->data);
    } else {
        printf("No Intersection\n");
    }
    freeList(&list1);    
    return 0;
}
