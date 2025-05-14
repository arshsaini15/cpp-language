// print propeties of class using private acccess modifier outside the class using getter and setter

#include<iostream>
using namespace std;

class Hero {

    private:
    int health;

    public:
    char level;

    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health  = h;
    }

    void setLevel(char ch){
        level = ch; 
    }
};

int main(){

    Hero paul;
    cout << "paul's health is :" << paul.getHealth() << endl;

    paul.setHealth(100);
    paul.setLevel('A');

    cout<<"health : "<< paul.getHealth() << endl;
    cout<<"level : "<< paul.getLevel() << endl;

    return 0;
}