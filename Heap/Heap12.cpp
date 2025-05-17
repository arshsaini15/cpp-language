// merge k sorted arrays

#include<iostream>
#include<queue>

class node{
    public:
    // i=row, j=col
    int data, i, j;
}

void mergeArrays(vector<vector<int>> v, int k){
    priority_queue<node*, vector<node*>, compare> minheap;
}

int main(){

    vector<vector<int> > v = {
        {4,3,2,1},
        {6,5,2,3},
        {9,33,12,3}
    };

    mergeArrays(v, 3);


    return 0;
}