// Shortest Path in Directed Acyclic Graph.

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

class graph{
    public:
    unordered_map<int, list<pair<int, int> > > adjlist;

    void addEdge(int u, int v, int weight){
        pair<int, int> p = make_pair(v,weight);
        adjlist[u].push_back(p); 
    }

    void print(){
        for(auto i: adjlist){
            cout<<i.first<<" ";
            for(auto j: i.second){
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }cout<<endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st){

        visited[node] = true;

        for(auto neighbors: adjlist[node]){
            if(!visited[neighbors.first]){
                dfs(neighbors.first,visited,st);
            }
        }
        st.push(node);
    }

    void getShortestPath(int src, vector<int> &dist, stack<int> &st){

        dist[src] = 0;

        while(!st.empty()){
            int topnode = st.top();
            st.pop();

            if(dist[topnode] != INT_MAX){
                for(auto i: adjlist[topnode]){
                    if(dist[topnode] + i.second < dist[i.first]){
                        dist[i.first] = dist[topnode] + i.second;
                    }
                }
            }
        }
    }
};


int main(){

    graph g;

    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    // g.print();

    int nodes = 6;

    // Topological Sort.
    unordered_map<int, bool> visited;
    stack<int> st;
    for(int i=0; i<nodes; i++){
        if(!visited[i]){
            g.dfs(i,visited,st);
        }
    }

    int src = 1;
    vector<int> dist(nodes,INT_MAX);
    g.getShortestPath(src, dist, st);

    for(int i=0; i<dist.size(); i++){
        cout<<dist[i]<<" ";
    }

    return 0;
}