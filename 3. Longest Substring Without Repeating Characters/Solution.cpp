class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> s1;
        int left = 0, right = 0, ans = 0;
        while(right < s.size()){

            while(!s1.empty() && s1.find(s[right]) != s1.end()){
                s1.erase(s[left]);
                left++;
            }
            ans = max(ans, right-left+1);
            s1.insert(s[right]);
            right++;
            
        }
        return ans;

    }
};