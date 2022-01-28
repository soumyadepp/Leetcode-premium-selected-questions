class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dictionary;
        for(auto i : wordDict){
            dictionary.insert(i);
        }
        if(dictionary.size() == 0) return false;
        
        int n = s.size();
        
        vector<bool>dp(n + 1,0);
        dp[0] = true;
        for(int i = 1 ; i <= n ; i++){
            for(int j = i - 1 ; j >=0 ; j--){
                if(dp[j] == true){
                    string findWord = s.substr(j,i - j);
                    if(dictionary.find(findWord) != dictionary.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};
