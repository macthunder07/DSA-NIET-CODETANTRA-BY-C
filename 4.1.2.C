#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int cq[MAX];
    int front = -1, rear = -1;

    for (int i = 0; i < n; i++) {
        int op, val;
        scanf("%d", &op);

        if (op == 1) { // Enqueue
            scanf("%d", &val);
            if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
                // Queue full, do nothing
            } else {
                if (front == -1) front = 0; // first element
                rear = (rear + 1) % MAX;
                cq[rear] = val;
            }
        } else if (op == 2) { // Dequeue
            if (front == -1) {
                // Queue empty, do nothing
            } else if (front == rear) {
                // Only one element
                front = rear = -1;
            } else {
                front = (front + 1) % MAX;
            }
        }
    }

    if (front == -1) {
        printf("Empty\n");
    } else {
        int i = front;
        while (1) {
            printf("%d", cq[i]);
            if (i == rear) break;
            printf(" ");
            i = (i + 1) % MAX;
        }
        printf("\n");
    }

    return 0;
}
