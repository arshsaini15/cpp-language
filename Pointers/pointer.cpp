#include<iostream>
using namespace std;

int main() {
    int x = 5;

    // cout << "x's value before: " << x << endl;

    int *ptr = &x;
    *ptr = 11;

    // cout << "x's values after: " << x;

    cout << ptr << " " << *ptr;

    return 0;
}