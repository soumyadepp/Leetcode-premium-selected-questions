class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0){
            return 0;
        }
        stack<int>idx;
        vector<int>left(n);
        vector<int>right(n);
        for(int i = 0 ; i < n; i++){
            if(idx.empty()){
                idx.push(i);
                left[i] = 0;
            }
            else{
                while(!idx.empty() && heights[idx.top()] >= heights[i]){
                    idx.pop();
                }
                left[i] = idx.empty()?0:idx.top() + 1;
                idx.push(i);
            }
        }
        while(!idx.empty()){
            idx.pop();
        }
        for(int i = n - 1; i >= 0; i--){
            if(idx.empty()){
                idx.push(i);
                right[i] = n - 1;
            }
            else{
                while(!idx.empty() && heights[idx.top()] >= heights[i]){
                    idx.pop();
                }
                right[i] = idx.empty()?n - 1:idx.top() - 1;
                idx.push(i);
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans = max((right[i] - left[i] + 1)*heights[i],ans);
        }
        return ans;
    }
};
