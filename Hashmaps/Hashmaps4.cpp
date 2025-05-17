// Maximum distance between same occurring elements.

#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int Find_Dist(int arr[], int n){
    unordered_map<int,int> m;
    int max_dist=0;

    for(int i=0;i<n;i++){  
        // check if element is present or not.
        if(m.find(arr[i]) == m.end()){
            m[arr[i]] = i;
        }
        else{
            // if element is found change max distance.
            max_dist = max(max_dist, i-m[arr[i]]);
        }
    }
    return max_dist;
}


int main(){

    int arr[] = {1,1,2,2,2,1};
    int n=6;

    cout<<Find_Dist(arr,n)<<endl;

    return 0;
}