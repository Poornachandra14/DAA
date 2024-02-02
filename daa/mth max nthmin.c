#include <stdio.h>

void findMaxMin(int arr[], int size, int m, int n, int *max, int *min) {
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

   
    *max = arr[size - m];
    *min = arr[n - 1];
}

int main() {
    int size, m, n;
    
    
    do {
        printf("Enter the size of the array (should be greater than 1): ");
        scanf("%d", &size);
    } while (size <= 1);

    
    int arr[size];
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

   
    do {
        printf("Enter the value of m (1 <= m <= %d): ", size);
        scanf("%d", &m);
    } while (m < 1 || m > size);

    do {
        printf("Enter the value of n (1 <= n <= %d): ", size);
        scanf("%d", &n);
    } while (n < 1 || n > size);

    int max, min;

    
    findMaxMin(arr, size, m, n, &max, &min);

   
    int sum = max + min;
    int diff = max - min;

    printf("The %dth maximum number is: %d\n", m, max);
    printf("The %dth minimum number is: %d\n", n, min);
    printf("Sum of the %dth maximum and %dth minimum numbers: %d\n", m, n, sum);
    printf("Difference between the %dth maximum and %dth minimum numbers: %d\n", m, n, diff);

    return 0;
}
