#include <stdio.h>

void printArray(int arr[], int size, int pass) {
    printf("Pass %d: ", pass);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    int i, key, j, pass = 1;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printArray(arr, n, pass++);
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx, pass = 1;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        printArray(arr, n, pass++);
    }
}

void bubbleSort(int arr[], int n) {
    int i, j, pass = 1;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        printArray(arr, n, pass++);
    }
}

int partition(int arr[], int low, int high, int n, int *pass) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    printArray(arr, n, (*pass)++);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int n, int *pass) {
    if (low < high) {
        int pi = partition(arr, low, high, n, pass);
        quickSort(arr, low, pi - 1, n, pass);
        quickSort(arr, pi + 1, high, n, pass);
    }
}
void merge(int arr[], int l, int m, int r, int n, int *pass) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    printArray(arr, n, (*pass)++);
}

void mergeSort(int arr[], int l, int r, int n, int *pass) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, n, pass);
        mergeSort(arr, m + 1, r, n, pass);
        merge(arr, l, m, r, n, pass);
    }
}

void heapify(int arr[], int n, int i, int *pass) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest, pass);
    }
}

void heapSort(int arr[], int n) {
    int pass = 1;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, &pass);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        printArray(arr, n, pass++);
        heapify(arr, i, 0, &pass);
    }
}

int main() {
    int arr[100], n, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n--- Sorting Menu ---\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Quick Sort\n");
        printf("5. Merge Sort\n");
        printf("6. Heap Sort\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int tempArr[100]; 
        for (int i = 0; i < n; i++) {
            tempArr[i] = arr[i];
        }

        int pass = 1;

        switch (choice) {
            case 1:
                printf("Insertion Sort:\n");
                insertionSort(tempArr, n);
                break;
            case 2:
                printf("Selection Sort:\n");
                selectionSort(tempArr, n);
                break;
            case 3:
                printf("Bubble Sort:\n");
                bubbleSort(tempArr, n);
                break;
            case 4:
                printf("Quick Sort:\n");
                quickSort(tempArr, 0, n - 1, n, &pass);
                break;
            case 5:
                printf("Merge Sort:\n");
                mergeSort(tempArr, 0, n - 1, n, &pass);
                break;
            case 6:
                printf("Heap Sort:\n");
                heapSort(tempArr, n);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 7);

    return 0;
}