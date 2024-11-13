#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    
    vector<pair<pair<ll,ll>,ll>> edgelist;

    ll n;
    cin >> n;
    unordered_set<ll>vertices;
    for (ll i = 0; i < n; i++) {
        ll startindex,endindex,weight;
        cin>>startindex>>endindex>>weight;
        edgelist.push_back({{startindex,endindex},weight});
        vertices.insert(startindex);
        vertices.insert(endindex);
    }

    unordered_map<ll,ll>dist;
    for(auto it:vertices){
        dist[it] = INT_MAX;
    }
    int source;
    cin>>source;
    dist[source] = 0;
    for(int i=0;i<edgelist.size()-1;i++){
        for(auto edge:edgelist){
            int start = edge.first.first;
            int end = edge.first.second;
            int weight = edge.second;

            if(dist[start] + weight < dist[end]){
                dist[end] = dist[start] + weight;
            }
        }
    }

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
    return 0;
}