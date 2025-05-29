class Solution {
public:
    int minDistance(string word1, string word2) {
        // Base cases: if words are equal or one is empty
        if (word1 == word2) return 0;
        if (word2 == "") return word1.size();  // All deletions
        if (word1 == "") return word2.size();  // All insertions

        int s1 = word1.size();
        int s2 = word2.size();

        // dp[i][j] will hold the edit distance between word1[0...i-1] and word2[0...j-1]
        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));

        // Initialize first row and column: transforming to/from empty string
        for (int i = 0; i <= s1; i++) dp[i][0] = i; // deletions
        for (int j = 0; j <= s2; j++) dp[0][j] = j; // insertions

        // Fill DP table
        for (int i = 1; i <= s1; i++) {
            for (int j = 1; j <= s2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // Characters match, no edit needed
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Take the minimum of insert, delete, or replace
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],    // delete
                        dp[i][j - 1],    // insert
                        dp[i - 1][j - 1] // replace
                    });
                }
            }
        }

        // The result is the edit distance for full strings
        return dp[s1][s2];
    }
};
