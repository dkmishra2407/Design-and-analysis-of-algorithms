#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 4

int findminindex(int i,vector<vector<int>>&matrix){
    int mini = INT_MAX;

    for(int j=0;j<N;j++){
        if(i != j && matrix[i][j] < mini){
            mini = matrix[i][j];
        }
    }
    return mini;
}

int calculateLowerBound(vector<vector<int>>&matrix,int currentBound,
vector<int>&visited){
    int bound = currentBound;

    for(int i=0;i<N;i++){
        if (!visited[i]) { 
            bound += findminindex(i, matrix); 
        } 
    }
    return bound;
}

void tspBranchAndBound(vector<vector<int>>&matrix,vector<int>&currpath, vector<int>&finalpath,vector<int>&visited,int currentBound,int finalcost,int n,int currlevel,int currCost){

    if(currlevel == N){
        if(matrix[currpath[currlevel - 1]][currpath[0]] != 0){
            int finalsolCost = currCost + matrix[currpath[currlevel - 1]][currpath[0]];

            if(finalsolCost < finalcost ){
                finalpath = currpath;
                finalpath.push_back(currpath[0]);
                finalsolCost = finalcost;
            }

            return;
        }
    }

    for(int i=0;i<N;i++){
        if(matrix[currpath[currlevel - 1]][i] != 0 && !visited[i]){
            int temp = currentBound;
            currCost += matrix[currpath[currlevel - 1]][i];

            currentBound -= (findminindex(currpath[currlevel - 1], matrix) + 
findminindex(i, matrix)) / 2; 

            if (currentBound + currentCost < finalCost) { 
                currentPath[currentLevel] = i; 
                visited[i] = true; 
 
                tspBranchAndBound(costMatrix, currentPath, visited, finalCost, finalPath, currentBound, 
currentCost, currentLevel + 1); 
            } 

            if (currentBound + currentCost < finalCost) { 
                currentPath[currentLevel] = i; 
                visited[i] = true; 
 
                tspBranchAndBound(costMatrix, currentPath, visited, finalCost, finalPath, currentBound, 
currentCost, currentLevel + 1); 
            } 
        }
    }
}
void solveTsp(vector<vector<int>>&matrix,int n){
    vector<int> currpath(N);
    vector<int> visited(N,0);

    int currentBound = 0;

    for(int i=0;i<N;i++){
        currentBound += (findminindex(i, matrix) + findminindex(i, matrix));
    }

    currentBound = (currentBound & 1) ? currentBound / 2 + 1 : currentBound / 2;

    visited[0] = true;
    currpath[0] = 0;

    vector<int> finalpath;
    int finalCost = 0;

    tspBranchAndBound(matrix,currpath,finalpath,visited,currentBound,finalCost,n,1);
}
int main() {
    int n;
    cin>>n;

    vector<vector<int>> matrix(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    solveTsp(matrix, n);
    return 0;
}