#include <stdio.h>
#include <stdlib.h>

// Function to print the chessboard
void printBoard(int **board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] == 1 ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if it's safe to place a queen at board[row][col]
int isSafe(int **board, int row, int col, int N) {
    // Check in the same row to the left
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return 0;
        }
    }

    // Check upper diagonal on the left
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    // Check lower diagonal on the left
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    return 1; // It's safe to place a queen at board[row][col]
}

// Recursive function to solve N-Queens problem using backtracking
void solveNQueens(int **board, int N, int col) {
    if (col == N) {
        // If all queens are placed successfully, print the board
        printBoard(board, N);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1; // Place the queen

            // Recur to place the rest of the queens
            solveNQueens(board, N, col + 1);

            // Backtrack if placing the queen at board[i][col] doesn't lead to a solution
            board[i][col] = 0;
        }
    }
}

int main() {
    int N;

    // Get user input for the size of the chessboard
    printf("Enter the size of the chessboard (N): ");
    scanf("%d", &N);

    // Allocate memory for the chessboard
    int **board = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        board[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            board[i][j] = 0; // Initialize the chessboard with zeros
        }
    }

    // Solve and print all solutions for the N-Queens problem
    solveNQueens(board, N, 0);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}
