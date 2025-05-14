// Vectors(Dynamic Array)

#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    cout<<endl;

    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }

    cout<<endl;

    for(auto element:v){
        cout<<element<<" ";
    }

    cout<<endl;

    v.pop_back();

    vector<int> v12(4,15);
    //In the above line 4 is size, 15 is the element present four times in vector.


    for(auto element:v12){
        cout<<element<<" ";
    }

    swap(v,v12);

    cout<<endl;

    vector<int>::iterator t;
    for(t=v12.begin();t!=v12.end();t++){
        cout<<*t<<" ";
    }

    sort(v.begin(),v.end());

    return 0;
}