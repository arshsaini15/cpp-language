// Print Subsequences

#include<iostream>
#include<vector>
using namespace std;

void printSubs(int arr[], int n, vector<int> &v, int i, vector<vector<int> > &s){
    if(i >= n){
        s.push_back(v);
        return;
    }
    
    // take.
    v.push_back(arr[i]);
    printSubs(arr,n,v,i+1,s);

    // not take.;
    v.pop_back();
    printSubs(arr,n,v,i+1,s);
}

int main(){

    int n = 3;
    int arr[] = {3,1,2};
    
    vector<vector<int> > store;
    
    vector<int> v;
    printSubs(arr,n,v,0,store);

    for(const auto& subset : store){
        for(int num : subset){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}