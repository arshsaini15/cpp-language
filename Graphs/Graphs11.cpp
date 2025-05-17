// Shortest Path in Undirected Graphs.

#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

void preparelist(unordered_map<int, list<int> > &adjlist, vector<pair<int,int> > edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}

vector<int> ShortestPath(int nodes, vector<pair<int,int> > edges, int src, int dest){
    unordered_map<int, list<int> > adjlist;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent; 

    preparelist(adjlist, edges);

    for(int i=1; i<=nodes; i++){
        visited[i] = false;
        parent[i] = -1;
    }

    // do bfs.
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int frontnode = q.front();
        q.pop();

        for(auto neighbor: adjlist[frontnode]){
            if(!visited[neighbor]){
                q.push(neighbor);
                parent[neighbor] = frontnode;
                visited[neighbor] = true;
            }
        }
    }

    // iterate from dest to src.
    vector<int> path;
    path.push_back(dest);
    int currentnode = dest;

    while(currentnode != src){
        currentnode = parent[currentnode];
        path.push_back(currentnode);
    }

    reverse(path.begin(), path.end());
    return path;
}

int main(){

    int nodes = 8;
    vector<pair<int,int> > edges = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {3, 8}, {4, 6}, {5, 8}, {6, 7}, {7, 8}};
    vector<int> path = ShortestPath(nodes, edges, 1, 8);

    for(int i=0; i<path.size(); i++){
        cout<<path[i]<<" ";
    }

    return 0;
}