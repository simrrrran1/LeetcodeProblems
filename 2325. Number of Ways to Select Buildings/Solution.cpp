class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        vector<long long> prefix_0(n, 0);
        vector<long long> prefix_1(n, 0);
        vector<long long> suffix_0(n, 0);
        vector<long long> suffix_1(n, 0);

        for(int i=0; i<n; i++){
            if(i > 0){
                prefix_0[i] = prefix_0[i-1];
                prefix_1[i] = prefix_1[i-1];
            }
            if(s[i] == '0') prefix_0[i]++;
            if(s[i] == '1') prefix_1[i]++;
        }

        for(int i=n-1; i>=0; i--){
            if(i < n-1){
                suffix_0[i] = suffix_0[i+1];
                suffix_1[i] = suffix_1[i+1];
            }
            if(s[i] == '0') suffix_0[i]++;
            if(s[i] == '1') suffix_1[i]++;
        }

        long long ans = 0;
        for(int i=1; i<n-1; i++){
            if(s[i] == '0'){
                ans += prefix_1[i-1] * suffix_1[i+1];
            }else{
                ans += prefix_0[i-1] * suffix_0[i+1];
            }
        }

        return ans;
    }
};
