// print properties of class

#include<iostream>
using namespace std;

class hero{

    public:

    int health;
    char level;

};

int main(){

    hero paul;
    paul.health = 100;
    paul.level = 'd';

    cout<<"health : "<< paul.health << endl;
    cout<<"level : "<< paul.level << endl;

    return 0;
}