nqueen

#include<iostream>
using namespace std;

bool issafe(int** arr ,int x ,int y ,int n){
    for(int row=0;row<x;row++){
       if(arr[row][y]==1){
        return false;
       }
    }
    int row=x;
    int col=y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }
    row=x;
    col=y;
    while(row>=0 && col<n){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nQueen(int** arr ,int x, int n){
    if(x>=n){
        return true;
    }
    for(int col=0;col<n;col++){
        if(issafe(arr,x,col,n)){
            arr[x][col]=1;
            if(nQueen(arr,x+1,n)){
                return true;
            }
            arr[x][col]=0;
        }
    }
    return false;
}

int main(){
   int n;
   cin>>n;
   int** arr=new int*[n];
   for(int i=0;i<n;i++){
    arr[i]=new int[n];
    for(int j=0;j<n;j++){
        arr[i][j]=0;
    }

   }
   if(nQueen(arr,0,n)){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout << endl;
    }
   }
}
























rat in maze

#include<iostream>
using namespace std;

bool issafe(int** arr,int x ,int y,int n){
    if(x<n  && y<n && arr[x][y]==1){
        return true;
    }
    return false;
}
bool RatMaze(int** arr,int x,int y,int n,int** solArr){
    if(x==n-1 && y==n-1){
        solArr[x][y]=1;
        return true;
    }
    if(issafe(arr,x,y,n)){
        solArr[x][y]=1;
        if(RatMaze(arr ,x+1,y,n,solArr)){
            return true;
        }
        if(RatMaze(arr ,x,y+1,n,solArr)){
            return true;
        }
        solArr[x][y]=0;
        return false;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int** solArr =new int*[n];
    for(int i=0;i<n;i++){
        solArr[i]=new int[n];
        for(int j=0;j<n;j++){
            solArr[i][j]=0;
        }
    }
    if(RatMaze(arr,0,0,n,solArr)){
         for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solArr[i][j]<<" ";
        }
        cout<<endl;
    }

    }
}

















sum of subset

#include <iostream>

using namespace std;

int maxSubsetSumNoAdjacent(int arr[], int n) {
    if (n == 0) return 0;
    if (n == 1) return arr[0];

    int max0 = arr[0];
    int max1;

   
    if (arr[0] > arr[1]) {
        max1 = arr[0];
    } else {
        max1 = arr[1];
    }

    for (int i = 2; i < n; i++) {
        int current;
        
        if (max1 > (max0 + arr[i])) {
            current = max1;
        } else {
            current = max0 + arr[i];
        }
        max0 = max1;
        max1 = current;
    }

    return max1;
}

int main() {
    int arr[] = {3, 2, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum sum of non-adjacent elements: " << maxSubsetSumNoAdjacent(arr, n) << endl;
    return 0;
}














string compression

#include<iostream>
using namespace std;

    
    


string compress(string str){
    string compressedstring;
    int count =0;
    char currentchar=str[0];
    sort(str.begin(),str.end());
   
    for(int i=0;i<str.length();i++){
        if(str[i]==currentchar){
            count++;
        }
        else{
           if (count > 1) {
                compressedstring += currentchar + to_string(count);
            } else {
                compressedstring += currentchar; 
            }
            count=1;
            currentchar=str[i];
        }
    }
    if (count > 1) {
                compressedstring += currentchar + to_string(count);
            } else {
                compressedstring += currentchar; 
            }
    return compressedstring;

}


int main(){
     string str;
     getline(cin,str);
  
     string compressed=compress(str);
     cout<<compressed<<endl;

}








subset of array

#include <iostream>
using namespace std;

// Function to find the subsets of the given array
void findSubsets(int nums[], int n)
{
    // Loop through all possible subsets using bit manipulation
    for (int i = 0; i < (1 << n); i++) {

        // Loop through all elements of the input array
        for (int j = 0; j < n; j++) {

            // Check if the jth bit is set in the current subset
            if ((i & (1 << j)) != 0) {

                // If the jth bit is set, add the jth element to the subset
                cout << nums[j] << " ";
            }
        }

        cout << endl;
    }
}

// Driver Code
int main()
{
    int arr[] = { 1, 2, 3 };
    int n = sizeof(arr)/sizeof(arr[0]);
    findSubsets(arr, n);
}









inorder preorder post order


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert nodes in level order
Node* insertLevelOrder(int arr[], Node* root, int i, int n) {
    if (i < n) {
        Node* temp = new Node(arr[i]);
        root = temp;

        // Insert left child
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        // Insert right child
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

// Preorder traversal
void preorder(Node *root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal
void inorder(Node *root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Postorder traversal
void postorder(Node *root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    int n;
    cout << "Enter number of elements in the tree: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter " << n << " elements for the tree: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = nullptr;
    root = insertLevelOrder(arr, root, 0, n);

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}







bottom view


#include<iostream>
#include<vector>
#include<map>
using namespace std;

void maping(map<int,int>&mp,int index,int n,vector<int>&arr,int cur){
    if(index>=arr.size() ) return;
    if(arr[index]==-1) return;
    mp[cur]=arr[index];
    maping(mp,index*2+1,n,arr,cur-1);
    maping(mp,index*2+2,n,arr,cur+1);

}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    map<int,int>mp;
    maping(mp,0,n,arr,0);
    for(auto it:mp){
        cout <<it.second<<" ";
    }
}



left view



#include<iostream>
#include<vector>
#include<map>
using namespace std;

void maping(map<int,int>&mp,int index,int n,vector<int>&arr,int cur){
    if(index>=arr.size() ) return;
    if(arr[index]==-1) return;
    if(mp.find(cur)==mp.end())mp[cur]=arr[index];
    maping(mp,index*2+1,n,arr,cur+1);
    maping(mp,index*2+2,n,arr,cur+1);

}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    map<int,int>mp;
    maping(mp,0,n,arr,0);
    for(auto it:mp){
        cout <<it.second<<" ";
    }
}



right view


#include<iostream>
#include<vector>
#include<map>
using namespace std;

void maping(map<int,int>&mp,int index,int n,vector<int>&arr,int cur){
    if(index>=arr.size() ) return;
    if(arr[index]==-1) return;
    mp[cur]=arr[index];
    maping(mp,index*2+1,n,arr,cur+1);
    maping(mp,index*2+2,n,arr,cur+1);

}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    map<int,int>mp;
    maping(mp,0,n,arr,0);
    for(auto it:mp){
        cout <<it.second<<" ";
    }
}






top view

#include<iostream>
#include<vector>
#include<map>
using namespace std;

void maping(map<int,int>&mp,int index,int n,vector<int>&arr,int cur){
    if(index>=arr.size() ) return;
    if(arr[index]==-1) return;
    if(mp.find(cur)==mp.end())mp[cur]=arr[index];
    maping(mp,index*2+1,n,arr,cur-1);
    maping(mp,index*2+2,n,arr,cur+1);

}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    map<int,int>mp;
    maping(mp,0,n,arr,0);
    for(auto it:mp){
        cout <<it.second<<" ";
    }
}







vertical transversal


#include<iostream>
#include<vector>
#include<map>
using namespace std;

void maping(map<int,map<int,vector<int> > >&mp,int index,int n,vector<int>&arr,int col,int row){
    if(index>=arr.size() ) return;
    if(arr[index]==-1) return;
    mp[col][row].push_back(arr[index]);
    maping(mp,index*2+1,n,arr,col-1,row+1);
    maping(mp,index*2+2,n,arr,col+1,row+1);
}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    map<int,map<int,vector<int> > >mp;
    maping(mp,0,n,arr,0,0);
    vector<int>ans;
    for(auto it:mp){
        for(auto temp:it.second){
            sort(temp.second.begin(),temp.second.end());
            for(auto i:temp.second) ans.push_back(i);
        }
    }
    for( auto it:ans) cout << it<<" ";
    cout <<endl;
}





check bst


#include<iostream>
#include<vector>
using namespace std;

void check_BST(int index,int n,vector<int>&arr,bool &ans,int lower,int upper){
    if(index>=n ) return ;
    if(arr[index]==-1) return ;
    check_BST(index*2+1,n,arr,ans,lower,arr[index]);
    check_BST(index*2+2,n,arr,ans,arr[index],upper);
    if(arr[index]>upper || arr[index]<lower) ans=false;
    return ;

}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    bool ans=true;

    check_BST(0,n,arr,ans,INT_MIN,INT_MAX);
    if(ans) cout <<"yes"<<endl;
    else cout<<"No"<<endl;
}




check cbt


#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    while(n>0 && arr[n-1]==-1)n--;

    for(int i=0;i<n;i++){
        if(arr[i]<0){
            cout << "NO"<<endl;
            return 0;
        } 
    }
    cout << "YES"<<endl;

}




full tree


#include<iostream>
#include<vector>
using namespace std;

int rec(vector<int>&arr,int index,bool&ans){
    if(index>=arr.size() || arr[index]==-1) return -1;
    int left=rec(arr,index*2+1,ans);
    int right=rec(arr,index*2+2,ans);
    if((left==-1 && right!=-1) || (left!=-1 && right==-1)) ans=false;
    return arr[index];
}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    while(n>0 && arr[n-1]==-1)n--;
    bool ans=true;
    rec(arr,0,ans);
    if(ans) cout << "YES\n";
    else cout <<"NO\n";

}




check heep

#include<iostream>
#include<vector>
using namespace std;

int check_heap(int index,int n,vector<int>&arr,bool &ans){
    if(index>=n ) return INT_MIN;
    if(arr[index]==-1) return INT_MIN;
    int left=check_heap(index*2+1,n,arr,ans);
    int right=check_heap(index*2+2,n,arr,ans);
    if(arr[index]<left || arr[index]<right) ans=false;
    return arr[index];

}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    bool ans=true;

    for(int i=0;i<n;i++){
        if(arr[i]<0) ans=false;
    }
    check_heap(0,n,arr,ans);
    if(ans) cout <<"yes"<<endl;
    else cout<<"No"<<endl;
}




check height

#include<iostream>
#include<vector>
using namespace std;

int check_balanced(bool &ans,int index,vector<int>&arr){
    if(index>=arr.size() ) return 0;
    if(arr[index]==-1) return 0;

    int left=check_balanced(ans,index*2+1,arr);
    int right=check_balanced(ans,index*2+2,arr);

    if(abs(left-right)>1){
        ans=false;
    }
    return max(left,right)+1;
}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    bool ans=true;
    check_balanced(ans,0,arr);
    if(ans) cout <<"yes"<<endl;
    else cout<<"No"<<endl;
    
}




check perfect

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    bool ans=true;

    for(int i=0;i<n;i++){
        if(arr[i]<0) ans=false;
    }
    
    int temp=log2(n+1);
    if(log2(n+1)!=temp)ans=false;
    
    if(ans) cout <<"yes"<<endl;
    else cout<<"No"<<endl;
}





level order to binary tree


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    int index=1;
    Node* root=new Node(arr[0]);
    queue<Node*>q;
    q.push(root);
    while(index<n && !q.empty()){
        Node* front=q.front();
        q.pop();
        if(arr[index]==-1){
            front->left=NULL;
        }else{
            Node* l=new Node(arr[index]);
            front->left=l;
            q.push(l);
        }
        index++;

        if(index<n){
            if(arr[index]==-1){
                front->right=NULL;
            }else{
                Node* r=new Node(arr[index]);
                front->right=r;
                q.push(r);
            }
        }
        index++;
    }
}





diameter of tree


#include<iostream>
#include<vector>
using namespace std;

int find_diameter(int index,int n,vector<int>&arr,int &ans){
    if(index>=n ) return 0;
    if(arr[index]==-1) return 0;
    int left=find_diameter(index*2+1,n,arr,ans);
    int right=find_diameter(index*2+2,n,arr,ans);
    int temp=left+right;
    ans=max(ans,temp);
    return max(left,right)+1;

}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    int ans=0,cur=0;
    cout <<endl;
    find_diameter(0,n,arr,ans);
    cout << ans<<endl;
}





balanced bracket

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    string s;
    cin >> s;
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(st.empty())st.push(s[i]);
        else {
            if(s[i]=='}' && st.top()=='{')st.pop();
            else if(s[i]==']' && st.top()=='[')st.pop();
            else if(s[i]==')' && st.top()=='(')st.pop();
            else st.push(s[i]);
        }
    }
    if(st.empty()) cout <<"YES"<<endl;
    else cout << "NO"<<endl;
}



house robber


#include<iostream>
#include<vector>
using namespace std;

void rec(vector<int>&arr,int index,int cur,int&ans){
    if(index>=arr.size()){
        ans=max(ans,cur);
        return;
    }
    rec(arr,index+2,cur+arr[index],ans);
    rec(arr,index+1,cur,ans);

}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    int ans=0;
    rec(arr,0,0,ans);
    cout <<ans<<endl;

}



grid ways

#include<iostream>
#include<vector>
using namespace std;

void rec(vector<vector<int> >&arr,int rows,int cols,int i,int j,int cur,int &ans){
    if(i>=rows || j>=cols) return;
    cur+=arr[i][j];
    if(i==rows-1 && j==cols-1){
        ans=min(cur,ans);
    }
    rec(arr,rows,cols,i+1,j,cur,ans);
    rec(arr,rows,cols,i,j+1,cur,ans);

}

int main(){
    int rows,cols;
    cin >> rows>>cols;
    vector<vector<int> > arr(rows,vector<int>(cols));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin >> arr[i][j];
        }
    }
    int ans=INT_MAX;
    rec(arr,rows,cols,0,0,0,ans);
    cout << ans<<endl;
}



ways to climb stairs


#include<iostream>
#include<vector>
using namespace std;

void rec(int n,int &ans){
    if(n<0){
        return;
    }else if(n==0){
        ans++;
        return;
    }
    rec(n-1,ans);
    rec(n-2,ans);
}

int main(){
    int n;
    cin >> n;
    int ans=0;
    // rec(n,ans);
    // cout << ans<<endl;

    // using dp
    vector<int>dp(n,-1);
    dp[n-1]=1;
    dp[n-2]=2;
    for(int i=n-3;i>=0;i--) dp[i]=dp[i+1]+dp[i+2];
    cout << dp[0]<<endl;

}




nqueen

#include<iostream>
#include<vector>
using namespace std;

bool check(int i,int j,vector<vector<int> >&arr,int n){
    bool hor=true,ver=true,left=true,right=true;
    for(int k=0;k<n;k++){
        if(arr[i][k]==1)hor=false; 
        if(arr[k][j]==1) ver=false;
    }
    int row=i,col=j;
    while(row>=0 && col>=0){
        if(arr[row][col]==1) left=false;
        row--;
        col--;
    }

    row=i,col=j;
    while(row>=0 && col<n){
        if(arr[row][col]==1) right=false;
        row--;
        col++;
    }
    return hor && ver && left&&right;
}

void rec(int i,vector<vector<int> >&arr,int n){
    if(i==n){
        for(auto it:arr){
            for(auto it2:it) cout << it2<< " ";
            cout <<endl;
        }
        cout << endl;
        return;
    }
    for(int j=0;j<n;j++){
        if(check(i,j,arr,n)){
            arr[i][j]=1;
            rec(i+1,arr,n);
            arr[i][j]=0;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int> > arr(n,vector<int>(n,0));
    rec(0,arr,n);
}



ratin maze

#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int> >&arr,int rows,int cols,int i,int j, string ans){
    if(i<0 || i>=rows || j<0 || j>cols || arr[i][j]==0){
        return;
    } 
    if(i==rows-1 && j==cols-1){
        cout << ans<<endl;
        return;
    }
    arr[i][j]=0;
    solve(arr,rows,cols,i+1,j,ans+"D");
    solve(arr,rows,cols,i-1,j,ans+"U");
    solve(arr,rows,cols,i,j+1,ans+"R");
    solve(arr,rows,cols,i,j-1,ans+"L");
    arr[i][j]=1;
}

int main(){
    int rows,cols;
    cin >> rows>>cols;
    vector<vector<int> > arr(rows,vector<int>(cols));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin >> arr[i][j];
        }
    }
    solve(arr,rows,cols,0,0,"");

}





first -ve

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    int k;
    cin >> k;
    queue<int>q;
    for(int i=0;i<k-1;i++){
        if(arr[i]<0) q.push(i);
    }
    for(int i=k-1;i<n;i++){
        if(arr[i]<0)q.push(i);
        while(!q.empty() && q.front()<=i-k) q.pop();
        if(q.empty()) cout << "0 ";
        else cout << arr[q.front()]<< " ";
    }
    cout << endl;
}



string subset

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void subsets(string cur,string &s,int index){
    if(index>=s.size()){
        cout << cur<<endl;
        return;
    }
    subsets(cur+s[index],s,index+1);
    subsets(cur,s,index+1);
}

int main(){
    string s;
    cin >>s;
    subsets("",s,0);
}



first non repeating char

#include<iostream>
#include<map>
#include<queue>
using namespace std;

int main(){
    string s;
    cin >>s;
    map<char,int>mp;
    queue<char>q;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
        q.push(s[i]);
        while(!q.empty() && mp[q.front()]>1)q.pop();
        if(q.empty()) cout << "-1"<<" ";
        else cout << q.front()<< " ";
    }
    cout << endl;
}




delete node

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

Node* newNode(int item) {
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

Node* insert(Node* node, int key) {
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

Node* deleteNode(Node* root, int k) {
    if (root == NULL)
        return root;
    if (k < root->key)
        root->left = deleteNode(root->left, k);
    else if (k > root->key)
        root->right = deleteNode(root->right, k);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* succParent = root;
        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        root->key = succ->key;
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        delete succ;
    }
    return root;
}

int main() {
    vector<int> elements;
    int numElements, element;
    
    cout << "Enter the number of elements to insert into the BST: ";
    cin >> numElements;
    
    cout << "Enter the elements: ";
    for (int i = 0; i < numElements; i++) {
        cin >> element;
        elements.push_back(element);
    }
    
    Node* root = NULL;
    for (int elem : elements) {
        root = insert(root, elem);
    }
    
    cout << "Original BST: ";
    inorder(root);
    cout << endl;
    
    // Deletion part
    vector<int> deletions;
    int numDeletions;
    
    cout << "Enter the number of nodes to delete: ";
    cin >> numDeletions;
    
    cout << "Enter the nodes to delete: ";
    for (int i = 0; i < numDeletions; i++) {
        cin >> element;
        deletions.push_back(element);
    }
    
    for (int del : deletions) {
        cout << "\nDeleting " << del << endl;
        root = deleteNode(root, del);
        cout << "BST after deletion: ";
        inorder(root);
        cout << endl;
    }

    return 0;
}