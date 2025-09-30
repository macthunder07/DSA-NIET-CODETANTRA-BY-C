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
    
    // Check if the array is sorted in ascending order
    int isSorted = 1; // assume sorted
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            isSorted = 0; // not sorted
            break;
        }
    }
    
    // Print True or False
    if(isSorted) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    
    return 0;
}
