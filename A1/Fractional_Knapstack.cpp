#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void heapify(vector<vector<int>>& matrix, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Use floating-point division for accurate profit-to-weight ratio comparison
    if (left < n && (double)matrix[largest][0] / matrix[largest][1] < (double)matrix[left][0] / matrix[left][1]) {
        largest = left;
    }
    if (right < n && (double)matrix[largest][0] / matrix[largest][1] < (double)matrix[right][0] / matrix[right][1]) {
        largest = right;
    }

    if (largest != i) {
        swap(matrix[i], matrix[largest]);
        heapify(matrix, n, largest);
    }
}

void heapsort(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Build the heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(matrix, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(matrix[0], matrix[i]); // Move current root to the end
        heapify(matrix, i, 0); // Re-heapify with reduced size
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> matrix(n, vector<int>(2));

        // Input profit and weight for each item
        for (int i = 0; i < n; i++) {
            cin >> matrix[i][0] >> matrix[i][1];
        }

        int w;
        cin >> w;

        // Sort the items by profit-to-weight ratio using heapsort
        heapsort(matrix);

        double profit = 0.0;
        vector<double> ans;

        // Calculate maximum profit
        for (int i = n - 1; i >= 0; i--) { // Start from the highest ratio
            if (w <= 0) {
                break;
            }
            if (w >= matrix[i][1]) {
                // Take the whole item
                w -= matrix[i][1];
                profit += matrix[i][0];
                ans.push_back(matrix[i][0]);
            } else {
                // Take a fraction of the item
                profit += (double)matrix[i][0] * w / matrix[i][1];
                ans.push_back((double)matrix[i][0] * w / matrix[i][1]);
                break;
            }
        }

        // Output total profit and chosen fractions
        cout << fixed << setprecision(2) << profit << endl;

        for (double p : ans) {
            cout << fixed << setprecision(2) << p << " ";
        }
        cout << endl;
    }
    return 0;
}
