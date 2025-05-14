// Kth largest sum Subarray.

#include<iostream>
#include<queue>
using namespace std;

int Kth_largestSumSubarray(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(pq.size() < k){
                pq.push(sum);
            } else {
                if(sum > pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}

int main(){

    int arr[] = {1,2,6,4,3};
    int k = 3;
    cout << Kth_largestSumSubarray(arr, 5, k);

    return 0;
}