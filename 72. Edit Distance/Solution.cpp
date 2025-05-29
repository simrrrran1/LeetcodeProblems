class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1 == word2) return 0;
        if(word2 == "") return word1.size();
        if(word1 == "") return word2.size();
        int s1 = word1.size();
        int s2 = word2.size();

        vector<vector<int>> dp(s1+1, vector<int>(s2+1, 0));

        for(int i=0; i<=s1; i++)dp[i][0] = i;
        for(int i=0; i<=s2; i++)dp[0][i] = i;
        

        for(int i=1; i<=s1; i++){
            for(int j=1; j<=s2; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                    continue;
                }
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])); 
            }
        }

        return dp[s1][s2];


    }
};