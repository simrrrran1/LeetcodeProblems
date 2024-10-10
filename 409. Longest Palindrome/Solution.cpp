class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int ans=0;
        for(char i:s){
            mp[i]++;
            if(mp[i]%2==0)ans+=2;
        }
        for(auto i:mp){
            if(i.second%2==1){
                ans++;break;
            }
        }
        return ans;
    }
};