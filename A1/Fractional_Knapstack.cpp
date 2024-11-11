#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void heapify(vector<vector<int>>&matrix,int n,int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && matrix[largest][0]/matrix[largest][1] <  matrix[left][0]/matrix[left][1]){
        largest = left;
    }

    if(right < n && matrix[largest][0]/matrix[largest][1] <  matrix[right][0]/matrix[right][1]){
        largest = right;
    }

    if(largest != i){
        for(int j=0;j<2;j++){
            swap(matrix[largest][j],matrix[i][j]);
        }
        heapify(matrix,n,largest);
    }
}

void heapsort(vector<vector<int>>&matrix){
    int n = matrix.size();

    for(int i=n/2-1;i>=0;i--){
        heapify(matrix,n,i);
    }

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<2;j++){
            swap(matrix[i][j],matrix[0][j]);
        }

        heapify(matrix,n,0);
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin>>n;

        vector<vector<int>> matrix(n, vector<int>(2));

        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                cin>>matrix[i][j];
            }
        }

        int w;
        cin>>w;

        heapsort(matrix);
        int profit = 0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(w<=0){
                break;
            }
            if(w>=matrix[i][1]){
                w-=matrix[i][1];
                profit += matrix[i][0];
                ans.push_back(matrix[i][0]);
            }
            else{
                profit += matrix[i][0]*w/matrix[i][1];
                ans.push_back(matrix[i][0]*w/matrix[i][1]);
                break;
            }
        }
        cout << profit << endl;

        for(int i=0;i<ans.size();i++){
            cout << ans[i] << " ";
        }
        cout  << endl;
    }
    return 0;
}