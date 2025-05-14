#include<iostream>
#include<list>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

bool isCyclic(unordered_map<int, list<int>>& adj, int src, unordered_map<int, bool>& vis, unordered_map<int, int>& parent) {
    vis[src] = true;

    for(int nbr: adj[src]) {
        if(!vis[nbr]){
            parent[nbr] = src;
            return isCyclic(adj, nbr, vis, parent);
        } else if(vis[nbr] && nbr != parent[src]) {
            return true;
        }
    }
    return false;
}

void CycleDetection(int nodes, vector<pair<int, int>> edges) {
    unordered_map<int, bool> vis;
    unordered_map<int, list<int>> adj;
    unordered_map<int, int> parent;

    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=nodes; i++) {
        if(!vis[i]){
            if(isCyclic(adj, i, vis, parent)){
                cout << "Yes";
                return;
            }
        }
    }
    cout << "No";
}

int main() {
    int nodes = 3;
    vector<pair<int, int> > edges = {{1,2}, {2,3}, {3,1}};
    CycleDetection(nodes, edges);

    return 0;
}