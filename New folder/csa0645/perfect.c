#include <stdio.h>

// Function to check if a number is perfect
int isPerfect(int num) {
    int sum = 1; // Initialize sum with 1 (since 1 is a proper divisor for all positive integers)

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i * i != num) {
                sum += num / i;
            }
        }
    }

    return (sum == num);
}

int main() {
    int num;

    // Get user input for the number
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Check if the number is perfect or not
    if (isPerfect(num)) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }

    return 0;
}
