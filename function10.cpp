// take a number and replace its zeros with five...!]


#include<iostream>
using namespace std;


int ReverseTheNumber(int temp){
    int num = 0;
    while(temp>0){
    int lastdigit = temp %10;
    num = (num * 10) + lastdigit;
    temp = temp /10;
    }
    return num;
}


int convert_0to5(int n){

    int temp = 0;
    
    if(n==0){
        return 5;
    }

    else{

        while(n>0){
            int lastdigit = n%10;
            
            if(lastdigit == 0){
                lastdigit = 5;
            }

            temp = (temp*10) + lastdigit;
            n = n/10;
        }
    }

    return ReverseTheNumber(temp);

}


int main(){

    int n;
    cin>>n;

    cout<<convert_0to5(n);

    return 0;

}