// Quick Sort Using Recursion


#include<iostream>
using namespace std;

int partition(int *arr,int s,int e){

    int pivot = arr[s];

    int count = 0;
    for(int i=s+1;i<=e;i++){
        if(arr[i] <= pivot){
            count++;   
        }
    }

    // place pivot at right position
    int pivotindex = s + count;
    swap(arr[pivotindex] , arr[s]);

    // left and right part managing
    int i = s , j = e;

    while(i < pivotindex && j > pivotindex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pivotindex && j > pivotindex){
            swap(arr[i++] , arr[j++]);
        }
    } 

    return pivotindex;

}

void Quick_Sort(int *arr , int s , int e){

    //base case
    if(s >= e){
        return ;
    }

    // partition  p+1,e);

}


int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    Quick_Sort(arr , 0 , n - 1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;

}