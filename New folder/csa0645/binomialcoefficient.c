#include <stdio.h>

// Function to calculate binomial coefficient using dynamic programming
int binomialCoefficient(int n, int k) {
    int C[n+1][k+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k && j <= i; j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    return C[n][k];
}

int main() {
    int n, k;

    // Input values for n and k
    printf("Enter values for n and k (separated by space): ");
    scanf("%d %d", &n, &k);

    // Check if input is valid
    if (n < 0 || k < 0 || k > n) {
        printf("Invalid input. Please enter non-negative values for n and k, and ensure k is not greater than n.\n");
        return 1;  // Exit with an error code
    }

    // Calculate and print the binomial coefficient
    printf("C(%d, %d) = %d\n", n, k, binomialCoefficient(n, k));

    return 0;
}
