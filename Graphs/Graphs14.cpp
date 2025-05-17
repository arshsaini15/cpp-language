// Minimum Spanning Tree (Prim's Algorithm).

#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<limits.h>
using namespace std;

class graph{
    public:
    unordered_map<int, vector<pair<int, int>>> adjlist;

    void addEdge(int u, int v, int weight){
        adjlist[u].push_back({v, weight});
        adjlist[v].push_back({u, weight});
    }

    vector<pair<pair<int, int >, int > > Minimum_SpanningTree(int nodes, int src){
        vector<int> key(nodes, INT_MAX);
        vector<int> parent(nodes, -1);
        vector<bool> mst(nodes, false);

        key[src] = 0;

        for(int i=0; i<nodes-1; i++){

            int mini = INT_MAX;
            int u;

            // Step1. Find mini node.
            for(int v=0; v<nodes; v++){
                if(mst[v] == false && key[v] < mini){
                    u = v;
                    mini = key[v];
                }
            }

            // Step2. mark min node as true.
            mst[u] = true;

            // Step3. check adjacent nodes.
            for(auto it: adjlist[u]){
                int v = it.first;
                int weight = it.second;

                if(mst[v] == false && weight < key[v]){
                    parent[v] = u;
                    key[v] = weight;
                }
            }
            // Repeat...
        }

        vector<pair<pair<int, int >, int > > result;
        for(int i=1; i<nodes; i++){
            result.push_back({{parent[i], i}, key[i]});
        }
        return result;
    }
};

int main(){

    graph g;
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);

    int nodes = 5;
    int src = 0;

    vector<pair<pair<int, int >, int > > ans = g.Minimum_SpanningTree(nodes, src);
    for(auto edge : ans) {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
    }

    return 0;
}