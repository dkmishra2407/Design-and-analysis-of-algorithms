#include <vector>
#include <cmath>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<std::string>> ans; // To store the final board configurations

    // Function to check if a queen can be placed at (row, col)
    bool place(std::vector<int>& s, int col, int row) {
        for (int j = 0; j < row; j++) {
            // Check for column and diagonal conflicts
            if (s[j] == col || abs(s[j] - col) == abs(j - row)) {
                return false;
            }
        }
        return true;
    }

    // Backtracking function to place queens
    void nqueen(std::vector<int>& s, int n, int row) {
        if (row == n) {
            // A valid configuration is found, convert it to the board format
            std::vector<std::string> board(n, std::string(n, '.'));
            for (int i = 0; i < n; i++) {
                board[i][s[i]] = 'Q'; // Place the queen
            }
            ans.push_back(board); // Store the valid configuration
            return;
        }

        for (int col = 0; col < n; col++) {
            if (place(s, col, row)) {
                s[row] = col; // Place the queen
                nqueen(s, n, row + 1); // Move to the next row
                // No need to reset s[row] because it will be overwritten in the next iteration
            }
        }
    }

    // Main function to initiate the N-Queens solving
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<int> store_col(n, 0); // To store the column positions of queens
        nqueen(store_col, n, 0); // Start placing queens from row 0
        return ans; // Return all valid configurations
    }
};

// Example usage
int main() {
    Solution solution;
    int n = 8; // Change this value to test with different sizes
    auto results = solution.solveNQueens(n);
    
    for (const auto& board : results) {
        for (const auto& row : board) {
            std::cout << row << std::endl;
        }
        std::cout << std::endl; // Separate different solutions
    }

    return 0;
}


// SOLUTION 2


// void addSolution ( vector<vector<int> > &ans, vector < vector < int> > &board, int n ){

// 	vector<int> temp;

// 	for ( int i = 0; i<n ; i++){
// 		for ( int j = 0; j<n ; j++){
// 			temp.push_back(board[i][j]);
// 		}
// 	}
// 	ans.push_back(temp);
// } 

// bool isSafe ( int row , int col , vector<vector<int> > &board , int n){

// 	int x = row ;
// 	int y = col ;



// 	while ( y>=0){
// 		if( board [x][y] == 1)
// 			return false;
// 		y--;
// 	}

// 	x = row ;
// 	y = col ;
	
// 	while ( x>= 0 && y>=0){
// 		if( board [x][y] == 1)
// 			return false;
	
// 		y--;
// 		x--;
// 	}

// 	x = row ;
// 	y = col ;

// 	while ( x<n && y>=0 ){
// 		if( board [x][y] == 1)
// 			return false;
	
// 		y--;
// 		x++;
// 	}

// 	return true;
// }

// void solve(int col,vector<vector<int> > &ans,vector<vector<int> > &board , int n){


// 	if( col == n ){
// 		addSolution (  ans , board, n);
// 		return ;
// 	}

	

// 	for ( int row = 0 ; row < n ; row++){
// 		if( isSafe (row , col ,board , n)){
// 			// place queen if safe
// 			board[row][col] = 1;
// 			solve(col+1 , ans , board , n);
// 			board[row][col] = 0;
// 		}
// 	}
// }

// vector<vector<int>> nQueens(int n)
// {

	
// 	vector < vector < int> > board (n , vector <int> ( n , 0));
// 	vector < vector < int> > ans;

// 	solve( 0 , ans , board , n);
// 	return ans;
// }