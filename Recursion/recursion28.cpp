// Calculate Power Using Recursion

#include<iostream>
#include<string>
using namespace std;

int power(int a, int b){

    //base case
    if(b==0){
        return 1;
    }

    //rcursive call
    int ans =  a * power(a,b-1);
    return ans;
}

int main(){

    int a,b;
    cin>>a>>b;

    cout<<power(a,b);

    return 0 ;

}