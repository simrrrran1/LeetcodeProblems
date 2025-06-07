class Solution {
public:
    bool dfs(string s1, unordered_map<string, bool>& dp, unordered_set<string>& s){
        if(dp.count(s1)) return dp[s1];
        
        for(int i=1; i<s1.size(); i++){
            string prefix = s1.substr(0, i);
            string suffix = s1.substr(i);

            if(s.count(prefix) && (s.count(suffix) || dfs(suffix, dp, s))){
                dp[s1] = true;
                return dp[s1];
            }
        }
        dp[s1] = false;
        return dp[s1];
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
       unordered_set<string> s;
       for(string i: words){
            s.insert(i);
       }

       vector<string> ans;

       for(int i=0; i<words.size(); i++){
            unordered_map<string, bool> dp;
            s.erase(words[i]);
            if(dfs(words[i], dp, s)){
                ans.push_back(words[i]);
            }
            s.insert(words[i]);
       }
       return ans;
    }
};