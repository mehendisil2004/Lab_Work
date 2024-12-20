#include <stdio.h>

#define rows 4
#define cols 5

void nonzero(int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        int count = 0;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
        printf("Row %d has %d non-zero elements.\n", i + 1, count);
    }
}

int main() {
    int matrix[rows][cols] = {
        {0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0},
        {0, 3, 0, 0, 0},
        {1, 0, 0, 0, 0}
    };

    nonzero(matrix);

    return 0;
}
