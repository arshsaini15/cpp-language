#include<iostream>
using namespace std;
int main(){

    int n;
    cin>>n;

    int arr[n];
    int count = 0;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<endl;
    int sum=0;

    for(int i=n;i<0;i--){
        sum = sum + (arr[i] * pow(2,count));
        count++;
    }
    
    cout<<sum<<endl;

    return 0;
}