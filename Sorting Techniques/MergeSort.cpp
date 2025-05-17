// Merge Sort Using Recursion

#include<iostream>
using namespace std;

void Merge(int *arr , int begin , int end){

    int mid  = begin + (end - begin)/2;

    int len1 = mid - begin + 1;
    int len2 = end - mid;

    // copy values
    int *first = new int[len1];
    int *second = new int[len2];

    /*
    int firstarray[len1];
    int secondarray[len2];
    */


    int MainArrayIndex = begin;

    for(int i=0;i<len1;i++){
        first[i] = arr[MainArrayIndex++];
    }

    int k = mid+1;

    for(int i=0;i<len2;i++){
        second[i] = arr[k++]; 
        // second[i] = arr[MainArrayIndex++];
    }


    // merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    MainArrayIndex = begin;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[MainArrayIndex++] = first[index1++];
        }
        else{
            arr[MainArrayIndex++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[MainArrayIndex++] = first[index1++];
    }

    while(index2 < len2){
        arr[MainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

}

void MergeSort(int *arr, int  begin , int end){

    // base case
    if(begin >= end){
        return;
    }

    int mid = begin + (end - begin)/2;

    // for left part of the array
    MergeSort(arr , begin , mid);

    // for right part of the array
    MergeSort(arr , mid+1 , end);

    // merge both arrays
    Merge(arr , begin , end);
}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    MergeSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}