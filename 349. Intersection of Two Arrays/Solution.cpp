class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        unordered_set<int> s;
        for(int i:nums1){
            if(s.find(i) == s.end())
            s.insert(i);
        }

        for(int i: nums2){
            if(s.find(i) != s.end()){
                v.push_back(i);
                s.erase(i);
            }
        }

        return v;
    }
};