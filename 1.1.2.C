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
    
    // Calculate the sum of elements
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    // Print the sum
    printf("%d\n", sum);
    
    return 0;
}
