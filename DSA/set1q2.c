#include<stdio.h>

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original list: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Reverse list: ");
    for (int j=n-1; j>=0; j--)
    {
        printf("%d ", arr[j]);
    }
    
}