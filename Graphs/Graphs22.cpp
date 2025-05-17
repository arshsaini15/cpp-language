// Dijkastra Algorithm.

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<set>
using namespace std;

class graph {
    public:
    unordered_map<int, list<pair<int, int> > > adj;

    void addEdge(int u, int v, int w){
        pair<int, int> p = make_pair(v, w);
        adj[u].push_back(p);
    }

    vector<int> Dijkastra(int nodes, int src){
        vector<int> dist(nodes, INT_MAX);
        dist[src] = 0;

        set<pair<int, int> > st;
        st.insert(make_pair(0, src));

        while(!st.empty()){
            auto top = *(st.begin());

            int nodeDistance = top.first;
            int topNode = top.second;

            st.erase(st.begin());

            for(auto nbr: adj[topNode]){
                if(nodeDistance + nbr.second < dist[nbr.first]){
                    auto record = st.find(make_pair(nodeDistance + nbr.second, nbr.first));

                    if(record != st.end()){
                        st.erase(record);
                    }

                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert(make_pair(dist[nbr.first], nbr.first));
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
        cout << ans[i] << " ";
    }

    return 0;
}