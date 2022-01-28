class Solution {
public:
    void permuteHelper(vector<int>&nums,vector<vector<int>>&perms,int idx){
        if(idx == nums.size() - 1){
            perms.push_back(nums);
            return;
        }
        for(int i = idx ; i < nums.size(); i++){
            swap(nums[idx],nums[i]);
            permuteHelper(nums,perms,idx + 1);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permuteHelper(nums,ans,0);
        return ans;
    }
};
