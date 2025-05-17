// K-th smallest element (Approach : 1).

#include<iostream>
using namespace std;

class heap{
    public:

    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size+=1;
        int index = size;
        arr[index] = val;

        while(index>1){
            int parent = index/2;

            if(arr[parent] > arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
    
    void print(vector<int> &v){
        for(int i=1;i<=size;i++){
            // cout<<arr[i]<<" "; 
            v.push_back(arr[i]);
        }
    }
};

void arrange(vector<int> &v){
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i] > v[j]){
                swap(v[i],v[j]);
            }
        }
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void K_smallest(int k, vector<int> v, heap h){
    h.print(v);
    arrange(v);
    cout << v[k-1];
}

int main(){

    heap h;
    h.insert(55);
    h.insert(54);
    h.insert(53);
    h.insert(52);
    h.insert(50);
    h.insert(45);

    vector<int> v;

    int k=3;
    K_smallest(k,v,h);

    return 0;
}