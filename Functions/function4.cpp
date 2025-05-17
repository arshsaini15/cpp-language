#include<iostream>
using namespace std;

int series(int num){

    int t1=0;
    int t2=1;
    int nexterm;

    for(int i=1;i<=num;i++){
    cout<<t1<<endl;
    nexterm =  t1 + t2;
    t1=t2;
    t2=nexterm;
  
    }

    return 0;

}   

    int main(){

        int n;
        cin>>n;

        cout<<series(n)<<endl;

    return 0;

    }
