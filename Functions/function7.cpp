#include<iostream>
using  namespace std;

int fact(int num){
    int letanumber = 1;
    for(int i=num;i>=1;i--){

        letanumber = letanumber *i;

    }
    return letanumber;

}

int main(){


    int n;
    cin>>n;

     for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<fact(i)/(fact(i-j)*fact(j));
        }
        cout<<endl;
    }

    return 0;
 
}