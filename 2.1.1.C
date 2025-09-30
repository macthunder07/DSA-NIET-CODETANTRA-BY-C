#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Insert at the end of the list
void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

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

// Delete first occurrence of value
void delete(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If head node itself holds the value
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the value
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // Value not found
    if (temp == NULL) return;

    // Unlink node
    prev->next = temp->next;
    free(temp);
}

// Print linked list (with space after every element)
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);  // always print space after number
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

    printList(head);
    return 0;
}
