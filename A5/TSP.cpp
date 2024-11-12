#include<bits/stdc++.h> 
using namespace std; 
#define N 4 
 
// FIND THE MINIMUM EDGE 
int findMinEdge(int i, const vector<vector<int>>& costMatrix) { 
    int min = INT_MAX; 
    for (int j = 0; j < N; j++) { 
        if (i != j && costMatrix[i][j] < min) { 
            min = costMatrix[i][j]; 
        } 
    } 
    return min; 
} 
 
//CALCULATE THE LOWER BOUND 
int calculateLowerBound(const vector<vector<int>>& costMatrix, const vector<bool>& visited, int 
currentBound, int currentLevel) { 
    int bound = currentBound; 
 
    for (int i = 0; i < N; i++) { 
        if (!visited[i]) { 
            bound += findMinEdge(i, costMatrix); 
        } 
    } 
    return bound; 
} 
 
// Recursive function to solve the TSP using branch and bound 
void tspBranchAndBound(const vector<vector<int>>& costMatrix, vector<int>& currentPath, 
vector<bool>& visited, int& finalCost, vector<int>& finalPath, int currentBound, int currentCost, 
int currentLevel) { 
    if (currentLevel == N) { 
        if (costMatrix[currentPath[currentLevel - 1]][currentPath[0]] != 0) {   //Checks if there’s a direct path from the last city visited back to the starting city.
            int finalSolutionCost = currentCost + costMatrix[currentPath[currentLevel - 
1]][currentPath[0]]; 
 
            if (finalSolutionCost < finalCost) { 
                finalPath = currentPath; 
                finalPath.push_back(currentPath[0]); // Complete the cycle 
                finalCost = finalSolutionCost; 
            } 
        } 
        return; 
    } 
 
    for (int i = 0; i < N; i++) { 
        if (costMatrix[currentPath[currentLevel - 1]][i] != 0 && !visited[i]) { 
            int temp = currentBound; 
            currentCost += costMatrix[currentPath[currentLevel - 1]][i]; 
 
            if (currentLevel == 1) { 
                currentBound -= (findMinEdge(currentPath[currentLevel - 1], costMatrix) + 
findMinEdge(i, costMatrix)) / 2; 
            } else { 
                currentBound -= (findMinEdge(currentPath[currentLevel - 1], costMatrix) + 
findMinEdge(i, costMatrix)) / 2; 
            } 
 
            if (currentBound + currentCost < finalCost) { 
                currentPath[currentLevel] = i; 
                visited[i] = true; 
 
                tspBranchAndBound(costMatrix, currentPath, visited, finalCost, finalPath, currentBound, 
currentCost, currentLevel + 1); 
            } 
 
            currentCost -= costMatrix[currentPath[currentLevel - 1]][i]; 
            currentBound = temp; 
 
            fill(visited.begin(), visited.end(), false); 
            for (int j = 0; j <= currentLevel - 1; j++) { 
                visited[currentPath[j]] = true; 
            } 
        } 
    } 
} 
 
// Main function to solve TSP using Branch and Bound 
int solveTSP(const vector<vector<int>>& costMatrix) { 
    vector<int> currentPath(N); 
    vector<bool> visited(N, false); 
 
    //INITIALIZE THE LOWER BOUND 
    int currentBound = 0; 
    for (int i = 0; i < N; i++) { 
        currentBound += (findMinEdge(i, costMatrix) + findMinEdge(i, costMatrix)); 
    } 
    currentBound = (currentBound & 1) ? currentBound / 2 + 1 : currentBound / 2; 
//     Example to Illustrate currentBound
// Let's take an example with the following costMatrix for four cities (N = 4):

// cpp
// Copy code
// vector<vector<int>> costMatrix = { 
//     {0, 10, 15, 20}, 
//     {10, 0, 35, 25}, 
//     {15, 35, 0, 30}, 
//     {20, 25, 30, 0} 
// };
// Here’s the breakdown for each step:

// Finding Minimum Outgoing Edges:

// For each city, find the minimum cost edge to another city.

// City 0: The smallest edge is to City 1, with a cost of 10.
// City 1: The smallest edge is to City 0, with a cost of 10.
// City 2: The smallest edge is to City 0, with a cost of 15.
// City 3: The smallest edge is to City 0, with a cost of 20.
// Adding Twice the Minimum Edge Cost:

// Now, we add twice the minimum outgoing edge for each city:

// currentBound
// =
// 2
// ×
// 10
// +
// 2
// ×
// 10
// +
// 2
// ×
// 15
// +
// 2
// ×
// 20
// =
// 20
// +
// 20
// +
// 30
// +
// 40
// =
// 110
// currentBound=2×10+2×10+2×15+2×20=20+20+30+40=110
// Adjusting for Integer Division:

// Now, we divide currentBound by 2 to get the actual bound.

// Since 110 is even, dividing by 2 gives us:

// currentBound
// =
// 110
// /
// 2
// =
// 55
// currentBound=110/2=55
// Thus, our initial currentBound is 55. This value serves as a starting lower bound estimate for the minimum cost to complete the TSP tour.
    visited[0] = true; 
    currentPath[0] = 0; 
 
    vector<int> finalPath; 
    int finalCost = INT_MAX; 
 
    tspBranchAndBound(costMatrix, currentPath, visited, finalCost, finalPath, currentBound, 0, 1); 
 
    cout << "Minimum cost: " << finalCost << endl; 
    cout << "Path: "; 
    for (int i : finalPath) { 
        cout << i << " "; 
    } 
    cout << endl; 
 
    return finalCost; 
} 
 
int main() { 
    vector<vector<int>> costMatrix = { 
        {0, 10, 15, 20}, 
        {10, 0, 35, 25}, 
        {15, 35, 0, 30}, 
        {20, 25, 30, 0} 
    }; 
 
    solveTSP(costMatrix); 
    return 0; 
} 
 