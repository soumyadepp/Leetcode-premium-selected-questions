class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>helper;
        vector<int>res;
        int x,y;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(find(helper.begin(),helper.end(),target - nums[i])==helper.end())
            {
                helper.push_back(nums[i]);
            }
            else
            {
                x = nums[i];
                y = target - nums[i];
                break;
            }
        }
        int index1,index2;
        if(x == y)
        {
            for(int i = 0 ; i < nums.size() ; i++)
            {
                if(nums[i] == x)
                {
                    index1 = i;
                }
            }
            for(int i = 0 ; i < nums.size() ; i++){
                if(nums[i] == y && i !=index1)
                {
                    index2 = i;
                }
            }
        }
        else
        {
            for(int i = 0; i < nums.size() ;i++)
            {
                if(nums[i] == x)
                {
                    index1 = i;
                }
                if(nums[i] == y)
                {
                    index2 = i;
                }
            }
        }
        return {index1,index2};
       
    }
};
