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

// Function to print the first 'n' perfect numbers
void printPerfectNumbers(int n) {
    printf("First %d perfect numbers:\n", n);

    int count = 0;
    int num = 1;

    while (count < n) {
        if (isPerfect(num)) {
            printf("%d\n", num);
            count++;
        }
        num++;
    }
}

int main() {
    int n;

    // Get user input for the number of perfect numbers to print
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Print the first 'n' perfect numbers
    printPerfectNumbers(n);

    return 0;
}
