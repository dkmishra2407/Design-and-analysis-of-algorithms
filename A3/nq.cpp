#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isSafe(int col,int row,vector<int>&stored_col){
    
    for(int j=0;j<row;j++){
        if(stored_col[j] == col || abs(stored_col[j] - col) == abs(j - row)){
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


void nqueen(int n,vector<int>&stored_col,int row){

    if(row == n){
        print(stored_col,n);
        return;
    }

    for(int col = 0;col < n;col++){
        if(isSafe(col,row,stored_col)){
            stored_col[row] = col;
            nqueen(n,stored_col,row+1);
            stored_col[row] = -1;
        }
    }
}
int main() {
    int n;
    cin>>n;

    vector<int> stored_col(n,-1);
    nqueen(n,stored_col,0);
    return 0;
}