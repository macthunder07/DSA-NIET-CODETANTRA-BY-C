#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Insert at the end of circular linked list
void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode; // initially points to itself

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

// Delete first occurrence of value
void delete(struct Node** head, int value) {
    if (*head == NULL) return;

    struct Node* curr = *head;
    struct Node* prev = NULL;

    // Case: head node itself holds the value
    if (curr->data == value) {
        // If only one node
        if (curr->next == *head) {
            free(curr);
            *head = NULL;
            return;
        }

        // Find last node to update its next pointer
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = curr->next;
        *head = curr->next;
        free(curr);
        return;
    }

    // Traverse to find the node
    prev = curr;
    curr = curr->next;
    while (curr != *head) {
        if (curr->data == value) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Print circular linked list
void printList(struct Node* head) {
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
