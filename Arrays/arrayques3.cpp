#include<iostream>
using namespace std;
int main(){

    int a,b;
    cin>>a>>b;

    int c[10][10];

    int arr1[a][b];

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>arr1[i][j];
        }
    }

    cout<<endl;

    int arr2[a][b];

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>arr2[i][j];
        }
    }
    cout<<endl;

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            for(int k=0;k<b;k++){
            c[i][j] = arr1[i][k] * arr2[k][j];
            }
        }
    }

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}