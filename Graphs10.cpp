// Cycle Detection in Directed Graph (using BFS).

#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

void preparelist(unordered_map<int, list<int> > &adjlist, vector<pair<int, int> > edges){
    
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjlist[u].push_back(v);
    }
}

bool Detect_Cycle(int nodes, vector<pair<int,int> > edges){
    unordered_map<int, list<int> > adjlist;
    unordered_map<int, bool> visited;

    preparelist(adjlist,edges);

    for(int i=1; i<nodes; i++){
        visited[i] = false;
    }

    vector<int> indegree(nodes,0);
    for(auto i: adjlist){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i=1; i<=nodes; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    int count = 0;
    while(!q.empty()){
        int frontnode = q.front();
        q.pop();

        // inc count.
        count++;

        for(auto neighbor: adjlist[frontnode]){
            indegree[neighbor]--;
            if(indegree[neighbor] == 0){
                q.push(neighbor);
            }
        }
    }

    if(count == nodes){
        return false;
    }
    return true;
}

int main(){

    int nodes = 5;
    vector<pair<int,int> > edges = {{1, 2}, {1, 3}, {2, 5}, {3, 5}, {5, 4}};
    cout << Detect_Cycle(nodes, edges);

    return 0;
}   