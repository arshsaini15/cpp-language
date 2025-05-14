// Cycle Detection in Undirected Graphs (Using BFS).

#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
#include<vector>
using namespace std;

void preparelist(unordered_map<int, list<int> > &adjlist, vector<pair<int, int> > &edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}

bool isCyclicBFS(unordered_map<int,list<int> > &adjList, unordered_map<int,bool> &visited, int src){

    unordered_map<int,int> parent;
    parent[src] = -1;
    visited[src] = 1;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        // traverse all neighbors of frontnode.
        for(auto neighbor: adjList[frontNode]){
            if(visited[neighbor] && neighbor != parent[frontNode]){
                return true;
            }
            else if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = 1;
                parent[neighbor] = frontNode; 
            }
        }
    }
    return false; 
}

void CycleDetection(int nodes, vector<pair<int,int> > edges){

    unordered_map<int, bool> visited;
    unordered_map<int, list<int> > adjlist;

    preparelist(adjlist, edges);

    for(int i=0; i<nodes; i++){
        visited[i] = false;
    }
    for(int i=0; i<nodes; i++){
        if(!visited[i]){
            if(isCyclicBFS(adjlist,visited,i)){
                cout<<"Yes";
                return;
            }
        }
    }
    cout<<"No";
}

int main(){

    int nodes = 10;
    vector<pair<int,int> > edges = {{1,2}, {2,3}, {4,5}, {5,6}, {5,7}, {6,8}, {7,8}, {8,9}};
    CycleDetection(nodes, edges);

    return 0;
}