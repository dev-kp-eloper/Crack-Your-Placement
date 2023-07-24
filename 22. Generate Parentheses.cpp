//Link - https://leetcode.com/problems/generate-parentheses/description/

class Solution {
public:
    void solve(int open, int close, string ds, vector<string>& ans, int n){
        if(ds.size() == 2*n){
            ans.push_back(ds);
            return;
        }
        if(open < n){
            ds.push_back('(');
            solve(open+1,close,ds,ans,n);
            ds.pop_back();
        }
        if(open > close){
            ds.push_back(')');
            solve(open,close+1,ds,ans,n);
            ds.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;

        string ds = "";
        vector<string> ans;
        if(n == 0) return ans;
        solve(open,close,ds,ans,n);
        return ans;
    }
};
