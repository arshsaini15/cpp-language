// Minimum Cost Of Ropes.

#include<iostream>
#include<queue>
using namespace std;

int main(){

    priority_queue<int, vector<int>, greater<int> > pq;
    vector<int> v = {4,3,2,6};

    for(int i=0; i<v.size(); i++){
        pq.push(v[i]);
    }

    // take two variables, add them and push again to queue.
    int ans = 0;
    while(pq.size() > 1){
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        int sum = a+b;
        pq.push(sum);
        ans += sum;
    }

    cout << ans;

    return 0;
}