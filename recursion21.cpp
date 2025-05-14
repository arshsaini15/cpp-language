//linear search using recursion...!

#include<iostream>
using namespace std;


int LinearSearch(int arr[],int n,int key,int index){

    //base case
    if(n==0){
        return -1;
    }
  
    //processing
    if(arr[0]==key){
        return index;
    }
    
    index += 1;  

    //recursive call
    int RemainingPart = LinearSearch(arr+1,n-1,key,index);
    return RemainingPart;

}


int main(){

int index = 0;
int n,key;

cout<<"enter number of elements in an array"<<endl;
cin>>n;

int  arr[n];

cout<<"enter the elements of array"<<endl;
for(int i=0;i<n;i++){
    cin>>arr[i];
}

cout<<"enter the element which we have to find"<<endl;
cin>>key;

cout<<LinearSearch(arr,n,key,index); 
 
return 0;

}