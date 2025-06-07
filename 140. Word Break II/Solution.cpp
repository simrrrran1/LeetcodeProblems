class Solution {
public:
    vector<string> dfs(int i, string& s, unordered_set<string>& wordDict, unordered_map<int, vector<string>>& memo) {
        if (memo.count(i)) return memo[i];

        vector<string> result;

        if (i == s.size()) {
            result.push_back(""); // Base case: empty string to signify valid end
            return result;
        }

        for (int j = i; j < s.size(); ++j) {
            string word = s.substr(i, j - i + 1);
            if (wordDict.find(word) != wordDict.end()) {
                vector<string> suffixes = dfs(j + 1, s, wordDict, memo);
                for (string suffix : suffixes) {
                    // If suffix is empty, don't add extra space
                    if (suffix.empty())
                        result.push_back(word);
                    else
                        result.push_back(word + " " + suffix);
                }
            }
        }

        return memo[i] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        return dfs(0, s, dict, memo);
    }
};
