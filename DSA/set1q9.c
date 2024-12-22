#include <stdio.h>

int getIndex(int row, int col, int numCols) {
    return row * numCols + col;
}

int main() {
    int rows, cols;

    // Ask for the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int array[rows][cols];
    int oneDArray[rows * cols];

    // Input the 2D array from the user
    printf("Enter the elements of the 2D array:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &array[i][j]);
        }
    }

    // Convert 2D array to 1D array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            oneDArray[getIndex(i, j, cols)] = array[i][j];
        }
    }

    // Print the 1D array
    printf("1D array: ");
    for (int i = 0; i < rows * cols; i++) {
        printf("%d ", oneDArray[i]);
    }
    printf("\n");

    return 0;
}
