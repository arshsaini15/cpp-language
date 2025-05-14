// inversion count


#include<iostream>
using namespace std;

void InversionCount(int *arr , int n){

    int inversion = 0;

    for(int i = 0 ;i <n-1 ; i++){
        for(int j = i+1;j<n;j++){
            if(arr[i] > arr[j]){
                inversion++;
            }
        }
    }
    cout<<inversion;
}


int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    InversionCount(arr,n);

    return 0;

}