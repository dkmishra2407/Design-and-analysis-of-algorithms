#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Recursive function for knapsack with memoization
int knap(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int w) {
    int n = matrix.size();
    if (i >= n || w == 0) {
        return 0;
    }
    if (dp[i][w] != -1) {
        return dp[i][w];
    }
    int non_take = knap(matrix, dp, i + 1, w);
    int take = 0;
    if (w >= matrix[i][1]) {
        take = matrix[i][0] + knap(matrix, dp, i + 1, w - matrix[i][1]);
    }

    return dp[i][w] = max(take, non_take);
}

// Tabulation (bottom-up) approach for knapsack
int tab(vector<vector<int>>& matrix, int n, int w) {
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    // Fill the dp table iteratively
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= w; ++j) {
            // If we don't take the current item
            dp[i][j] = dp[i - 1][j];

            // If we take the current item (and if the weight allows)
            if (j >= matrix[i - 1][1]) {
                dp[i][j] = max(dp[i][j], matrix[i - 1][0] + dp[i - 1][j - matrix[i - 1][1]]);
            }
        }
    }

    // The answer will be at dp[n][w]
    return dp[n][w];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(2));
        for (ll i = 0; i < n; i++) {
            cin >> matrix[i][0] >> matrix[i][1];  // matrix[i][0] is value, matrix[i][1] is weight
        }
        int w;
        cin >> w;

        // Choose which approach to use: memoization (recursive) or tabulation (iterative)
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));  // For memoization
        // Use knap for memoization
        cout << knap(matrix, dp, 0, w) << endl;

        // Or use tabulation (bottom-up approach)
        cout << tab(matrix, n, w) << endl;
    }
    return 0;
}
