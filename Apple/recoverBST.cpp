/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int i = 0;
    void preorderStore(TreeNode* root,vector<int>&store){
        if(!root) return;
        store.push_back(root -> val);
        preorderStore(root->left,store);
        preorderStore(root->right,store);
    } 
    void recoverTree(TreeNode* root) {
        vector<int>v;
        preorderStore(root,v);
        sort(v.begin(),v.end());
        buildTree(root,v);
    }
    void buildTree(TreeNode* root,vector<int>v){
        if(!root) return; 
        buildTree(root->left,v);
        if(root->val != v[i]){
            root -> val = v[i];
        }
        i++;
        buildTree(root->right,v);
    }
};
