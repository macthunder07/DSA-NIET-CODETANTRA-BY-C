#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Detect loop using Floyd’s Cycle-Finding Algorithm
bool hasLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }
    return false;
}

int main() {
    int N;
    scanf("%d", &N);

    struct Node* head = NULL;
    struct Node* tail = NULL;
    struct Node* nodes[N+1]; // store node pointers for creating loop

    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        nodes[i+1] = newNode; // position starts from 1

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int X; // position to create loop
    scanf("%d", &X);

    if (X != 0) {
        tail->next = nodes[X]; // connect tail to Xth node
    }

    if (hasLoop(head)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
