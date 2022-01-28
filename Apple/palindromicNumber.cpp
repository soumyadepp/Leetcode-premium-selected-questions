class Solution {
public:
    bool isPalindrome(int x) {
        string p = to_string(x);
        string r = p;
        reverse(p.begin(),p.end());
        
        if( r == p)
            return true;
        else
            return false;
    }
};
