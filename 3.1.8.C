#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);

    // Minimum moves = 2^N - 1
    int minMoves = (1 << N) - 1;  // Using bit shift instead of pow for integer precision
    printf("%d\n", minMoves);

    return 0;
}
