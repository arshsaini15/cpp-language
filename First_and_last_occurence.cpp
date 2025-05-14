#include<iostream>
using namespace std;


int first_occurence(int arr[], int key, int s, int e){

    int first = -1;

    while(s<=e){
    
        int mid = (s+e)/2;

        if(arr[mid] == key){
            first = mid;
            e = mid - 1;
        }

        if(arr[mid] < key){
            s = mid + 1;
        }

        else{
            e = mid - 1;
        }
    }
    return first;
}


int last_occurence(int arr[], int key, int s, int e, int n){

    int last = -1;

    while(s<=e){
    
        int mid = (s+e)/2;

        if(arr[mid] == key){
            last = mid;
            s = mid + 1;
        }

        else if(arr[mid] < key){
            s = mid + 1;    
        }
 
        else{
            e = mid - 1;
        }
    }
    return last;
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
    int e = n - 1;

    int ans1 = first_occurence(arr,key,s,e);
    int ans2 = last_occurence(arr,key,s,e,n);

    cout<<ans1<<" "<<ans2;

    return 0;

}