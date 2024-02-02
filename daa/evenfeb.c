#include <stdio.h>

// Function to calculate the sum of the first 'n' even Fibonacci numbers
long long int evenFibonacciSum(int n) {
    long long int a = 0, b = 1, c = 0, sum = 0;
    int count = 0;

    while (count < n) {
        if (c % 2 == 0) {
            sum += c;
            count++;
        }

        a = b;
        b = c;
        c = a + b;
    }

    return sum;
}

int main() {
    int n;

    // Get user input for the number of even Fibonacci numbers
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Calculate and print the sum of the first 'n' even Fibonacci numbers
    long long int result = evenFibonacciSum(n);
    printf("Sum of the first %d even Fibonacci numbers: %lld\n", n, result);

    return 0;
}
