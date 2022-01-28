class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxTillNow = nums[0];
        int maxEndingHere = nums[0];
        for(int i = 1 ; i < nums.size(); i++){
            maxEndingHere = max(maxEndingHere + nums[i], nums[i]);
            maxTillNow = max(maxTillNow,maxEndingHere);
        }
        return maxTillNow;
    }
};
