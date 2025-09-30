#include <stdio.h>
#include <stdlib.h>

int fibonacciNumbers(int N, int *resultsArr) {
    int count = 0;

    if (N >= 0) resultsArr[count++] = 0;
    if (N >= 1) resultsArr[count++] = 1;

    int a = 0, b = 1;
    while (1) {
        int next = a + b;
        if (next > N) break;
        resultsArr[count++] = next;
        a = b;
        b = next;
    }

    return count; // number of elements
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("0\n");
        return 0;
    }

    int N = atoi(argv[1]);

    int resultsArr[100000];
    int count = fibonacciNumbers(N, resultsArr);

    for (int i = 0; i < count; i++) {
        if (i > 0) printf(",");
        printf("%d", resultsArr[i]);
    }
    printf("\n");

    return 0;
}
