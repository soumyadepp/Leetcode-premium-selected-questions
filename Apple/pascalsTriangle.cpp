class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        if(numRows == 1){
            ans.push_back(vector<int>{1});
            return ans;
        }
        int dp[numRows][numRows];
        for(int i = 0 ; i < numRows; i++){
            for(int j = 0 ; j < numRows;j++){
                dp[i][j] = 0;
            }
        }
        for(int i = 0 ; i < numRows; i++){
            dp[i][0] = 1;
            dp[i][i] = 1;
        }
        for(int i = 2 ; i < numRows; i++){
            for(int j = 1 ; j < i ; j++){
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
        for(int i = 0 ; i < numRows ; i++){
            vector<int>temp;
            for(int j = 0 ; j <= i ; j++){
                temp.push_back(dp[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
