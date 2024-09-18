// #include <vector>
// #include <cmath>
// #include <iostream>

// using namespace std;

// vector<vector<string>> ans;

// bool place(const vector<int>& s, int col, int row) {
//     for (int j = 0; j < row; j++) {
//         if (s[j] == col || abs(s[j] - col) == abs(j - row)) {
//             return false;
//         }
//     }
//     return true;
// }

// void nqueen(vector<int>& s, int n, int row) {
//     if (row == n) {
//         vector<string> board(n, string(n, '.'));
//         for (int i = 0; i < n; i++) {
//             board[i][s[i]] = 'Q';
//         }
//         ans.push_back(board);
//         return;
//     }

//     for (int col = 0; col < n; col++) {
//         if (place(s, col, row)) {
//             s[row] = col;
//             nqueen(s, n, row + 1);
//         }
//     }
// }

// vector<vector<string>> solveNQueens(int n) {
//     vector<int> store_col(n, 0);
//     nqueen(store_col, n, 0);
//     return ans;
// }

// int main() {
//     int n = 8;
//     auto results = solveNQueens(n);
    
//     for (const auto& board : results) {
//         for (const auto& row : board) {
//             cout << row << endl;
//         }
//         cout << endl;
//     }

//     return 0
// }
    
    bool isSafe(vector<vector<bool>> &board, int n, int r, int c) {
        for (int i = 0; i < r; i++)
            if (board[i][c]) return false;
        for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
            if (board[i][j]) return false;
        for (int i = r, j = c; i >= 0 && j < n; i--, j++)
            if (board[i][j]) return false;
        return true;
    }
    
    void find_positions(vector<vector<bool>> &board, vector<int> &queen_positions, vector<vector<int>> &ans, int n, int r) {
        if (r == n) {
            ans.push_back(queen_positions);
            return;
        }
    
        for (int c = 0; c < n; c++) {
            if (isSafe(board, n, r, c)) {
                board[r][c] = true;
                queen_positions.push_back(c + 1);
                find_positions(board, queen_positions, ans, n, r + 1);
                queen_positions.pop_back();
                board[r][c] = false;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        vector<vector<int>> ans;
        vector<int> queen_positions;
    
        find_positions(board, queen_positions, ans, n, 0);
    
        return ans;
    }

// SOLUTION 2

// #include <vector>
// #include <cmath>
// #include <iostream>

// using namespace std;

// vector<vector<string>> ans; // To store the final board configurations

// // Function to check if a queen can be placed at (row, col)
// bool place(const vector<int>& s, int col, int row) {
//     for (int j = 0; j < row; j++) {
//         // Check for column and diagonal conflicts
//         if (s[j] == col || abs(s[j] - col) == abs(j - row)) {
//             return false; // Conflict found
//         }
//     }
//     return true; // No conflicts
// }

// // Backtracking function to place queens
// void nqueen(vector<int>& s, int n, int row) {
//     if (row == n) {
//         // A valid configuration is found, convert it to the board format
//         vector<string> board(n, string(n, '.'));
//         for (int i = 0; i < n; i++) {
//             board[i][s[i]] = 'Q'; // Place the queen
//         }
//         ans.push_back(board); // Store the valid configuration
//         return; // Backtrack to explore other configurations
//     }

//     for (int col = 0; col < n; col++) {
//         if (place(s, col, row)) { // Check if placing queen is valid
//             s[row] = col; // Place the queen at (row, col)
//             nqueen(s, n, row + 1); // Move to the next row (backtracking step)
//             // After returning from recursion, we backtrack:
//             // We do not need to reset s[row] because it will be overwritten in the next iteration
//         }
//         // If placing the queen at (row, col) didn't lead to a solution,
//         // the loop continues to try the next column.
//     }
// }

// // Main function to initiate the N-Queens solving
// vector<vector<string>> solveNQueens(int n) {
//     vector<int> store_col(n, 0); // To store the column positions of queens
//     nqueen(store_col, n, 0); // Start placing queens from row 0
//     return ans; // Return all valid configurations
// }

// // Example usage
// int main() {
//     int n = 8; // Change this value to test with different sizes
//     auto results = solveNQueens(n);
    
//     for (const auto& board : results) {
//         for (const auto& row : board) {
//             cout << row << endl;
//         }
//         cout << endl; // Separate different solutions
//     }

//     return 0;
// }
