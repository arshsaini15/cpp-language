// reach home question ~love babber using recursion

#include<iostream>
using namespace std;

void reachHome(int src,int dest){

    //base case
    if(src==dest){
        cout<<"pahuch gaya"<<endl;
        return;
    } 

    //processing -- ek step aage badh jao
    //  src++:
 
    //recursive call

    reachHome(src+1,dest); 

}


int main(){

    int dest = 10;
    int src = 1;

    cout<<endl;

    reachHome(src,dest);


    return 0;
}