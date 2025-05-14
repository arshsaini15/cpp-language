#include<iostream>
using namespace std;

    int factorial(int num){
        int letanumber  = 1;

        for(int i=num;i>=1;i--){
            
            letanumber = letanumber * i;
        
        }
        return letanumber;
    }

    int main(){

        int n;
        cin>>n;
         
        cout<<factorial(n)<<endl;

        return 0;

    }
