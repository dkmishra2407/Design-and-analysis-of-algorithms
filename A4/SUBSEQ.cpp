#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> subseq(vector<int>& ans, int n, int sum, int fsum, int i, vector<int>& arr) {
    if (sum == fsum) {
        return arr;
    }

    if (i >= n) {
        return {};
    }

    arr.push_back(ans[i]);
    if (sum + ans[i] <= fsum) {
        vector<int> take = subseq(ans, n, sum + ans[i], fsum, i + 1, arr);
        if (!take.empty()) {  
            return take;
        }
    }
    // Backtrack: remove the current element
    arr.pop_back();

    // Exclude the current element from the subsequence and continue
    return subseq(ans, n, sum, fsum, i + 1, arr);
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
    vector<int> result = subseq(ans, n, 0, fsum, 0, arr);

    if (!result.empty()) {
        cout << "Subsequence with the required sum: ";
        for (int x : result) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        cout << "No subsequence found with the required sum." << endl;
    }

    return 0;
}
