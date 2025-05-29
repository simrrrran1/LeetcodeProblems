class Solution {
public:
    void fnc(int n, int open, int closed, string s, vector<string>& ans){
        if(open + closed == 2*n){
            ans.push_back(s);
            return;
        }
        if(open < n){
            s.push_back('(');
            fnc(n, open+1, closed, s, ans);
            s.pop_back();
        }
        if(closed < open){
            s.push_back(')');
            fnc(n, open, closed+1, s, ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        fnc(n, 0, 0, s, ans);

        return ans;
    }
};