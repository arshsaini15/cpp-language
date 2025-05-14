// power set using recursion

#include<iostream>
using namespace std;

void powerset(int *arr,int n,int index){

    // base case
    if(index >= n){
        cout<<"{}"<<" ";
        return;
    }

    // take
    powerset(arr,n,index+1);
    cout<<arr[index]<<" ";

    // Not take
    powerset(arr,n,index+1);

}

int main(){

    int arr[3] = {3,2,1};

    powerset(arr,3,0);  

    return 0;
}