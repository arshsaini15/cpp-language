// DFS traversal (Depth First Search).

#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std;

void preparelist(unordered_map<int, list<int> > &adjlist, vector<pair<int,int> > edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}

void dfs(unordered_map<int, list<int> > &adjlist, unordered_map<int, bool > &visited, vector<int> &ans, int node){

    visited[node] = true;
    ans.push_back(node);

    for(int neighbor : adjlist[node]){
        if(!visited[neighbor]){
            dfs(adjlist, visited, ans, neighbor);
        }
    }
}

vector<int> DFS(int nodes, vector<pair<int,int> > &edges){
    vector<int> ans;
    unordered_map<int, bool> visited;
    unordered_map<int, list<int> > adjlist;

    preparelist(adjlist, edges);

    for(int i=0; i<nodes; i++){
        visited[i] = false;
    }

    for(int i=0; i<nodes; i++){
        if(!visited[i]){
            dfs(adjlist, visited, ans, i);
        }
    }
    return ans;
}

int main(){

    int nodes = 5;
    vector<pair<int,int> > edges = {{0,2}, {2,1}, {1,3}, {3,4}, {4,2}};

    vector<int> ans = DFS(nodes, edges);

    for(int node : ans){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}