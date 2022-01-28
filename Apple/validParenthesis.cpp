class Solution {
public:
    bool isValid(string s) {
        stack<char>inserter;
        map<char,char>brackets;
        brackets[')'] = '(';
        brackets['}'] = '{';
        brackets[']'] = '[';
        
        for(int i = 0 ; i < s.size(); i++)
        {
            if(s[i] == ']' || s[i] == '}' || s[i] == ')')
            {
                if(inserter.empty() || inserter.top() != brackets[s[i]])
                    return false;
                else if(inserter.top() == brackets[s[i]])
                    inserter.pop();
            }
            else
                inserter.push(s[i]);
        }
               return inserter.empty() == true;
    }
};
