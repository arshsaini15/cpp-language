#include<iostream>
using namespace std;
int main()
{   

    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxelement = INT_MIN;   

    for(int i=0;i<n;i++){
        maxelement = max(maxelement,arr[i]);
    }
    cout<<maxelement;

    return 0;
}
