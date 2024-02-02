#include <stdio.h>

int binarySearch(int nums[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

       
        if (nums[mid] == target) {
            return mid;
        }

       
        if (target < nums[mid]) {
            right = mid - 1;
        }

       
        else {
            left = mid + 1;
        }
        
    }

    
    return -1;
}

int main() {
    int n, target;

    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int nums[n];

    
    printf("Enter the sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

  
    printf("Enter the target value: ");
    scanf("%d", &target);

   
    int result = binarySearch(nums, 0, n - 1, target);

    if (result != -1) {
        printf("Target %d found at index %d.\n", target, result);
    } else {
        printf("Target %d not found in the array,index is -1.\n",target );
    }

    return 0;
}
