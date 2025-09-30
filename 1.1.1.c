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
    
    // Print the input array
    printf("[");
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i != n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    
    // Find the maximum element
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Print the maximum element
    printf("%d\n", max);
    
    return 0;
}
