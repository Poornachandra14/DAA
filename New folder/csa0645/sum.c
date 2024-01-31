#include <stdio.h>


int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int maxSumOfDigits(int nums[], int n) {
    int maxSum = -1;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sumOfDigits(nums[i]) == sumOfDigits(nums[j])) {
                int currentSum = nums[i] + nums[j];
                if (currentSum > maxSum) {
                    maxSum = currentSum;
                }
            }
        }
    }

    return maxSum;
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = maxSumOfDigits(nums, n);
    
    if (result == -1) {
        printf("No pair with equal sum of digits found.\n");
    } else {
        printf("Maximum sum of digits for two numbers is: %d\n", result);
    }

    return 0;
}
