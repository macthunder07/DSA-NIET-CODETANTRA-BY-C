#include <stdio.h>

int main() {
    int n;
    
    // Read the size of the array
    scanf("%d", &n);
    
    int arr[n];
    
    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Print the array in reversed order
    printf("[");
    for(int i = n - 1; i >= 0; i--) {
        printf("%d", arr[i]);
        if(i != 0) {
            printf(", ");
        }
    }
    printf("]\n");
    
    return 0;
}
