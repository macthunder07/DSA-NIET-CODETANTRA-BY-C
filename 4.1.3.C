#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

void push(Stack *s, int val) {
    if (s->top < MAX - 1) {
        s->top++;
        s->arr[s->top] = val;
    }
}

int pop(Stack *s) {
    if (s->top == -1) return -1; // empty stack
    int val = s->arr[s->top];
    s->top--;
    return val;
}

int peek(Stack *s) {
    if (s->top == -1) return -1; // empty stack
    return s->arr[s->top];
}

// Queue using two stacks
typedef struct {
    Stack s1;
    Stack s2;
} Queue;

void enqueue(Queue *q, int val) {
    push(&q->s1, val);
}

void dequeue(Queue *q) {
    if (q->s2.top == -1) { // transfer all from s1 to s2 if s2 is empty
        while (q->s1.top != -1) {
            int val = pop(&q->s1);
            push(&q->s2, val);
        }
    }
    if (q->s2.top != -1) pop(&q->s2);
}

void display(Queue *q) {
    // Print elements in s2 from top to bottom
    int first = 1;
    for (int i = q->s2.top; i >= 0; i--) {
        if (!first) printf(" ");
        printf("%d", q->s2.arr[i]);
        first = 0;
    }
    // Print elements in s1 from bottom to top
    for (int i = 0; i <= q->s1.top; i++) {
        if (!first) printf(" ");
        printf("%d", q->s1.arr[i]);
        first = 0;
    }
    if (first) printf("Empty"); // queue empty
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    Queue q;
    q.s1.top = -1;
    q.s2.top = -1;

    for (int i = 0; i < n; i++) {
        int op, val;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &val);
            enqueue(&q, val);
        } else if (op == 2) {
            dequeue(&q);
        }
    }

    display(&q);

    return 0;
}
