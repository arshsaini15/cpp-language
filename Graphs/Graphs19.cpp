// Bellman Ford Algorithm.

#include<iostream>
#include<list>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

class graph{ 
    public:
    unordered_map<int, list<pair<int, int> > > adjlist;

    void addEdge(int u, int v, int weight){
        pair<int, int> p = make_pair(v,weight);
        adjlist[u].push_back(p);
    }


    vector<int> BellmanFordAlgo(int src, int dst, int nodes){
        
        vector<int> dist(nodes + 1, INT_MAX);
        dist[src] = 0;

        // Step 1: Apply formula (nodes - 1) times.
        for (int i = 1; i <= nodes - 1; i++) {
            for (auto it = adjlist.begin(); it != adjlist.end(); it++) {
                int u = it->first;
                for (auto edge : adjlist[u]) {
                    int v = edge.first;
                    int wt = edge.second;
                    if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        // Step 2: Check for negative weight cycles.
        for (auto& i : adjlist) {
            int u = i.first;
            for (auto& j : i.second){
                int v = j.first;
                int weight = j.second;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]){
                    // Negative weight cycle detected
                    cout << "Graph contains negative weight cycle" << endl;
                    // Handle cycle detection as needed
                }
            }
        }
        return dist;
    }
};

int main(){

    graph g;
    g.addEdge(1,2,2);
    g.addEdge(2,3,-1);
    g.addEdge(1,3,2);

    vector<int> ans = g.BellmanFordAlgo(1,3,3);
    for(int i=1; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}