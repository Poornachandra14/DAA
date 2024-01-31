#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive function to perform merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int m, n;

    // Input the number of elements in arrays nums1 and nums2
    printf("Enter the number of elements in nums1: ");
    scanf("%d", &m);

    printf("Enter the number of elements in nums2: ");
    scanf("%d", &n);

    int nums1[m], nums2[n], merged[m + n];

    // Input the elements of nums1
    printf("Enter the elements of nums1 in non-increasing order:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    // Input the elements of nums2
    printf("Enter the elements of nums2 in non-increasing order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    // Merge nums1 and nums2 into merged array
    for (int i = 0; i < m; i++) {
        merged[i] = nums1[i];
    }
    for (int i = 0; i < n; i++) {
        merged[m + i] = nums2[i];
    }

    // Perform merge sort on merged array
    mergeSort(merged, 0, m + n - 1);

    // Display the merged and sorted array
    printf("Merged and sorted array (AB): ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
