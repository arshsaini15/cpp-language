// Kosaraju's Algorithm.

#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<unordered_map>
using namespace std;

void dfs(unordered_map<int, list<int> > &newadjlist, unordered_map<int, bool> &visited,
 int node, vector<int> &sub_ans){

    visited[node] = true;
    sub_ans.push_back(node);

    for(auto nbr: newadjlist[node]){
        if(!visited[nbr]){
            dfs(newadjlist, visited, nbr, sub_ans);
        }
    }
}

void TS(unordered_map<int, bool> &visited, unordered_map<int, list<int> > &adjlist, int node, stack<int> &st){

    visited[node] = true;
    
    for(auto neighbors: adjlist[node]){
        if(!visited[neighbors]){
            TS(visited, adjlist, neighbors, st);
        }
    }
    st.push(node);
}

vector<vector<int> > KosarajuAlgorithm(vector<vector<int> > edges, int nodes){
    unordered_map<int, bool> visited;
    unordered_map<int, list<int> > adjlist;

    // make list.
    for(int i=0; i< edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
    }

    // Step 1: Topological Sort.
    stack<int> st;
    for(int i=0; i<nodes; i++){
        if(!visited[i]){
            TS(visited, adjlist, i, st);
        }
    }

    // Step 2: Transpose of Graph / Change direction of edges.
    unordered_map<int, list<int> > newadjlist;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        newadjlist[v].push_back(u);
    }

    // Step 3: Count/Print SCC.
    visited.clear();
    vector<vector<int> > finalans;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!visited[node]){
            vector<int> component;
            dfs(newadjlist, visited, node, component);
            finalans.push_back(component);
        }
    }
    return finalans;
}


int main(){

    vector<vector<int> > edges = {{0,1}, {1,2}, {2,0}, {2,3}, {3,4}};
    int nodes = 5;
    vector<vector<int>> ans = KosarajuAlgorithm(edges, nodes);

    for (const auto &component : ans) {
        for (int node : component) {
            cout << node << " ";
        }cout << endl;
    }

    return 0;
}