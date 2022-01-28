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
    bool isValidBST(TreeNode* root) {
       ios_base::sync_with_stdio(0);
        cin.tie(0);
       return isValidBSTHelper(root,NULL,NULL);
    }
    bool isValidBSTHelper(TreeNode* root,TreeNode* minm, TreeNode* maxm){
        if(!root) return true;
        
        if((minm && root -> val <= minm->val) || (maxm && root -> val >= maxm -> val)){
            return false;
        }
        return isValidBSTHelper(root->left,minm,root) && isValidBSTHelper(root->right,root,maxm);
    }
};
