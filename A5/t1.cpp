#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define n 4

int FindMinEdge(int i,vector<vector<int>>&matrix){
    int mini = INT_MAX;
    for(int j=0;j<n;j++){
        if(i != j && matrix[i][j] < mini){
            mini = matrix[i][j];
        }
    }
    return mini;
}

int calculateLowerBound(int currBound,int i,vector<vector<int>>&matrix){
    int bound = currBound;
    for(int j=0;j<n;j++){
        bound += matrix[i][j];
    }
    return bound;
}

void tspByBranchAndBound(vector<vector<int>>&matrix,vector<bool>&visited,vector<int>&currpath,
        vector<int>&finalpath,int finalcost,int currentLevel,int currentCost,int currentBound){

            if(currentLevel == n){
                if(matrix[currpath[currentLevel - 1]][currpath[0]] != 0){
                    int finalsolution = currentCost + matrix[currpath[currentLevel - 1]][currpath[0]];

                    if(finalsolution < finalcost){
                        finalpath = currpath;
                        finalpath.push_back(currpath[0]);
                        finalcost = finalsolution;
                    }
                }
                return;
            }

            for(int i=0;i<n;i++){
                if(matrix[currpath[currentLevel - 1]][currpath[i]] != 0 && !visited[i]){
                    int temp = currentBound;
                    currentCost += matrix[currpath[currentLevel - 1]][currpath[i]];
                    currentBound -= (findMinEdge(currpath[currentlevel - 1], matrix) + findMinEdge(i, matrix)) / 2;
                    if(currentCost + currentBound < finalcost){

                    }
                }
            }
}
void solvetsp(vector<vector<int>>&matrix){
    vector<bool> visited(n,false);
    vector<int> currpath(n);
    vector<int> finalpath(n);

    int finalcost = INT_MAX;
    int currentLevel =1;
    int currentCost =0;
    int currentBound = 0;

    for(int i=0;i<n;i++){
        currentBound += FindMinEdge(i,matrix);
    }

    currentBound = (currentBound + 1 )/ 2;
    tspByBranchAndBound(matrix,visited,currpath,finalpath,finalcost,currentLevel,currentCost,currentBound);

    cout << "Minimum cost: " << finalcost << endl;
    cout << "Path: ";
    for (int i : finalpath) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> matrix(n,vector<int>(n));

    matrix= {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    solvetsp(matrix);
    return 0;
}