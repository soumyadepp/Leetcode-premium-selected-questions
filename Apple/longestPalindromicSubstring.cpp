Here we are creating a function f which will simply traverse the string and store the max length of
longest palindromic substring. Note substring is not same as subsequence.
*/
class Solution {
public:
    void f(int &l,int &r, string &str,int &n, int &max_len, int &start)
    {
        while(l>=0 && r<str.length() && str[l]==str[r])
            {
                int len=r-l+1;
                if(len > max_len){
				    max_len = len;
                    start = l; //store the start index of the max length LPS
                }
                l--;r++; //expanding from centre towards left and right, if palindrome exists
            }
    }
    string longestPalindrome(string str) 
    {
        string ans; //store the answer here
        int max_len = 0; //maxlength is 0 initially
        int start, end; //store the start and end pointers used in traversing the string.
        int n = str.size(); //length of the string.
        for(int i=0;i<n;i++) //for loop for every index i.
        {
            int l = i, r = i; // same centre odd LPS
            f(l,r,str,n,max_len,start);
            l = i; r = i+1; //start and end are same character but seperated EVEN LPS
            f(l,r,str,n,max_len,start);
        }
        return str.substr(start, max_len); return max length substr.
    }
};
