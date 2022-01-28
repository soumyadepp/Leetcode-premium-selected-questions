class Solution {
public:
int binarySearch(vector<int>arr,int left,int right,int target){
    int l = left;
    int r = right;
    while(l <= r){
        int mid = l + (r - l)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return -1;
}
int search(vector<int>&nums,int target){
    if(nums.size() == 0){
        return -1;
    }
    int l = 0;
    int h = nums.size() - 1;
    while(l < h){
        int mid =(l + h)/2;
        if(nums[mid] >= nums[0]){
            l = mid + 1;
        }
        if(nums[mid] < nums[0]){
            h = mid;
        }
    }
    int f = binarySearch(nums,0,l-1,target);
    int s = binarySearch(nums,l,nums.size()-1,target);
    return max(f,s);
}
};
