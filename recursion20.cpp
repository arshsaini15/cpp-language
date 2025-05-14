//Find the sum of elements of an   array...!

#include<iostream>
using namespace std;

int  SumOfArray(int arr[],int size){

    if(size==0){
        return 0;
    }

    if(size==1){
        return arr[0];
    }

    int remainingPart = SumOfArray(arr+1,size-1);
    int sum = arr[0] + remainingPart;

    return sum;

}


int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<SumOfArray(arr,n);

    return 0;

}