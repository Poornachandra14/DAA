#include <stdio.h>
#include <math.h>

// Function to print a subset
void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

// Function to generate all subsets of an array
void generateSubsets(int arr[], int n) {
    int totalSubsets = pow(2, n);

    for (int i = 0; i < totalSubsets; i++) {
        printf("Subset %d: ", i + 1);

        int subset[n];
        int subsetSize = 0;

        // Check each bit in the binary representation
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) > 0) {
                subset[subsetSize] = arr[j];
                subsetSize++;
            }
        }

        printSubset(subset, subsetSize);
    }
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Generate and print all subsets
    generateSubsets(arr, n);

    return 0;
}
