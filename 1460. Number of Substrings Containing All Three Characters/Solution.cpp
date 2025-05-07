class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left = 0, right = 0;
        unordered_map<char,int> mp;
        int ans = 0;

        while(right < n){
            mp[s[right]]++;
            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
                ans += (n-right);
                mp[s[left]]--;
                left++;
            }
            right++;
        }
        return ans;
    }
};

//abcabc 