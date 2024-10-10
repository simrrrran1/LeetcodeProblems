class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s1=s.size();
        int s2=t.size();
        if(s1>s2)return false;
        int j=0;
        for(int i=0;i<s2;i++){
            if(s[j]==t[i])j++;
        }
        return j==s1;
    }
};