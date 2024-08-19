#include <stdio.h>

int main() {
    int arr[10];
    int new_arr[8];
    int i, j = 0;

    printf("Enter 10 elements:\n");
    for(i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < 10; i++) {
        if(i != 2 && i != 5) {
            new_arr[j] = arr[i];
            j++;
        }
    }

    printf("The 5th element is: %d\n", new_arr[4]);

    return 0;
}
