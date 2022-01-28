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
    TreeNode* constructTree(vector<int>& nums,int low,int high)
    {
        if(low>high)
            return NULL;
        int mid=low+(high-low)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=constructTree(nums,low,mid-1);
        node->right=constructTree(nums,mid+1,high);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructTree(nums,0,nums.size()-1);
    }
};
