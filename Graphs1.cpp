// Implementation of Graph using lists.

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int> >adj;

    void addEdge(int u, int v, bool direction){
        // direction = 0 -> Undirected graph
        // direction = 1 -> Directed graph

        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }i

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<", "; 
            }cout<<endl;
        }
    }
};

int main(){
    
    int n;
    cout<<"Enter number of Nodes:"<<endl;
    cin>>n;

    int m;
    cout<<"Enter number of Edges:"<<endl;
    cin>>m;

    graph g;

    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
         
        // creating undirected graph.
        g.addEdge(u,v,0);
    }

    g.printAdjList();

    return 0;
}