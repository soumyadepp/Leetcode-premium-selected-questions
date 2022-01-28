class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = -1;
        int i = 0 ;
        int j = n - 1;
        while(i<j)
        {
            int curr = min(height[i],height[j])*( j - i);
            maxArea = max(curr,maxArea);
            if(height[i] > height[j])
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return maxArea;
    }
};
