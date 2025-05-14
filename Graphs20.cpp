// Longest Cycle Size.

#include<iostream>
#include <unordered_map>
#include <vector>
#include <climits>
#include <list>
#include <vector>
using namespace std;

class Solution {
public:

    int dfs(int node, unordered_map<int, list<int>>& adj, vector<bool>& vis, vector<bool>& dfsvis, vector<int>& dist, int maxi) {
        vis[node] = true;
        dfsvis[node] = true;
        
        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                dist[nbr] = dist[node] + 1;
                maxi = dfs(nbr, adj, vis, dfsvis, dist, maxi);
            }
            else{
                // Cycle Detected
                if(dfsvis[nbr]){
                    maxi = max(maxi, dist[node] - dist[nbr] + 1);
                }
            }
        }

        dfsvis[node] = false;
        return maxi;
    }

    int longestCycle(vector<int>& edges){
        int n = edges.size();
        unordered_map<int, list<int>> adj;

        for(int i = 0; i < n; i++){
            int u = i;
            int v = edges[i];
            if (edges[i] != -1) {
                adj[u].push_back(v);
            }
        }

        vector<bool> vis(n, false);
        vector<bool> dfsvis(n, false);
        vector<int> dist(n, 0);
        int ans = -1;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                ans = max(ans, dfs(i, adj, vis, dfsvis, dist, 0));
            }
        }

        return (ans == 0) ? -1 : ans;
    }
};

int main(){
    
    Solution s;
    vector<int> edges = {3,3,4,2,3};
    cout << s.longestCycle(edges) << endl;

    return 0;
}