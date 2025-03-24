class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i:arr){
            mp[i]++;
        }
        unordered_set<int> s;
        for(auto i:mp){
            if(s.find(i.second) != s.end()){
                return false;
            }
            s.insert(i.second);
        }
        return true;
    }
};