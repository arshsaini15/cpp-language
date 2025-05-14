// Bridges in Graphs.

#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>>& result, unordered_map<int, list<int>>& adj, unordered_map<int, bool>& vis){
    vis[node] = true;
    disc[node] = low[node] = timer++;

    for(auto nbr : adj[node]){
        if(nbr == parent){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr, node, timer, disc, low, result, adj, vis);
            low[node] = min(low[node], low[nbr]);

            // check edge is bridge
            if(low[nbr] > disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else{
            // Back edger
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> FindBridges(vector<vector<int>>& edges, int v, int e){
    // adjlist
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    unordered_map<int, bool> vis;

    vector<vector<int>> result;

    for(int i = 0; i < v; i++){
        if(!vis[i]){
            dfs(i, parent, timer, disc, low, result, adj, vis);
        }
    }
    return result;
}

int main(){

    int v = 5; // Number of vertices
    int e = 5; // Number of edges
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};

    vector<vector<int>> bridges = FindBridges(edges, v, e);

    cout << "Bridges in the graph are:\n";
    for(auto bridge : bridges){
        cout << bridge[0] << " - " << bridge[1] << "\n";
    }

    return 0;
}