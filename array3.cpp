// copy value of an array to another array

#include<iostream>
using namespace std;

int main(){
    
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int arr2[n];
    int j = 0;

    for(int i=0;i<n;i++){
        arr2[i] = arr[j++];
    }

    for(int i=0;i<n;i++){
        cout<<arr2[i];
    }

    return 0;
 
}