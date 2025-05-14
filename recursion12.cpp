// print counting using recursion

#include<iostream>
using namespace std;

void count(int n){

    // base case
    if(n==0){
        return;
    }

    // recursive relation
    count(n-1);
    cout<<n<<endl;

}


int main(){

    int n;
    cin>>n;

    cout<<endl;
    count(n);

    return 0;
}