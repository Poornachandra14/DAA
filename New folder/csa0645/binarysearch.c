#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; 
}

int main() {
    int size, key;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to search for: ");
    scanf("%d", &key);
    clock_t start_time = clock();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int index = binarySearch(arr, size, key);

    clock_t end_time = clock();
    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    if (index != -1) {
        printf("Number %d found at index %d\n", key, index);
    } else {
        printf("Number %d not found in the array\n", key);
    }

   

    return 0;
}
