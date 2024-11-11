#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int zero_one(vector<vector<int>>& matrix, vector<vector<int>>& dp, int w, int i) {
    if (i == 0) {
        if (w >= matrix[i][1]) {
            return matrix[i][0];
        } else {
            return 0;
        }
    }

    if (dp[i][w] != -1) {
        return dp[i][w];
    }

    int non_take = zero_one(matrix, dp, w, i - 1);
    int take = 0;

    if (w >= matrix[i][1]) {
        take = matrix[i][0] + zero_one(matrix, dp, w - matrix[i][1], i - 1);
    }

    return dp[i][w] = max(take, non_take);
}

void track_selected_item(vector<vector<int>>& matrix, vector<vector<int>>& dp, int W, int n){
    vector<int> selectedItems;

    int i = n, j = W;

    while (i >= 0 && j >= 0) {
        if (i == 0 || dp[i][j] != dp[i - 1][j]) {
            selectedItems.push_back(i);
            j -= matrix[i][1]; 
        }
        i--; 
    }

    cout << "Selected items: ";
    for (int index : selectedItems) {
        cout << "Item " << index << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> matrix(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> matrix[i][j];
            }
        }

        int w;
        cin >> w;

        // Initialize dp with -1 for memoization
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));

        cout << zero_one(matrix, dp, w, n - 1) << endl;
        track_selected_item(matrix, dp, w, n - 1);
    }
    return 0;
}


// 2
// 3
// 1 4
// 2 5
// 3 6
// 3
// 3
// 60 10
// 100 20
// 120 30
// 50
