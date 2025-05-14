// Shortest Cycle Size.

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
    int bfs(vector<vector<int> >& adj, int node, int mini){
        int n = adj.size();
        vector<int> parent(n, -1);
        vector<int> dist(n, INT_MAX);
        queue<int> q;
        
        q.push(node);
        dist[node] = 0;

        while (!q.empty()) {
            int frontnode = q.front();
            q.pop();
            
            for(int neighbor : adj[frontnode]){
                // Not visited
                if(dist[neighbor] == INT_MAX) {
                    dist[neighbor] = dist[frontnode] + 1;
                    parent[neighbor] = frontnode;
                    q.push(neighbor);
                }
                // Cycle detected
                else if(parent[frontnode] != neighbor){
                    mini = min(mini,dist[frontnode] + dist[neighbor] + 1);
                }
            }
        }        
        return mini;
    }

    int findShortestCycle(int n, vector<vector<int> > &edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans, bfs(adj, i, INT_MAX));
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main(){

    Solution s;
    vector<vector<int> > edges = { {0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 6}, {6, 3} };
    cout << s.findShortestCycle(edges.size(),edges);

    return 0;
}