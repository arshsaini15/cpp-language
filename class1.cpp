// print size of an object using class


#include<iostream>
using namespace std;

class hero{

    // properties
    int health;

};

int main(){

    hero h1;

    cout<<"size : "<<sizeof(h1);

    return 0;
}