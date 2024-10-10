class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        //unordered_map<string, vector<string>>mp;
        map<vector<int>, vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            vector<int>v(26,0);
            for(auto c:strs[i]){
                v[c-'a']++;
            }
            // string key="";
            // for(int i=0;i<26;i++){
            //     if(v[i]>0){
            //         key+=string(v[i],i+'a');
            //     }
            // }
            //string key=strs[i];
            //sort(strs[i].begin(),strs[i].end());
            mp[v].push_back(strs[i]);
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};