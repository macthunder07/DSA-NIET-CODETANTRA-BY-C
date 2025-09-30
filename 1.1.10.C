#include <stdio.h>

int main() {
    int n, key, found = 0;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &key);

    // Linear search
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("%d\n", i);
            found = 1;
            break;  // stop at first occurrence
        }
    }

    if (!found) {
        printf("Not found\n");
    }

    return 0;
}
