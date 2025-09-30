#include <stdio.h>

int main() {
    int rows, cols;
    
    // Read number of rows and columns
    scanf("%d %d", &rows, &cols);
    
    int matrix[rows][cols];
    int zero_count = 0;
    int total_elements = rows * cols;
    
    // Read elements and count zeros
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j] == 0) {
                zero_count++;
            }
        }
    }
    
    // Check if the matrix is sparse
    if(zero_count > total_elements - zero_count) {
        printf("True\n");
        // Print non-zero elements with their positions
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] != 0) {
                    printf("%d %d %d\n", i, j, matrix[i][j]); // row column value
                }
            }
        }
    } else {
        printf("False\n");
    }
    
    return 0;
}
