class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(auto i : nums2)
        {
            nums1.push_back(i);
        }
        sort(nums1.begin(),nums1.end());
        
        if(int(nums1.size())%2 == 0)
        {
            double k = nums1[nums1.size()/2];
            double m = nums1[nums1.size()/2-1];
            return double((k+m)/2);
        }
        return nums1[nums1.size()/2];
    }
};
