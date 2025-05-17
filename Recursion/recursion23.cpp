//Binary Search using recusion...!

#include<iostream>
using namespace std;

int BinarySearch(int arr[],int key,int s,int e){

    //base case when element not found
    if(s>e){
        return -1;
    }

    int mid = (s+e)/2;

    //base case when element is found
    if(arr[mid] == key){
        return mid;
    }

    //recursive call
    if(arr[mid] < key){
        return BinarySearch(arr,key,mid+1,e);
    }

    else{
        return BinarySearch(arr,key,s,mid-1);
    } 

}



int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
   }

    int key;
    cin>>key;

    int s = 0;
    int e = n;

    cout<<BinarySearch(arr,key,s,e);

    return 0;

}