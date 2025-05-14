#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > printAdj(int n, int m, vector<vector<int> > &edges){
    vector<vector<int> > ans(n);

    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int> > adj(n);
    for(int i=0; i<n; i++){
        adj[i].push_back(i);

        for(int j=0; j<ans[i].size(); j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}

int main(){

    int n = 4, m = 3;
    
    vector<vector<int> > edges;
    edges.push_back({0, 1});
    edges.push_back({2, 3});
    edges.push_back({1, 2})
    
    vector<vector<int> > adjacencyList = printAdj(n, m, edges);

    for (int i = 0; i < adjacencyList.size(); i++) {
        for (int j = 0; j < adjacencyList[i].size(); j++) {
            cout << adjacencyList[i][j] << ",";
        }
        cout << endl;
    }
    
    return 0;
}
