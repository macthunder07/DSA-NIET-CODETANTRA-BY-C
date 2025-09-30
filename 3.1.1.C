#include <stdio.h>

#define MAX 1000

int main() {
    int stack[MAX];
    int top = -1;
    int n;
    scanf("%d", &n);

    int output[MAX];
    int outputCount = 0;

    for (int i = 0; i < n; i++) {
        int op, val;
        if (scanf("%d", &op) != 1) continue;

        if (op == 1) {
            // Push operation
            scanf("%d", &val);
            if (top < MAX - 1) {
                stack[++top] = val;
            }
        } else if (op == 2) {
            // Pop operation
            if (top >= 0) {
                top--;
            }
        } else if (op == 3) {
            // Peek operation
            if (top >= 0) {
                output[outputCount++] = stack[top];
            }
        }
    }

    // Print all peek outputs
    for (int i = 0; i < outputCount; i++) {
        printf("%d\n", output[i]);
    }

    // Print final stack (top to bottom)
    if (top < 0) {
        printf("Empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            if (i < top) printf(" ");
            printf("%d", stack[i]);
        }
        printf("\n");
    }

    return 0;
}
