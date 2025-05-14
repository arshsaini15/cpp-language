#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> temp = {1,1,1,1,1,1,1,1};
    vector<vector<int> > ans;

    ans.push_back(temp);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans.size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}