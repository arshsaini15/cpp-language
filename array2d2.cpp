#include<iostream>
#include<math.h>
using namespace std;
int main(){

int n,m,target;
cin>>n>>m;
cin>>target;

int arr[n][m];

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>arr[i][j];
    }
}


bool found=false;
int r=0,c=m-1;

while(r<n && c>=0){
    if(arr[r][c] == target){
        found=true;
    }
    else if(arr[r][c] > target){
        c--; 
    }
    else{
        r++;
    }
}

if(found==true){
    cout<<"element found";
}
else{
    cout<<"element is not found";
}
    return 0;
}