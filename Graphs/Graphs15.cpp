// Kruskal's Algorithm.

#include<iostream>
#include<unordered_map>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    // as weight is in 3rd column so we choose index 2.
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, int nodes){
    for(int i=0; i<nodes; i++){
        parent[i] = i;
    }
}

int findParent(vector<int> &parent, int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent,parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(parent, u);
    v = findParent(parent, v);
    
    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int> > &edges, int nodes){
    
    sort(edges.begin(), edges.end(), cmp);
    
    vector<int> parent(nodes);
    vector<int> rank(nodes, 0);
    makeSet(parent, nodes);

    int minweight = 0;

    for(int i=0; i<edges.size(); i++){
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if(u != v){
            minweight += wt;
            unionSet(u,v,parent,rank);
        }
    }
    return minweight;
}

int main(){

    vector<vector<int>> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };
    
    int nodes = 4;
    int result = minimumSpanningTree(edges, nodes);
    
    cout << "The weight of the minimum spanning tree is: " << result << endl;

    return 0;
}