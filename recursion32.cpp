// Recursion Using Insertion Sort


#include<iostream>
using namespace std;

void InsertionSort(int *arr, int n){

    //base case
    if(n == 0){
        return ;
    }

    
    for(int i=0;i<n;i++){
        int current = arr[i];
        int j = i-1;
        while(arr[j] > current  && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=current;
    }

    //recursive call
    InsertionSort(arr,n-1);

}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    InsertionSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;

}