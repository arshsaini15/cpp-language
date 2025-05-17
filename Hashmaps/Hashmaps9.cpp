// Top K Frequent Elements.

#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

void TopKelements(int arr[], int n, int k){
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }

    vector<pair<int, int> > ans;
    unordered_map<int,int> :: iterator it;

    for(it = m.begin(); it != m.end(); it++){
        if(it->second != 0){
            ans.push_back(make_pair(it->second,it->first));
        }
    }
    sort(ans.begin(),ans.end(),greater<pair<int,int> >());

    vector<pair<int,int> > :: iterator it1;
    for(it1 = ans.begin(); it1 != ans.end(); it1++){
        cout<<it1->second<<" "<<it1->first<<endl;
    }

    cout << "Top " << k << " frequent elements:" << endl;
    for(int i = 0; i < k && i < ans.size(); ++i){
        cout << ans[i].second << " appears " << ans[i].first << " times" << endl;
    }
}

int main(){

    int arr[] = {1,2,2,2,3};
    TopKelements(arr,5,2);

    return 0;
}