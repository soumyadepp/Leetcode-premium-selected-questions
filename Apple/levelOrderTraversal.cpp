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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*>bfsQueue;
        bfsQueue.push(root);
        map<TreeNode*,int>levels;
        map<int,vector<int>>mp;
        int l = 0;
        levels[root] = 0;
        mp[0].push_back(root->val);
        while(!bfsQueue.empty()){
            TreeNode* front = bfsQueue.front();
            bfsQueue.pop();
            if(front->left){
                bfsQueue.push(front->left);
                levels[front->left] = levels[front] + 1;
                mp[levels[front->left]].push_back(front->left->val);
            }
            if(front->right){
                bfsQueue.push(front->right);
                levels[front->right] = levels[front] + 1;
                mp[levels[front->right]].push_back(front->right->val);
            }
        }
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
