// Cycle Detection in Undirected Graphs (Using DFS).

#include<iostream>
#include<list>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

void preparelist(unordered_map<int, list<int> > &adjlist, vector<pair<int,int> >&edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}

bool isCyclicDFS(unordered_map<int, list<int>>& adjlist, int src, unordered_map<int, bool>& visited, unordered_map<int, int>& parent){

    visited[src] = true;

    for(int neighbor : adjlist[src]){
        if(!visited[neighbor]){
            parent[neighbor] = src;
            return isCyclicDFS(adjlist, neighbor, visited, parent);
        }
        else if(visited[neighbor] && neighbor != parent[src]){
            return true;
        }
    }
    return false;
}

void CycleDetection(int nodes, vector<pair<int,int> > edges){
    unordered_map<int,bool> visited;
    unordered_map<int, list<int> > adjlist;
    unordered_map<int,int> parent;

    preparelist(adjlist,edges);

    for(int i=0; i<=nodes; i++){
        visited[i] = false;
        parent[i] = -1;
    }

    for(int i=1; i<=nodes; i++){
        if(!visited[i]){
            if(isCyclicDFS(adjlist, i, visited, parent)){
                cout<<"Yes";
                return;
            }
        }
    }
    cout<<"No";
}

int main(){

    int nodes = 3;
    vector<pair<int,int> > edges = {{1,2}, {2,3}, {3,1}};
    CycleDetection(nodes, edges);

    return 0;
}