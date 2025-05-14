// Sliding Window Sum.

#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

void Sum(int arr[], int n, int k){
    unordered_map<int,int> m;
    int sum = 0;
    int index = 1;

    for(int i=0; i<k; i++){
       sum+=arr[i];
    }
    m[index] = sum;
    index++;

    for(int i=k; i<n; i++){
        sum += arr[i] - arr[i-k];
        m[index] = sum;
        index++;
    }

    unordered_map<int,int> :: iterator it = m.begin();
    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    // conversion of unordered_map to map.
    // map<int,int> result(m.begin(),m.end());
    // return result;
}

int main(){

    int arr[] = {-2,10,1,2,-3,5,7};
    Sum(arr, 7, 3);

    return 0;
}