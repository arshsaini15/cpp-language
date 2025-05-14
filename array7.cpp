// Insert An Element In An Array.

#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int num=100;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    n+=1;

    for(int i=0;i<n;i++){
        if(i == n-1){
            arr[i] = num;
            swap(arr[0],arr[i]);
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}