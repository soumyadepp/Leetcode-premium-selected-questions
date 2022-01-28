class Solution {
public:
    int lower_bound(vector<int>&nums,int target){
        int lo = 0;
        int hi = nums.size() - 1;
        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target){
                ans = mid;
                hi = mid - 1;
            }
            else if(nums[mid] < target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
    int upper_bound(vector<int>nums,int target){
        int lo = 0;
        int hi = nums.size() - 1;
        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target){
                ans = mid;
                lo = mid + 1;
            }
            else if(nums[mid] < target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int>{lower_bound(nums,target),upper_bound(nums,target)};
    }
};
