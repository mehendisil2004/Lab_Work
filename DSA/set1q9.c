#include <stdio.h>

int getIndex(int row, int col, int numCols) {
    return row * numCols + col;
}

int main() {
    int rows = 3, cols = 4;
    int array[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int oneDArray[rows * cols];

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