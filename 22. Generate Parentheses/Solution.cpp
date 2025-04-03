class Solution {
public:
    
    void helper(int n, string& s, vector<string>& ans, int open, int closed){
        if(open + closed == 2*n){
            ans.push_back(s);
            return;
        }
        if(open < n){
            s.push_back('(');
            helper(n, s, ans, open+1, closed);
            s.pop_back();
        }
        if(closed < open){
            s.push_back(')');
            helper(n, s, ans, open, closed+1);
            s.pop_back();
        }

    }    

    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> ans;
        helper(n, s, ans, 0, 0);
        return ans;
    }
};