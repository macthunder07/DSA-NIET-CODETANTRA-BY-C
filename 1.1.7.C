#include <stdio.h>

int main() {
    int rows, cols;
    
    // Read number of rows and columns
    scanf("%d %d", &rows, &cols);
    
    int matrix[rows][cols];
    
    // Read elements to populate the matrix
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Print original matrix
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);  // space after each element
        }
        printf("\n");
    }
    
    // Print transpose of the matrix
    for(int j = 0; j < cols; j++) {
        for(int i = 0; i < rows; i++) {
            printf("%d ", matrix[i][j]);  // space after each element
        }
        printf("\n");
    }
    
    return 0;
}
