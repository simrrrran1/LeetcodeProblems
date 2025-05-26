class Solution {
public:
    int minimumKeypresses(string s) {
        int n = s.size();
        int ans = 0;

        vector<int> v(26, 0);
        for(int i=0; i<n; i++){
            v[s[i] - 'a']++;
        }

        sort(v.begin(), v.end(), greater<int>());
        int count = 0;

        for(int i=0; i<26; i++){
            if(i % 9 == 0) count++;
            int freq = v[i];
            ans += (freq * count);
        }
        return ans;
    }
};