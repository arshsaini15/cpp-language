// Articulation Points in Graphs.

#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<int> &ap, unordered_map<int, list<int>>& adj, unordered_map<int, bool>& vis) {
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for(auto nbr : adj[node]){
        if(nbr == parent){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr, node, timer, disc, low, ap, adj, vis);
            low[node] = min(low[node], low[nbr]);

            // check if node is Articulation Point.
            if(low[nbr] >= disc[node] && parent != -1){
                // if Articulation Point mark them as '1' or 'true', At the time of printing AP's print who are not equal to 0.
                ap[node] = 1;
            }
            child++;
        }
        else{
            // Back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }
    if(parent != -1 && child > 1){
        ap[node] = 1;
    }
}

vector<int> ArticulationPoints(vector<vector<int>>& edges, int v, int e){
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

    vector<int> ap(v,0); 

    for(int i = 0; i < v; i++){
        if(!vis[i]){
            dfs(i, parent, timer, disc, low, ap, adj, vis);
        }
    }
    return ap;
}

int main(){

    int v = 5; // Number of vertices
    int e = 5; // Number of edges
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};

    vector<int> ap = ArticulationPoints(edges, v, e);

    cout << "Articulation Points in the graph are: " << endl;
    for(int i=0; i<ap.size(); i++){
        if(ap[i] != 0)
            cout << i << " ";
    }

    return 0;
}