#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// Board
const int N = 8;
int board[N][N];

// Possible moves for the knight in clockwise order.
const int row[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
const int col[] = { 2, 1, -1, -2, -2, -1, 1, 2 };

// Variable to keep track of how many dead ends occurred
int deadEnds = 0;

// Function to check if a move is valid
bool isValid(int x, int y, int board[N][N]) {
    if (x < 0 || x >= N || y < 0 || y >= N) {
        return false; // Out of bounds
    }

    // Return false if the square is already visited
    if (board[x][y] != -9) {
        return false;
    }

    // Return true if valid
    return true;
}

// Function to print the board
void outputSolution(int board[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(2) << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Recursive knight's tour function
bool knightsTour(int x, int y, int moveCount, int board[N][N]) {
    // Variable to check if there are any valid moves
    bool hasValidMove = false;

    // Check if all squares are visited
    if (moveCount == N * N + 1) {
        return true;
    }

    // Check through all possible knight moves
    for (int i = 0; i < 8; ++i) {
        int nextX = x + row[i];
        int nextY = y + col[i];

        if (isValid(nextX, nextY, board)) {
            board[nextX][nextY] = moveCount;
            hasValidMove = true;

            // Recursively solve the tour from the new current position
            if (knightsTour(nextX, nextY, moveCount + 1, board)) {
                return true;
            }

            // Undo the move if it leads to a dead end
            board[nextX][nextY] = -9;
        }
    }

    // Increment the dead ends counter if there are no valid moves
    if (!hasValidMove) {
        ++deadEnds;
    }
    return false;
}

bool doTour(int startX = 0, int startY = 0) {
    // Assign all squares -9 from the beginning. Any square with -9 is unvisited.
    for (int i = 0; i < N; ++i) {
        fill(board[i], board[i] + N, -9);
    }

    // Starting position
    board[startX][startY] = 1;

    // Starting move
    int startMove = 2;

    // Start the recursive function
    if (!knightsTour(startX, startY, startMove, board)) {
        cout << "No solution exists for starting position: " << startX << ", " << startY << endl;
        return false;
    }

    cout << "Solution:" << endl;
    outputSolution(board);
    return true;
}

int main(int argc, char* argv[]) {
    if (argc == 3) {
        int x = stoi(argv[1]);
        int y = stoi(argv[2]);
        doTour(x, y);
    } else {
        doTour();
    }
    
    cout << "Stats:" << endl;
    cout.imbue(std::locale("")); // Formatting
    cout << "Total Number of Dead Ends: " << deadEnds << endl;
    cout << "Link to my GitHub repo for CS280: https://github.com/jm2489/CS280" << endl;

    return 0;
}
