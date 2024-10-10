class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())return {};
        vector<int> shash(26,0);
        vector<int> phash(26,0);
        vector<int>v;
        for(int i=0;i<p.size();i++){
            shash[s[i]-'a']++;
            phash[p[i]-'a']++;
        }
        if(shash==phash)v.push_back(0);
        for(int i=1;i<s.size()-p.size()+1;i++){
            shash[s[i+p.size()-1]-'a']++;
            shash[s[i-1]-'a']--;
            if(shash==phash)v.push_back(i);
        }
        return v;

    }
};