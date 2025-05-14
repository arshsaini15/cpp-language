// K-Smallest Element (Approach: 2).
/*
1. Create a max heap for first K-elements.
2. For the rest elements, if element < heap.top(){heap.pop(); heap.push(element)}.
3. ans = heap.top()
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class heap{
    public:

    int arr[100];
    int size;

    heap(){
        size=0;
        arr[0]=-1;
    }

    void insert(int val){
        size+=1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[index],arr[parent]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(vector<int> &v){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
            v.push_back(arr[i]);
        }cout<<endl;
    }

    int K_smallest(int k, vector<int> v){
        priority_queue<int> pq;

        for(int i=1;i<=k;i++){
            pq.push(arr[i]);
        }

        for(int i=k+1;i<=size;i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};

int main(){

    heap h;
    h.insert(5);
    h.insert(10);
    h.insert(1);
    h.insert(20);
    h.insert(3);

    vector<int> v;
    h.print(v);

    int k = 4;

    cout << h.K_smallest(k,v);

    return 0;
}