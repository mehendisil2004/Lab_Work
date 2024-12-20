#include <stdio.h>

struct Element {
    int row;
    int col;
    int value;
};

int add(struct Element mat1[], int len1, struct Element mat2[], int len2, struct Element result[]) {
    int i = 0, j = 0, k = 0;

    while (i < len1 && j < len2) {
        if (mat1[i].row < mat2[j].row || (mat1[i].row == mat2[j].row && mat1[i].col < mat2[j].col)) {
            result[k++] = mat1[i++];
        } else if (mat2[j].row < mat1[i].row || (mat2[j].row == mat1[i].row && mat2[j].col < mat1[i].col)) {
            result[k++] = mat2[j++];
        } else {
            result[k] = mat1[i];
            result[k].value = mat1[i].value + mat2[j].value;

            if (result[k].value != 0) {
                k++;
            }

            i++;
            j++;
        }
    }

    while (i < len1) {
        result[k++] = mat1[i++];
    }

    while (j < len2) {
        result[k++] = mat2[j++];
    }

    return k;  
}

void print(struct Element mat[], int len) {
    for (int i = 0; i < len; i++) {
        printf("Row: %d, Col: %d, Value: %d\n", mat[i].row, mat[i].col, mat[i].value);
    }
}

int main() {
    int len1, len2;

    printf("Enter the number of non-zero elements in the first matrix: ");
    scanf("%d", &len1);
    struct Element mat1[len1];
    for (int i = 0; i < len1; i++) {
        printf("Enter row, column, and value for element %d: ", i + 1);
        scanf("%d %d %d", &mat1[i].row, &mat1[i].col, &mat1[i].value);
    }

    printf("Enter the number of non-zero elements in the second matrix: ");
    scanf("%d", &len2);
    struct Element mat2[len2];
    for (int i = 0; i < len2; i++) {
        printf("Enter row, column, and value for element %d: ", i + 1);
        scanf("%d %d %d", &mat2[i].row, &mat2[i].col, &mat2[i].value);
    }

    struct Element result[len1 + len2];
    int lenResult = add(mat1, len1, mat2, len2, result);

    printf("Resulting Sparse Matrix:\n");
    print(result, lenResult);

    return 0;
}
