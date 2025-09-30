#include <stdio.h>

int main() {
    int rows, cols;
    
    // Read number of rows and columns
    scanf("%d %d", &rows, &cols);
    
    int arr[rows][cols];
    
    // Read elements to populate the 2D array
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    // Print row-major order
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);  // space after every element
        }
        printf("\n");
    }
    
    // Print column-major order
    for(int j = 0; j < cols; j++) {
        for(int i = 0; i < rows; i++) {
            printf("%d ", arr[i][j]);  // space after every element
        }
        printf("\n");
    }
    
    return 0;
}
