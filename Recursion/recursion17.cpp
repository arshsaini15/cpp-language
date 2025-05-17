// merge sort using recursion, 

#include<iostream>
using namespace std;

void Merge(int *arr , int s , int e){

    int mid = s + (e - s)/2;

    //length of both halves
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // copying values
    int *first_half = new int[len1]; 
    int *second_half = new int[len1]; 

    int MainArray = s;

    for(int i=0;i<len1;i++){
        first_half[i] = arr[MainArray++];
    }

    int k = mid + 1;

    for(int i=0;i<len2;i++){
        second_half[i] = arr[k++];
    }

    int i1 = 0;
    int i2 = 0; 
    MainArray = s;

    while(i1 < len1 && i2 < len2){
        if(first_half[i1] < second_half[i2]){
            arr[MainArray++] = first_half[i1++];
        }

         else{
            arr[MainArray++] = second_half[i2++];
         }   
    }

    while(i1 < len1){
        arr[MainArray++] = first_half[i1++];
    }

    while(i2 < len2){
        arr[MainArray++] = second_half[i2++];
    }


    delete []first_half;
    delete []second_half;

}

void Merge_Sort(int *arr , int s , int e){

    // base case

    if(s < e){
        
        int mid = s + (e - s)/2;

        // recursive calls:

        // for left side of array
        Merge_Sort(arr,s,mid);

        // for right side of array
        Merge_Sort(arr,mid+1,e);

        // merge both halves
        Merge(arr,s,e);

    }
}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    Merge_Sort(arr , 0 , n-1); 

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;

}