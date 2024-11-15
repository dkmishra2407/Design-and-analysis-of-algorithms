#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void subseq(vector<int>& ans, int n, int sum, int fsum, int i, vector<int>& arr) {
    // Base case: if the current sum equals the target, print the subsequence
    if (sum == fsum) {
        cout << "Subsequence with the required sum: ";
        for (int x : arr) {
            cout << x << " ";
        }
        cout << endl;
        return; // Continue to explore other subsequences
    }

    if (i >= n) {
        return; // Stop if we reach the end of the list
    }

    // Include the current element in the subsequence if it doesn't exceed the sum
    arr.push_back(ans[i]);
    if (sum + ans[i] <= fsum) {
        subseq(ans, n, sum + ans[i], fsum, i + 1, arr);
    }
    // Backtrack: remove the current element
    arr.pop_back();

    // Exclude the current element from the subsequence and continue
    subseq(ans, n, sum, fsum, i + 1, arr);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> ans(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> ans[i];
    }

    int fsum;
    cout << "Enter the target sum: ";
    cin >> fsum;

    vector<int> arr;
    cout << "All subsequences with the required sum:" << endl;
    subseq(ans, n, 0, fsum, 0, arr);

    return 0;
}
