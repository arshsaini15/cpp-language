#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int nextSmallerElement(int* arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top() != -1 && s.top() >= curr){
            s.pop();
        }
        // ans is stack ka top
        ans[i]=s.top();
        s.push(curr);
    }
    return ans;
}

int prevSmallerElement(int* arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }
        // ans is stack ka top
        ans[i]=s.top();
        s.push(curr);
    }
    return ans;
}

int LargestRectangularArea(int *height,int n){
    vector<int> next(n);

    next=nextSmallerElement(height,n);

    vector<int> prev(n);
    prev= prevSmallerElement(height, n);

    int area=INT_MIN;
    for(int i=0;i<n;i++){
        int l=height[i];
        int b=next[i]-prev[i]-1;

        if(next[i]==-1){
            next[i]=n;
        }

        int newArea=l*b;
        area=max(area,newArea);
    }
    return area;
}

int main(){

    int n=7;
    int height[]={2,1,3,4,5,6,1};
    
    cout<<LargestRectangularArea(height,n);


    return 0;
}