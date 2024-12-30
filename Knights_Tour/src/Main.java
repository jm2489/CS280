import java.util.Arrays;

public class Main {

    // Board
    static final int N = 8;
    static int[][] board = new int[N][N];

    // Possible moves for the knight in clockwise order.
    static final int[] row = { 1, 2, 2, 1, -1, -2, -2, -1 };
    static final int[] col = { 2, 1, -1, -2, -2, -1, 1, 2 };

    // Variable to keep track of how many dead ends occured
    static int deadEnds = 0;

    // Recursive knight's tour function
    static boolean knightsTour(int x, int y, int moveCount, int[][] board) {
        // Variable to check if there are any valid moves
        boolean hasValidMove = false;

        // Check if all squares are visited
        if (moveCount == N * N + 1) {
            return true;
        }

        // Check through all possible knight moves
        for (int i = 0; i < row.length; i++) {
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
            deadEnds++;
        }
        return false;
    }

    // Function to check if a move is valid
    static boolean isValid(int x, int y, int[][] board) {
        if (x < 0) {
            return false; // Row index is too small. It imploded.
        }
        if (x >= board.length) {
            return false; // Row index is too large. It exlploded?
        }
        if (y < 0) {
            return false; // Column index is too small. 
        }
        if (y >= board[0].length) {
            return false; // Column index is too large.
        }

        // Return false if the square is already visited
        if (board[x][y] != -9) {
            return false;
        }

        // Return true if valid
        return true;
    }

    static boolean doTour() {
        return doTour(0, 0);
    }

    static boolean doTour(int startX, int startY) {
        // Assign all squares -9 from the beginning. Any square with -9 is unvisited.
        for (int[] row : board) {
            Arrays.fill(row, -9);
        }

        // Starting position
        board[startX][startY] = 1;

        // Starting move
        int startMove = 2;

        // Start the recursive function
        if (!knightsTour(startX, startY, startMove, board)) {
            System.out.println("No solution exists for starting position: " + startX + ", " + startY);
            return false;
        }
        
        System.out.println("Solution:");
        output(board);
        return true;
    }

    // Function to print the board
    static void output(int[][] board) {
        for (int[] row : board) {
            for (int cell : row) {
                System.out.printf("%2d ", cell);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        if (args.length == 2) {
            int x = Integer.parseInt(args[0]);
            int y = Integer.parseInt(args[1]);
            doTour(x, y);
        } else {
            doTour();
        }
        System.out.println("Stats:");
        String formattedDeadEnds = String.format("%,d", deadEnds);
        System.out.println("Total Number Dead ends: " + formattedDeadEnds);
    }
}
