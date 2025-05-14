#include<iostream>
using namespace std;

void update(int n , int arr){
    int min = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
        min=0;
    }
}

void find(int n , int arr[]){
    int max = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        max=0;
    }
}


int main(){

    int n;
    cin>>n;

    int arr[n];

    for (int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    update(n,arr[n]);
    find(n,arr[n]);

    int sum=0;
   
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    cout<<sum;

    return 0;
}