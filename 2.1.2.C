#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Insert at the end of the list
void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

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

// Delete first occurrence of value
void delete(struct Node** head, int value) {
    struct Node* temp = *head;

    // Search for the node
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    // If not found
    if (temp == NULL) return;

    // If node is head
    if (temp->prev == NULL) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
}

// Traverse and print the list
void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);  // space after each element
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int op, val;
        scanf("%d %d", &op, &val);

        if (op == 1) {
            insert(&head, val);
        } else if (op == 2) {
            delete(&head, val);
        }
    }

    traverse(head);
    return 0;
}
