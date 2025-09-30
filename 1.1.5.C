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
    
    int x;
    // Read the element to search for
    scanf("%d", &x);
    
    // Count occurrences of x
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
            count++;
        }
    }
    
    // Print the count
    printf("%d\n", count);
    
    return 0;
}
