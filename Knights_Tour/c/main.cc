#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Board
#define N 8
int board[N][N];

// Possible moves for the knight in clockwise order.
const int row[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
const int col[] = { 2, 1, -1, -2, -2, -1, 1, 2 };

// Variable to keep track of how many dead ends occurred
int deadEnds = 0;

// Function to check if a move is valid
int isValid(int x, int y, int board[N][N]) {
    if (x < 0 || x >= N || y < 0 || y >= N) {
        return 0; // Out of bounds
    }

    // Return 0 if the square is already visited
    if (board[x][y] != -9) {
        return 0;
    }

    // Return 1 if valid
    return 1;
}

// Function to print the board
void outputSolution(int board[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

// Recursive knight's tour function
int knightsTour(int x, int y, int moveCount, int board[N][N]) {
    // Variable to check if there are any valid moves
    int hasValidMove = 0;

    // Check if all squares are visited
    if (moveCount == N * N + 1) {
        return 1;
    }

    // Check through all possible knight moves
    for (int i = 0; i < 8; ++i) {
        int nextX = x + row[i];
        int nextY = y + col[i];

        if (isValid(nextX, nextY, board)) {
            board[nextX][nextY] = moveCount;
            hasValidMove = 1;

            // Recursively solve the tour from the new current position
            if (knightsTour(nextX, nextY, moveCount + 1, board)) {
                return 1;
            }

            // Undo the move if it leads to a dead end
            board[nextX][nextY] = -9;
        }
    }

    // Increment the dead ends counter if there are no valid moves
    if (!hasValidMove) {
        ++deadEnds;
    }
    return 0;
}

int doTour(int startX, int startY) {
    // Assign all squares -9 from the beginning. Any square with -9 is unvisited.
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            board[i][j] = -9;
        }
    }

    // Starting position
    board[startX][startY] = 1;

    // Starting move
    int startMove = 2;

    // Start the recursive function
    if (!knightsTour(startX, startY, startMove, board)) {
        printf("No solution exists for starting position: %d, %d\n", startX, startY);
        return 0;
    }

    printf("Solution:\n");
    outputSolution(board);
    return 1;
}

int main(int argc, char* argv[]) {
    int x = 0, y = 0;

    if (argc == 3) {
        x = atoi(argv[1]);
        y = atoi(argv[2]);
    }

    doTour(x, y);

    printf("Stats:\n");
    printf("Total Number of Dead Ends: %d\n", deadEnds);
    printf("Link to my GitHub repo for CS280: https://github.com/jm2489/CS280\n");

    return 0;
}
