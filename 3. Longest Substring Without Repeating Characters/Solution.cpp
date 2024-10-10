class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_set<char>s1;
        int left=0,right=0,ans=0;
        while(right<n){
            while(s1.find(s[right])!=s1.end()){
                s1.erase(s[left]);
                left++;
            }
            s1.insert(s[right]);
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};