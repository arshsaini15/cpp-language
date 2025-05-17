// Dijkastra's Shortest Path.

#include<iostream>
#include<list>
#include<unordered_map>
#include<set>
#include<vector>
using namespace std;

class graph{
    public:
    unordered_map<int, list<pair<int, int> > > adjlist;

    void addEdge(int u, int v, int weight){
        pair<int, int> p = make_pair(v,weight);
        adjlist[u].push_back(p);
    }

    vector<int> Dijkastra(int nodes, int src){
        vector<int> dist(nodes,INT_MAX);
        dist[src] = 0;

        set<pair<int, int> > st;
        st.insert(make_pair(0, src));

        while(!st.empty()){

            // fetch top record.
            auto top = *(st.begin());

            int nodeDistance = top.first;
            int topNode = top.second;

            // remove top record.
            st.erase(st.begin());

            // traverse on neighbors.
            for(auto neighbors: adjlist[topNode]){
                if(nodeDistance + neighbors.second  < dist[neighbors.first]){
                    auto record = st.find(make_pair(nodeDistance + neighbors.second, neighbors.first));

                    // if record found, then erase it.
                    if(record != st.end()){
                        st.erase(record);
                    }

                    // distance update.
                    dist[neighbors.first] = nodeDistance + neighbors.second;
                    
                    // push record in set.
                    st.insert(make_pair(dist[neighbors.first], neighbors.first));
                }
            }
        }
        return dist;
    }
};

int main(){

    graph g;
    g.addEdge(0,1,7);
    g.addEdge(0,2,1);
    g.addEdge(0,3,2);
    g.addEdge(1,0,7);
    g.addEdge(1,2,3);
    g.addEdge(1,3,5);
    g.addEdge(1,4,1);
    g.addEdge(2,0,1);
    g.addEdge(2,1,3);
    g.addEdge(3,0,2);
    g.addEdge(3,1,5);
    g.addEdge(3,4,7);
    g.addEdge(4,1,1);
    g.addEdge(4,3,7);
 
    vector<int> ans = g.Dijkastra(5, 0);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}