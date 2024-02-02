#include <stdio.h>

// Recursive function to find the reverse of a number
int reverseNumber(int num) {
    static int reversed = 0;

    if (num != 0) {
        reversed = reversed * 10 + num % 10;
        reverseNumber(num / 10);
    }

    return reversed;
}

int main() {
    int num;

    // Input the number
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) {
        // Check if the input is a valid number
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    // Find and display the reverse of the number
    int reversed = reverseNumber(num);
    printf("The reverse of %d is: %d\n", num, reversed);

    return 0;
}
