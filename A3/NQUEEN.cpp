#include <bits/stdc++.h>
using namespace std;

bool place(vector<int>& s, int row, int j) {
    for (int k = 0; k < row; k++) {
        // Check if the same column or same diagonal+
        if (s[k] == j || abs(s[k] - j) == abs(k - row)) {   //ROW DIFFERENCES == COL DIFFERENCES
            return false;
        }
    }
    return true;
}

void print(vector<int>& store_col, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (store_col[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void nqueen(vector<int>& store_col, int n, int row) {
    if (row == n) {
        print(store_col, n);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (place(store_col, row, i)) {
            store_col[row] = i;
            nqueen(store_col, n, row + 1);
            store_col[row] = -1; // Backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens to place: ";
    cin >> n;

    if (n <= 3) {
        cout << "INVALID NUMBER" << endl;
    } else {
        vector<int> store_col(n, -1);
        nqueen(store_col, n, 0);
    }
    return 0;
}
