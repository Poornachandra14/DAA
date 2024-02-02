#include <stdio.h>
#include <limits.h>

void findFirstTwoMin(int arr[], int size) {
    if (size < 2) {
        printf("Array should have at least two elements.\n");
        return;
    }

    int firstMin = INT_MAX;
    int secondMin = INT_MAX;

    for (int i = 0; i < size; i++) {
        if (arr[i] < firstMin) {
            secondMin = firstMin;
            firstMin = arr[i];
        } else if (arr[i] < secondMin && arr[i] != firstMin) {
            secondMin = arr[i];
        }
    }

    if (secondMin == INT_MAX) {
        printf("There are less than two distinct values in the array.\n");
    } else {
        printf("First minimum value: %d\n", firstMin);
        printf("Second minimum value: %d\n", secondMin);
    }
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findFirstTwoMin(arr, n);

    return 0;
}
