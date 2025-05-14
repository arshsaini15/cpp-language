#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    // creation
    unordered_map<string,int> m;

    // insertion 1:
    pair<string, int> p = make_pair("arsh",3);
    m.insert(p);

    // insertion 2:
    pair<string, int> pair2("xyz",2);
    m.insert(pair2);

    // insertion 3:
    m["my"] = 1;
    m["name"] = 2;

    // search
    cout<< m["name"]<<endl;
    cout<<m.at("arsh")<<endl;

    // cout<<m.at("unknown_key")<<endl; "This will show error but the line below will not !"
    cout<<m["unknown_key"]<<endl;
    cout<<m.at("unknown_key")<<endl;

    // size
    cout<<m.size()<<endl;

    // to check presence
    cout<<m.count("bro")<<endl;

    // erase
    m.erase("name");
    cout<<m.size()<<endl;

    // diplay 1:
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    // display 2(iterator):
    unordered_map<string,int> :: iterator it = m.begin();
    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    return 0;
}