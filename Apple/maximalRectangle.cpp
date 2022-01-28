class Solution {
public:
    int histogramArea(int heights[],int n){
    vector<int>left(n);
    vector<int>right(n);
    stack<int>st;
    for(int i = 0 ; i < n; i++){
        if(st.empty()){
            st.push(i);
            left[i] = 0;
        }
        else{
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            left[i] = st.empty()?0:st.top() + 1;
            st.push(i);
        }
    }
    while(!st.empty()){
        st.pop();
    }
    for(int i = n - 1 ; i >= 0 ; i--){
        if(st.empty()){
            st.push(i);
            right[i] = n - 1;
        }
        else{
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            right[i] = st.empty()?n - 1 : st.top() - 1; 
            st.push(i);
        }
    }
    int maxAns = 0;
    for(int i = 0 ; i < n; i++){
        maxAns = max(maxAns,heights[i]*(right[i] - left[i] + 1));
    }
    return maxAns;
  }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0){
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m][n];
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 1 ; i < m ; i++){
            for(int j = 0 ; j < n; j++){
                if(dp[i][j] == 1){
                    dp[i][j] += dp[i-1][j];
                }
            }
        }
        int maxArea = 0;
        for(int i = 0 ; i < m ;i++){
            maxArea = max(maxArea,histogramArea(dp[i],n));
        }
        return maxArea;
    }
};
