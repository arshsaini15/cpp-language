// Cycle Detection in Directed Graphs (Using DFS).

#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

void preparelist(vector<pair<int,int> > edges, unordered_map<int, list<int> > &adjlist){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
    }
}

bool check(unordered_map<int, list<int> > &adjlist, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, int node){
    
    visited[node] = true;
    dfsvisited[node] = true;

    for(int neighbors: adjlist[node]){
        if(!visited[neighbors]){
            bool searchcycle = check(adjlist,visited,dfsvisited,neighbors);
            if(searchcycle){
                return true;
            }
        }
        else{
            // visited true;
            if(dfsvisited[neighbors]){
                return true;
            }
        }
    }
    dfsvisited[node] = false;
    return false;
}

void CheckCycle(int nodes, vector<pair<int,int> > edges){
    unordered_map<int, list<int> > adjlist;
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsvisited;

    preparelist(edges,adjlist);

    for(int i=0; i<nodes; i++){
        visited[i] = false;
        dfsvisited[i] = false;
    }
    for(int i=0; i<nodes; i++){
        if(check(adjlist,visited,dfsvisited,i)){
            cout<<"Yes";
            return;
        }
    }
    cout<<"No";
}

int main(){

    int nodes = 8;
    vector<pair<int,int> > edges = {{1,2}, {2,3}, {3,8}, {8,7}, {2,4}, {4,5}, {5,6}, {6,4}};
    CheckCycle(nodes,edges);

    return 0;
}