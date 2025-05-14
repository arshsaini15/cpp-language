// Selection Sort Using Recursion

#include<iostream>
using namespace std;

void SelectionSort(int *arr, int n){
    
    //base case 
    if(n == 0){
        return ;
    }

    //processing 
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
                swap(arr[i] , arr[j]);
            }
        }
    }

    //recursive call
    SelectionSort(arr,n-1);

}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    SelectionSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;

}