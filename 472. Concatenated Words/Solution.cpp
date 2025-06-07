class Solution {
public:
    // Recursive function to check if the current word (s1)
    // can be formed by concatenating words from the set.
    bool dfs(string s1, unordered_map<string, bool>& dp, unordered_set<string>& s) {
        // If the result is already memoized, return it
        if (dp.count(s1)) return dp[s1];

        // Try splitting the word at every possible position
        for (int i = 1; i < s1.size(); i++) {
            string prefix = s1.substr(0, i);     // First i characters
            string suffix = s1.substr(i);        // Remaining characters

            // Check if prefix is in the dictionary,
            // and the suffix is either directly in the set or can be formed by recursion
            if (s.count(prefix) && (s.count(suffix) || dfs(suffix, dp, s))) {
                dp[s1] = true; // Cache result
                return true;
            }
        }

        // If no valid split found, cache and return false
        dp[s1] = false;
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // Create a set for fast lookup of words
        unordered_set<string> s(words.begin(), words.end());

        vector<string> ans;

        // Iterate through each word to check if it is a concatenated word
        for (string word : words) {
            unordered_map<string, bool> dp;  // Memoization map for current word

            // Temporarily remove the current word to prevent using itself
            s.erase(word);

            // Perform DFS to check if the word can be formed
            if (dfs(word, dp, s)) {
                ans.push_back(word);  // If yes, add it to the result
            }

            // Add the word back to the set for future checks
            s.insert(word);
        }

        return ans;
    }
};
