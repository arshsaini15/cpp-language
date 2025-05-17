// Merge Two Binary Max Heaps.

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void heapify(vector<int> &v, int i, int n){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && v[left] > v[largest]){
        largest = left;
    }
    if(right < n && v[right] > v[largest]){
        largest = right;
    }
    if(largest != i){
        swap(v[largest], v[i]);
        heapify(v, largest, n);
    }
}

vector<int> merge(vector<int> v1, vector<int> v2){
    int n = v1.size() + v2.size();
    vector<int> v(n);
    int index = 0;

    for(int i=0; i<v1.size(); i++){
        v[index++] = v1[i];
    }
    for(int i=0; i<v2.size(); i++){
        v[index++] = v2[i];
    }

    for(int i=n/2 - 1; i>=0; i--){
        heapify(v, i, n);
    }

    return v;
}

int main(){

    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {6,4,5,8,9};

    vector<int> v = merge(v1,v2);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }

    return 0;
}

// 9 8 5 4 5 3 1 2 6 4 