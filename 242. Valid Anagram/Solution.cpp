class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26, 0);
        if(s.size() != t.size()) return false;
        for(int i=0; i<s.size(); i++){
            v[s[i] - 'a']++;
            v[t[i] - 'a']--;
        }
        for(int i=0; i<26; i++){
            if(v[i] != 0) return false;
        }
        return true;
    }
};