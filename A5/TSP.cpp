#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define n 4

//  FIND THE MINIMUM EDGE
int findMinEdge(int i, vector<vector<int>> &matrix) {
    int mini = INT_MAX;
    for (int j = 0; j < n; j++) {
        if (i != j && mini > matrix[i][j]) {
            mini = matrix[i][j];
        }
    }
    return mini;
}


int calculateLowerBound(int currentBound, vector<vector<int>> &matrix, vector<int> &visited) {
    int bound = currentBound;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bound += findMinEdge(i, matrix);
        }
    }
    return bound;
}

void tspByBranchBound(vector<vector<int>> &matrix, vector<int> &currpath, vector<int> &finalpath,
                      vector<int> &visited, int &finalcost, int currentcost, int currentbound, int currentlevel) {
                        // IF YOU REACHED TO THE LAST LEVEL THEN CHECK IT CAN COME TO START VERTEX
    if (currentlevel == n) {
        // IF MATRIX IS NOT 
        if (matrix[currpath[currentlevel - 1]][currpath[0]] != 0) {
            int finalcostsolution = currentcost + matrix[currpath[currentlevel - 1]][currpath[0]];
            if (finalcostsolution < finalcost) {
                finalpath = currpath;
                finalpath.push_back(currpath[0]); // Close the cycle
                finalcost = finalcostsolution;
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (matrix[currpath[currentlevel - 1]][i] != 0 && !visited[i]) {
            int temp = currentbound;
            currentcost += matrix[currpath[currentlevel - 1]][i];
            currentbound -= (findMinEdge(currpath[currentlevel - 1], matrix) + findMinEdge(i, matrix)) / 2;

            if (currentbound + currentcost < finalcost) {
                currpath[currentlevel] = i;
                visited[i] = 1;
                tspByBranchBound(matrix, currpath, finalpath, visited, finalcost, currentcost, currentbound, currentlevel + 1);
            }

            currentcost -= matrix[currpath[currentlevel - 1]][i];
            currentbound = temp;

            visited[i] = 0;
        }
    }
}

void solveTSP(vector<vector<int>> &matrix) {
    vector<int> currpath(n);
    vector<int> visited(n, 0);
    vector<int> finalpath;
    int finalcost = INT_MAX;
    int currentcost = 0;
    int currentBound = 0;

    visited[0] = 1;

    currpath[0] = 0;

    for (int i = 0; i < n; i++) {
        currentBound += findMinEdge(i, matrix);
    }
    currentBound = (currentBound + 1) / 2;

    tspByBranchBound(matrix, currpath, finalpath, visited, finalcost, currentcost, currentBound, 1);

    cout << "Minimum cost: " << finalcost << endl;
    cout << "Path: ";
    for (int i : finalpath) {
        cout << i << " ";
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
