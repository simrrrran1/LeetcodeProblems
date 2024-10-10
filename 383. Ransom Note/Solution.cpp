class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v(26,0);
        for(auto i:magazine){
            v[i-'a']++;
        }
        for(auto i:ransomNote){
            v[i-'a']--;
        }
        for(int i=0;i<26;i++){
            if(v[i]<0)return false;
        }
        return true;
    }
};