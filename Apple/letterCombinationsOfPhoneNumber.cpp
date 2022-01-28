class Solution {
public:
    vector<string>result;
    
    void letterCombinationHelper(string &digits, map<char,vector<char>>&mp,string &temp,int count)
    {
        if(count == digits.size())
        {
            result.push_back(temp);
        }
        
        for(int i = 0 ; i < mp[digits[count]].size(); i++)
        {
            temp += mp[digits[count]][i];
            letterCombinationHelper(digits,mp,temp,count+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
        {
            return {};
        }
        map<char , vector<char>>mp;
        vector<string>res;
        mp['2'] = {'a','b','c'};
        mp['3'] = {'d','e','f'};
        mp['4'] = {'g','h','i'};
        mp['5'] = {'j','k','l'};
        mp['6'] = {'m','n','o'};
        mp['7'] = {'p','q','r','s'};
        mp['8'] = {'t','u','v'};
        mp['9'] = {'w','x','y','z'};
        
        string temp;
        letterCombinationHelper(digits,mp,temp,0);
        return result;
    }
    
};
