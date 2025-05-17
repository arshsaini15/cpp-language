/* Hash Functions :
1.Hash Code (conversion to int).
2.Compression Function (Take int from hash code in Range). */

#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    unordered_map<int,int> m;
    int arr[] = {1,2,3,4,5,1};
    for(int i=0;i<6;i++){
        m[arr[i]]++;
    }

    auto i = m.find(2);
    if(i != m.end()){
        cout<<i->second<<" ";
    }else{
        cout<<"Not Found"<<" ";
    }cout<<endl<<endl;

    unordered_map<int,int> :: iterator it = m.begin();
    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    return 0;
}