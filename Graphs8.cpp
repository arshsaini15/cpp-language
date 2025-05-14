// Topological Sort (Using DFS).

#include<iostream>
#include<list>
#include<unordered_map>
#include<stack>
#include<vector>
using namespace std;

void preparelist(unordered_map<int, list<int> > &adjlist, vector<pair<int,int> > edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
    }
}

void TS(unordered_map<int, list<int> > &adjlist, unordered_map<int, bool> &visited, int node, stack<int> &st){

    visited[node] = true;

    for(auto neighbors: adjlist[node]){
        if(!visited[neighbors]){
            TS(adjlist,visited,neighbors,st);
        }
    }
    st.push(node);
}

stack<int> TopologicalSort(int nodes, vector<pair<int,int> > &edges){
    unordered_map<int,list<int> > adjlist;
    unordered_map<int,bool> visited;

    preparelist(adjlist,edges);

    for(int i=1; i<=nodes; i++){
        visited[i] = false;
    }

    stack<int> st;
    for(int i=1; i<=nodes; i++){
        if(!visited[i]) TS(adjlist,visited,i,st);
    }

    return st;
}

int main(){

    int nodes = 6;
    vector<pair<int, int> > edges = {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}, {4, 6}, {5, 6}};
    stack<int> ans = TopologicalSort(nodes,edges);
    
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }

    return 0;
}