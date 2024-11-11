#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        unordered_map<int, int> dist;
        unordered_set<int> vertices;
        vector<pair<pair<int, int>, int>> edgelist;

        for (int i = 0; i < n; ++i) {
            int startIndex, endIndex, weight;
            cin >> startIndex >> endIndex >> weight;
            edgelist.push_back({{startIndex, endIndex}, weight});
            vertices.insert(startIndex);
            vertices.insert(endIndex);
        }

        int source;
        cin >> source;

        // Initialize all distances to INT_MAX
        for (auto vertex : vertices) { 
            dist[vertex] = INT_MAX; 
        }
        
        // Set the source distance to 0
        dist[source] = 0;

        // Relax edges |V|-1 times
        for (int i = 0; i < vertices.size() - 1; i++) {
            for (auto edge : edgelist) {
                int start = edge.first.first;
                int end = edge.first.second;
                int weight = edge.second;

                if (dist[start] != INT_MAX && dist[start] + weight < dist[end]) {
                    dist[end] = dist[start] + weight;
                }
            }
        }

        // Check for negative cycles
        bool isNegativeCycle = false;
        for (auto edge : edgelist) {
            int start = edge.first.first;
            int end = edge.first.second;
            int weight = edge.second;

            if (dist[start] != INT_MAX && dist[start] + weight < dist[end]) {
                isNegativeCycle = true;
                break;
            }
        }

        if (isNegativeCycle) {
            cout << "negative cycle" << endl;
        } else {
            for (auto vertex : vertices) {
                cout << (dist[vertex] == INT_MAX ? "INF" : to_string(dist[vertex])) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}


// 1
// 4
// 0 1 1
// 0 2 4
// 1 2 2
// 1 3 6
// 0


//1 
// 3
// 0 1 1
// 1 2 -1
// 2 0 -1
// 0
