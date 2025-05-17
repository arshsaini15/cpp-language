// Inversion Count Using Recursion with the help of Merge Sort...!


#include<iostream>
using namespace std;

int merge(int *arr , int s , int e){

    int temp[e+1];

    int total_inversion = 0;

    int mid = s + (e-s)/2;

    int len1 = e - mid;    
    int len2 = mid - s + 1 ;


    int i = 0;
    int j = 0;
    int k = s;


    while(i < len1 && j < len2){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
            total_inversion++;
        }

        else{
            temp[k++] = arr[j++];
            total_inversion++;
        }
    }

    k = s ;

    while(i < len1){
        temp[k++] = arr[i++];
        total_inversion++;
    }

    while(j < len2){
        temp[k++] = arr[j++];
        total_inversion++;
    }

    for(int i = s ; i <= e ; i++){
        arr[i] = temp[i];
    }

    return total_inversion;
    
}


int check_inversion1(int *arr , int s , int e){

    int inversion1 = 0;

    int len1 = e - s ;

    if(e > s){

    for(int i = 0 ; i < len1 - 1 ; i++){
        for(int j = i + 1 ; j < len1 ; j++){
            if(arr[i] > arr[j]){
                inversion1++;
            }
        }
    }
    
}

    return inversion1;

}


int check_inversion2(int *arr , int s , int e){

    int inversion2 = 0;

    int len2 = e - s + 2;

    if(e > s){

    for(int i = 0 ; i < len2 - 1 ; i++){
        for(int j = i + 1 ; j < len2 ; j++){
            if(arr[i] > arr[j]){
                inversion2++;
            }
        }
    }
}

    return inversion2;

}


int merge_sort(int *arr , int s , int e){
    
    int total_inversion = 0;

    if(e > s){

    int mid = s + (e - s)/2;

    // for left part of the array
    // merge_sort(arr,s,mid);

    // for right side of the array
    // merge_sort(arr,mid+1,e);

    total_inversion = check_inversion1(arr,s,mid) + 
    check_inversion2(arr,mid+1,e) ;

    total_inversion += merge(arr , s , e);
    
    }

    return total_inversion;
    
}


int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<merge_sort(arr,0,n-1);

    return 0;

}