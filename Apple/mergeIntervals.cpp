class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>res;
        
        if(n == 0) return res;
        
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        int j = 0;
        for(int i = 1 ; i < n ; i++){
            if(res[j][1] >= intervals[i][0]){
                res[j][1] = max(intervals[i][1],res[j][1]);
            }
            else{
                j++;
                res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
};
