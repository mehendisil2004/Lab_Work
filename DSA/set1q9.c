#include <stdio.h>

int main() {
    int m = 3;  
    int n = 4;  
    
    int arr1D[] = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12
    };
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int index = i * n + j;
            
            int element = arr1D[index];
            
            printf("Element at A[%d][%d] is: %d\n", i, j, element);
        }
    }
    
    return 0;
}
