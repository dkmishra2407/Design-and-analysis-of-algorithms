#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define n 4

int findMinEdge(vector<vector<int>>&matrix,int j){
    int mini = INT_MAX;

    for(int i=0;i<n;i++){
        if(i != j && mini > matrix[j][i]){
            mini = matrix[j][i];
        }
    }

    return mini;
}


void TSPByBranchAndBound(vector<vector<int>>&matrix,vector<int>&currpath,vector<int>&finalpath,vector<int>&visited,int currBound,int currCost,int &FinalCost,int currLevel){
    if(currLevel == n){
        if(matrix[currpath[currLevel - 1]][currpath[0]] != 0){
            int finalcostSol = currCost + matrix[currpath[currLevel - 1]][currpath[0]];

            if(finalcostSol < FinalCost){
                finalpath = currpath;
                finalpath.push_back(currpath[0]);
                FinalCost = finalcostSol;
           }
        }
        return;
    }

    for(int i=0;i<n;i++){
        if(matrix[currpath[currLevel - 1]][i] != 0 && !visited[i]){
            int temp = currBound;
            currCost += matrix[currpath[currLevel - 1]][i];
            currBound -= findMinEdge(matrix,currpath[currLevel-1]) + findMinEdge(matrix,i);

            if(currBound + currCost < FinalCost){
                currpath[currLevel] = i;
                visited[i] = 1;
                TSPByBranchAndBound(matrix,currpath,finalpath,visited,currBound,currCost,FinalCost,currLevel+1);
            }

            currBound = temp;
            visited[i] = 0;
            currCost -= matrix[currpath[currLevel - 1]][i];
        }
    }
}
void solveTSP(vector<vector<int>>&matrix){
    vector<int> currpath(n,0);
    vector<int> finalpath;
    vector<int> visited(n,0);
    int currBound = 0;
    int currCost = 0;
    int FinalCost = INT_MAX;
    for (int i = 0; i < n; i++) {
        currBound += findMinEdge(matrix, i) * 2;  // Find the minimum edge for each node
    }

    currBound = (currBound + 1) / 2;


    visited[0] = 1;
    currpath[0] = 0;

    TSPByBranchAndBound(matrix,currpath,finalpath,visited,currBound,currCost,FinalCost,1);
    cout << "Minimum cost: " << FinalCost << endl;

    cout << "Path: ";
    for (int i = 0; i < finalpath.size(); i++) {
        cout << finalpath[i] << " ";
    }
    cout << endl;
}
int main() {
    vector<vector<int>> matrix = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    solveTSP(matrix);
    return 0;
}