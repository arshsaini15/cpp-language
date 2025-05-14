#include<iostream>
using namespace std;
int main()
{
    int i=1;
    int j=2;
    int k;
    k=i + j + i++ +j++ + ++i + ++j;
    cout<<i<<" "<<j<<" "<<" "<<k<<endl;
    /*firstly value of i was 1 and value of j was 2.Then
    i++ and j++ increases the value of i and j by 1,but 
    i=1 and j=2 adds up cause increment happens after the
    use of initial value.Now,as value of i=2 and j=3 then
    ++i and ++j increases value by one so value of i becomes
    3 and that of j becomes 4
    */
    return 0; 
}