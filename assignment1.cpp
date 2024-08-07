#include <bits/stdc++.h>
using namespace std;

// Recursive solution
int knapstack(vector<int>& values, int w, vector<int>& weight, int i) {
    if (i == 0) {
        return (w >= weight[0]) ? values[0] : 0;
    }
    int non_take = knapstack(values, w, weight, i - 1);
    int take = 0;
    if (w >= weight[i]) {
        take = values[i] + knapstack(values, w - weight[i], weight, i - 1);
    }
    return max(take, non_take);
}

// Memoized solution
int knapsackm(vector<int>& values, int w, vector<int>& weight, int i, vector<vector<int>>& dp) {
    if (i == 0) {
        return (w >= weight[0]) ? values[0] : 0;
    }
    
    if (dp[i][w] != -1) {
        return dp[i][w];
    }
    
    int non_take = knapsackm(values, w, weight, i - 1, dp);
    int take = 0;
    if (w >= weight[i]) {
        take = values[i] + knapsackm(values, w - weight[i], weight, i - 1, dp);
    }
    return dp[i][w] = max(take, non_take);
}

// Function to find selected items
void findSelectedItems(vector<vector<int>>& dp, vector<int>& weight, vector<int>& values, int n, int W) {
    vector<int> selectedItems;

    int i = n - 1, j = W;

    while (i >= 0 && j >= 0) {
        if (i == 0 || dp[i][j] != dp[i - 1][j]) {
            selectedItems.push_back(i);
            j -= weight[i]; 
        }
        i--; 
    }

    cout << "Selected items: ";
    for (int index : selectedItems) {
        cout << "Item " << index << " (Value: " << values[index] << ", Weight: " << weight[index] << ") ";
    }
    cout << endl;
}

// Main function
int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> values(n);
    vector<int> weight(n);

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }

    int w;
    cout << "Enter knapsack capacity: ";
    cin >> w;

    int max_value_recursive = knapstack(values, w, weight, n - 1);
    cout << "Maximum value that can be obtained (Recursive): " << max_value_recursive << endl;

    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    int max_value_memoized = knapsackm(values, w, weight, n - 1, dp);
    cout << "Maximum value that can be obtained (Memoized): " << max_value_memoized << endl;

    vector<vector<int>> dp1(n, vector<int>(w + 1, 0));

    for (int i = 0; i <= w; i++) {
        if (i >= weight[0]) {
            dp1[0][i] = values[0];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= w; j++) {
            int non_take = dp1[i - 1][j];
            int take = INT_MIN;

            if (j >= weight[i]) {
                take = values[i] + dp1[i - 1][j - weight[i]];
            }

            dp1[i][j] = max(take, non_take);
        }
    }

    cout << "Maximum value that can be obtained (Tabulated): " << dp1[n - 1][w] << endl;
    
    findSelectedItems(dp1, weight, values, n, w);
    
    return 0;
}