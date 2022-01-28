class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        map<string,int>markers;
        int wl = words[0].size();
        int tl = wl * words.size();
        for(auto st : words){
            markers[st]++;
        }
        for(int i = 0 ; i < s.size() - tl + 1; i++){
            int cnt = 0;
            map<string,int>check;
            for(int j = i ; j < tl + i ; j += wl){
                string x = s.substr(j,wl);
                check[x]++;
                if(markers[x] && check[x] <= markers[x]){
                    cnt++;
                }
                else{
                    cnt = 0;
                    break;
                }
            }
            if(cnt == words.size()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
