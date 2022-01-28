class Solution {
public:
    int longestValidParentheses(string s) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(0);
        stack<int>brackets;
        if(s.size() == 0)
            return 0;
        int maxCount = 0;
        brackets.push(-1);
        for(int i = 0 ; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                brackets.push(i);
            }
            else
            {
                brackets.pop();
                if(brackets.empty())
                    brackets.push(i);
                else
                    maxCount = max(maxCount,i - brackets.top());
            }
        }
        return maxCount;
    }
};
