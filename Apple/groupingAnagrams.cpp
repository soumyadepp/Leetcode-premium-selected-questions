class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(int i = 0 ; i < strs.size(); i++){
            string word = strs[i];
            sort(word.begin(),word.end());
            if(mp.find(word) != mp.end()){
                mp[word].push_back(strs[i]);
            }
            else{
                mp[word] = vector<string>{strs[i]};
            }
        }
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
