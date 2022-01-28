class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        
        string prefix = strs[0];
        for(int i = 1 ; i < strs.size(); i++)
        {
            int c = 0 ; string res = "";
            for(char a:strs[i])
            {
                if( c >= prefix.size())
                    break;
                if(a == prefix[c++])
                    res += a;
                else
                    break;
            }
            prefix = res;
        }
        return prefix;
    }
};
