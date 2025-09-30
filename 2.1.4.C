#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Insert at the end of Doubly Circular Linked List
void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        return;
    }

    struct Node* last = (*head)->prev;
    newNode->next = *head;
    newNode->prev = last;
    last->next = newNode;
    (*head)->prev = newNode;
}

// Delete the last element
void deleteLast(struct Node** head) {
    if (*head == NULL) return;

    // Only one node
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* last = (*head)->prev;
    struct Node* secondLast = last->prev;

    secondLast->next = *head;
    (*head)->prev = secondLast;

    free(last);
}

// Traverse and print the list
void traverse(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int op, val;
        scanf("%d", &op);

        if (op == 1) {
            scanf("%d", &val);
            insert(&head, val);
        } else if (op == 2) {
            deleteLast(&head);
        }
    }

    traverse(head);
    return 0;
}
