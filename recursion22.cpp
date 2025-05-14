//First and Last occurence of an element in a sorted array using Binary Search...!

#include<iostream>
using namespace std;

int First_And_Last_Occurence(int arr[],int key, int s, int e){
   
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
        return First_And_Last_Occurence(arr,key,mid+1,e);
    }
    else{
        return First_And_Last_Occurence(arr,key,s,mid-1);
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

    cout<<First_And_Last_Occurence(arr,key,s,e);

    return 0;
    

}