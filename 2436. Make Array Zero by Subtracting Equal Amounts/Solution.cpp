class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s;
        for(int i:nums){
            if(i == 0) continue;
            s.insert(i);
        }
        return s.size();
    }
};