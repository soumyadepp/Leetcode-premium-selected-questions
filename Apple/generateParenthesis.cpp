class Solution {
public:
    void parenthesisGenerator(int lp,int rp,vector<string>&ans,string current){
        if(lp == 0 && rp == 0){
            ans.push_back(current);
        }
        if(lp != 0){
            string c1 = current;
            c1 += "(";
            parenthesisGenerator(lp-1,rp,ans,c1);
        }
        if(rp > lp){
            string c2 = current;
            c2 += ")";
            parenthesisGenerator(lp,rp-1,ans,c2);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        parenthesisGenerator(n,n,ans,"");
        return ans;
    }
};
