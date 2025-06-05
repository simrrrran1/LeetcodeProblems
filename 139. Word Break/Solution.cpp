class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[n] = true;

        for(int i=n-1; i>=0; i--){
            for(string s1: wordDict){
                if(i+ s1.size() <= n && s.substr(i, s1.size()) == s1)
                    dp[i] = dp[i + s1.size()];
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }
};