#include<iostream>
using namespace std;
class A {
    public:
        A() {
            cout << "contructor called";
        }
};

int main() {
    A a;

    return 0;
}