// Topological Sort (Using Kahn's Aglorithm).

#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

void preparelist(unordered_map<int, list<int> > &adjlist, vector<pair<int ,int> > edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
    }
}
vector<int> TS_KahnAlgo(int nodes, vector<pair<int, int> > edges){
    
    unordered_map<int, list<int> > adjlist;
    preparelist(adjlist, edges);

    vector<int> indegree(nodes+1,0);
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

    vector<int> ans;
    while(!q.empty()){
        int frontnode = q.front();
        q.pop();

        ans.push_back(frontnode);

        for(auto neighbor: adjlist[frontnode]){
            indegree[neighbor]--;
            if(indegree[neighbor] == 0){
                q.push(neighbor);
            }
        }
    }
    return ans;
}

int main(){

    int nodes = 5;
    vector<pair<int,int> > edges = {{1, 2}, {1, 3}, {2, 5}, {3, 5}, {5, 4}};
    vector<int> ans = TS_KahnAlgo(nodes, edges);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}