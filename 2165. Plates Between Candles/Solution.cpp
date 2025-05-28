class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prefixCandles(n, 0);
        vector<int> suffixCandles(n, 0);
        vector<int> plate(n, 0);
        vector<int> ans(queries.size(), 0);
        
        prefixCandles[0] = s[0] == '|' ? 0 : -1;
        plate[0] = s[0] == '*' ? 1 : 0;

        for(int i=1; i<n; i++){
            prefixCandles[i] = s[i] == '|' ? i : prefixCandles[i-1];
            plate[i] = (s[i] == '*' ? 1 : 0 )+ plate[i-1];
        }

        suffixCandles[n-1] = s[n-1] == '|' ? n-1 : n;
        
        for(int i=n-2; i>=0; i--){
            suffixCandles[i] = s[i] == '|' ? i : suffixCandles[i+1];
        }

        for(int i=0; i<queries.size(); i++){
            int start = suffixCandles[queries[i][0]];
            int end = prefixCandles[queries[i][1]];
            ans[i] = start >= end ? 0 : plate[end] - plate[start];
        }

        return ans;

    }
};