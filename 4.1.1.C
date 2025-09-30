#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int queue[1000];  // assuming max 1000 elements
    int front = 0, rear = 0; // front points to first element, rear points to next free slot

    for (int i = 0; i < n; i++) {
        int op, val;
        scanf("%d", &op);

        if (op == 1) { // Enqueue
            scanf("%d", &val);
            queue[rear++] = val; // insert at rear
        } else if (op == 2) { // Dequeue
            if (front < rear) {
                front++; // remove from front
            }
            // if queue is empty, do nothing
        }
    }

    if (front == rear) {
        printf("Empty\n");
    } else {
        for (int i = front; i < rear; i++) {
            if (i > front) printf(" ");
            printf("%d", queue[i]);
        }
        printf("\n");
    }

    return 0;
}
