// Zig Zag Level Order Traversal.

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> finalans;
        if(root == NULL) return finalans;

        vector<int> temp;
        queue<TreeNode*> q;
        bool flag = false;
        
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node != NULL){
                temp.push_back(node->val);
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            else{
                if(flag){
                    reverse(temp.begin(), temp.end());
                }
                finalans.push_back(temp);
                temp.clear();

                if(!q.empty()){
                    q.push(NULL);
                }
                flag = !flag;
            }
        }
        return finalans;
    }
};

int main(){

    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int> > pattern = sol.zigzagLevelOrder(root);
    for(int i=0; i<pattern.size(); i++){
        for(int j=0; j<pattern[i].size(); j++){
            cout << pattern[i][j] << " ";
        }
    }

    return 0;
}