// BFS Traversal (Breadth First Search).

#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<unordered_map> 
using namespace std;

void prepareAdjList(unordered_map<int,list<int> > &adjList, vector<pair<int,int> > &edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs(unordered_map<int,list<int> > &adjList, unordered_map<int,bool> &visited, vector<int> &ans, int node){

    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        // store frontnode in ans.  
        ans.push_back(frontNode);

        // traverse all neighbors of frontnode.
        for(auto i: adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int nodes, vector<pair<int,int> > edges){

    unordered_map<int, list<int> > adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // initialize visited map. 
    for(int i=0; i<nodes; i++){
        visited[i] = false;
    }

    // traverse all components of graph.
    for(int i=0; i<nodes; i++){
        if(!visited[i]){
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}

int main(){

    int nodes = 6;
    vector<pair<int, int> > edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};

    vector<int> result = BFS(nodes, edges);

    // Print the result.
    cout << "BFS Traversal: ";
    for(int node : result){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}