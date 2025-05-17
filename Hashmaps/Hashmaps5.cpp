// Count distinct elements in every window.

#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

vector<int> Distinct_elements(int arr[], int n, int k){
    
    unordered_map<int,int> m;
    vector<int> ans;

    // Step 1: Add first K elements in map.
    for(int i=0;i<k;i++){
        m[arr[i]]++;
    }

    // Step 2: Push the size of map in vector.
    ans.push_back(m.size());

    for(int i=k;i<n;i++){
        // Step 3: Remove the leftmost or the very first element from map.
        m[arr[i-k]]--;

        // Remove if the count of any element becomes zero.
        if(m[arr[i-k]] == 0){
            m.erase(arr[i-k]);
        }

        // Add the new element in map.
        m[arr[i]]++;
        ans.push_back(m.size());
    }
    return ans;
}

int main(){

    int arr[] = {1,2,1,3,4,2,3};
    int n = 7;

    vector<int> answer = Distinct_elements(arr,n,4);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }

    return 0;
}