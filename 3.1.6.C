#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int key;
    scanf("%d", &key);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("%d\n", i); // index in original array
            found = 1;
            break; // stop at first occurrence
        }
    }

    if (!found)
        printf("Not found\n");

    return 0;
}
