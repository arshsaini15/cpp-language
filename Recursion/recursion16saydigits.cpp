//say digits question ~love babbar using recursion...! 

#include<iostream>
#include<string>
using namespace std;

void saydigits(int n,string str[]){


//base case 
if(n==0){
    return;
}


// processing 
int digit = n % 10;
n = n/10;


//recursive call
saydigits(n,str);
cout << arr[digit] << " ";

}


int main(){

    int n;
    cin>>n;

    string str[10]={"zero","one","two",
    "three","four","five",
    "six","seven","eight","nine"};

    cout<<endl<<endl<<endl;
    
    saydigits(n,str);
    
    cout<<endl<<endl<<endl;

    return 0;

}