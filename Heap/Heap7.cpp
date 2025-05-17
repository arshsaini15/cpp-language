// Is BT Heap?

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class heap{
    public:

    int arr[100];
    int size;

    heap(){
        size=0;
        arr[0]=-1;
    }

    void insert(int val){
        size+=1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[index],arr[parent]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};

int countnode(Node* root){
    if(root == NULL){
        return 0;
    }

    return countnode(root->left) + countnode(root->right) + 1;
}

bool isCBT(Node* root, int index, int count){
    if(root == NULL){
        return true;
    }
    if(index >= count){
        return false;
    }
    else{
        return isCBT(root->left, (index*2)+1, count) && isCBT(root->right, (index*2)+2, count);
    }
}

bool ismaxorder(Node* root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    if(root->left != NULL){
        return (root->data > root->left->data);
    }
    if(root->right){
        return (root->data > root->right->data);
    }
    return ismaxorder(root->left) && ismaxorder(root->right);
}

bool isHeap(Node* root){
    int index=0;
    int totalcount = countnode(root);
    if(isCBT(root, index, totalcount) && ismaxorder(root)){
        return true;
    }
    return false;
}

int main(){

    heap h;
    h.insert(5);
    h.insert(10);
    h.insert(1);
    h.insert(20);
    h.insert(3);

    // h.print(v);

    struct Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(4);

    bool ans = isHeap(root);
    if(ans){
        cout<<"Yes";
    }else{
        cout<<"No";
    }

    return 0;
}