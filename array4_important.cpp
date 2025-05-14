// copying value of an array to other array but half of the values

/*
let , we take 2 arrays one of size '5' and other of size '3'
as we give other array value of first only first 3 values gets aligned...!
*/

#include<iostream>
using namespace std;
int main(){

    int a,b;
    cout<<"Enter Value Of a:";
    cin>>a;

    int arr[a];

    for(int i=0;i<a;i++){
        cin>>arr[i];
    }

    cout<<"Now Enter The Value Of b:";
    cin>>b;

    int arr2[b];
    int j = 0;

    for(int i=0 ; i<b ; i++){
        arr2[i] = arr[j++];
    }

    for(int i=0;i<b;i++){
        cout<<arr2[i]<<" ";
    }

    return 0;

}