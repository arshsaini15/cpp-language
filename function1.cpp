#include<iostream>
using namespace std;

int add(int num1, int num2)/*here num1 and num2 are 
local variables they get destroyed after excution.*/
   { int sum = num1+num2;
    return sum;
}

int main(){

    int a=2;
    int b=3;
    
    
    cout<<add(a,b)<<endl;

    return 0; 

}