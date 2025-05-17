#include<iostream>
using namespace std;
int main(){

    int n,m,o;
    cin>>n>>m>>o;

    int arr1[n][m];
    int arr2[m][o];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr1[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<o;j++){
            cin>>arr2[i][j];
        }
    }
    int ans[n][o];
    for(int i=0;i<n;i++){
        for(int j=0;j<o;j++){
            ans[i][j]=0;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<o;j++){
            for(int k=0;k<m;k++){
                ans[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<o;j++){
            cout<<ans[i][j]<<" ";
        }
    }


    return 0;
}