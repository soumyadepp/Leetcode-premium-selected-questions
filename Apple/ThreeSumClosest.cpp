class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       int n = nums.size();
        if(n < 3){
            return -1;
        }
        int ans = nums[0] + nums[1] + nums[n - 1];
        sort(nums.begin(),nums.end());
        int minDiff = INT_MAX;
        for(int i = 0 ; i < n - 2 ; i++){
            int start = i + 1;
            int end = n - 1;
            while(start < end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == target) return target;
                else if(sum < target){
                    start++;
                }
                else{
                    end--;
                }
                if(abs(sum - target) < minDiff){
                    minDiff = abs(sum - target);
                    ans = sum;
                }
            } 
        }
        return ans;
    }
};
