class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_set<char> s1;
        int left = 0, right = 0;
        while(right < s.size()){
            while(s1.find(s[right]) != s1.end()){
                s1.erase(s[left]);
                left += 1;
            }
            s1.insert(s[right]);
            ans = max(ans, right-left+1);
            right++;
        }

        return ans;
    }
};