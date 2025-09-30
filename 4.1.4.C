#include <stdio.h>

typedef struct {
    int value;
    int priority;
} Node;

typedef struct {
    Node arr[1000];
    int size;
} PriorityQueue;

// Enqueue: insert at the end
void enqueue(PriorityQueue *pq, int val, int prio) {
    pq->arr[pq->size].value = val;
    pq->arr[pq->size].priority = prio;
    pq->size++;
}

// Dequeue: remove element with the lowest priority
void dequeue(PriorityQueue *pq) {
    if (pq->size == 0) return;

    // find the element with the minimum priority (first occurrence)
    int idx = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->arr[i].priority < pq->arr[idx].priority) {
            idx = i;
        }
    }

    // shift elements left to remove idx
    for (int i = idx; i < pq->size - 1; i++) {
        pq->arr[i] = pq->arr[i + 1];
    }
    pq->size--;
}

// Display: sort by priority ascending, stable for equal priorities
void display(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Empty\n");
        return;
    }

    // simple stable bubble sort by priority
    for (int i = 0; i < pq->size - 1; i++) {
        for (int j = 0; j < pq->size - i - 1; j++) {
            if (pq->arr[j].priority > pq->arr[j + 1].priority) {
                Node temp = pq->arr[j];
                pq->arr[j] = pq->arr[j + 1];
                pq->arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < pq->size; i++) {
        if (i > 0) printf(" ");
        printf("%d (%d)", pq->arr[i].value, pq->arr[i].priority);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    PriorityQueue pq;
    pq.size = 0;

    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int val, prio;
            scanf("%d %d", &val, &prio);
            enqueue(&pq, val, prio);
        } else if (op == 2) {
            dequeue(&pq);
        }
    }

    display(&pq);
    return 0;
}
